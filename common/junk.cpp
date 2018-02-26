
#define LM75_REG_TEMP (0x00) // Temperature Register
#define LM75_REG_CONF (0x01) // Configuration Register
#define LM75_ADDR     (0x90) // LM75 address
 
/* MCP9808 high accuracy temp sensor from adafruit (no address pins pulled up) */ 
#define MCP9808_REG_TEMP (0x05) // Temperature Register
#define MCP9808_REG_CONF (0x01) // Configuration Register
#define MCP9808_ADDR     (0x30) // MCP9808 base address 0x18<<1
 
I2C i2c(I2C_SDA, I2C_SCL);
 
 
Serial pc(SERIAL_TX, SERIAL_RX);
 
volatile char TempCelsiusDisplay[] = "+abc.d C";
volatile char TempCelsiusDisplay[] = "+abc.dd C";
 
int main()
{
 
    char data_write[2];
    char data_write[3];
    char data_read[2];
 
    /* Configure the Temperature sensor device STLM75:
    - Thermostat mode Interrupt
    int tempval;
    
    wait(3);
    pc.printf("PumpHouse mcp9808 test! March 2, 2015  1450\n\r");
    i2c.frequency(10000); // default is 100000
    
    /* Configure the Temperature sensor device MCP9808:
    - Thermostat mode Interrupt not used
    - Fault tolerance: 0
    */
    data_write[0] = LM75_REG_CONF;
    data_write[1] = 0x02;
    int status = i2c.write(LM75_ADDR, data_write, 2, 0);
    data_write[0] = MCP9808_REG_CONF;
    data_write[1] = 0x00;  // config msb
    data_write[2] = 0x00;  // config lsb
    int status = i2c.write(MCP9808_ADDR, data_write, 3, 0);
    if (status != 0) { // Error
        pc.printf("  error status = 0x%08x\r\n", status);
        while (1) {
            myled = !myled;
            wait(0.2);
        }
    }
 
    pc.printf("enter forever loop\r\n");
    while (1) {
        // Read temperature register
        data_write[0] = LM75_REG_TEMP;
        i2c.write(LM75_ADDR, data_write, 1, 1); // no stop
        i2c.read(LM75_ADDR, data_read, 2, 0);
        data_write[0] = MCP9808_REG_TEMP;
        i2c.write(MCP9808_ADDR, data_write, 1, 1); // no stop
        i2c.read(MCP9808_ADDR, data_read, 2, 0);


//Convert the temperature data
//First Check flag bits
UpperByte = UpperByte & 0x1F; //Clear flag bits
if ((UpperByte & 0x10) == 0x10){ //T A < 0°C
UpperByte = UpperByte & 0x0F;
//Clear SIGN
Temperature = 256 - (UpperByte * 16 + LowerByte / 16);
}else
//T A
3 0°C
Temperature = (UpperByte * 16 + LowerByte / 16);
//Temperature = Ambient Temperature (°C)



 
        // Calculate temperature value in Celcius
        int tempval = (int)((int)data_read[0] << 8) | data_read[1];
        tempval >>= 7;
        if (tempval <= 256) {
 // check Ta vs Tcrit
        if((data_read[0] & 0x80)  == 0x80) {
            pc.printf(" temp >= critical ");
        }
        if((data_read[0] & 0x40) == 0x40) {
            pc.printf("   temp > upper limit ");
        }
        if((data_read[0] & 0x20) == 0x20) {
            pc.printf(" temp < lower limit  ");
        }
        if(data_read[0] & 0xE0) {
            pc.printf("\r\n");   
            data_read[0] = data_read[0] & 0x1F;  // clear flag bits
        }
        if((data_read[0] & 0x10) == 0x10) { 
            data_read[0] = data_read[0] & 0x0F;
            TempCelsiusDisplay[0] = '-';
            tempval = 256 - (data_read[0] << 4) + (data_read[1] >> 4);
        } else {
            TempCelsiusDisplay[0] = '+';
        } else {
            TempCelsiusDisplay[0] = '-';
            tempval = 512 - tempval;
            tempval = (data_read[0] << 4) + (data_read[1] >> 4);
        }
 
        // Decimal part (0.5°C precision)
        if (tempval & 0x01) {
            TempCelsiusDisplay[5] = 0x05 + 0x30;
        // fractional part (0.25°C precision)
        if (data_read[1] & 0x08) {
            if(data_read[1] & 0x04) {
                TempCelsiusDisplay[5] = '7';
                TempCelsiusDisplay[6] = '5';
            } else {
                TempCelsiusDisplay[5] = '5';
                TempCelsiusDisplay[6] = '0';
            }
        } else {
            TempCelsiusDisplay[5] = 0x00 + 0x30;
            if(data_read[1] & 0x04) {
                TempCelsiusDisplay[5] = '2';
                TempCelsiusDisplay[6] = '5';
            }else{
                TempCelsiusDisplay[5] = '0';
                TempCelsiusDisplay[6] = '0';
            }
        }
 
        // Integer part
        tempval >>= 1;
        TempCelsiusDisplay[1] = (tempval / 100) + 0x30;
        TempCelsiusDisplay[2] = ((tempval % 100) / 10) + 0x30;
        TempCelsiusDisplay[3] = ((tempval % 100) % 10) + 0x30;
 
        // Display result
        pc.printf("temp = %s\n", TempCelsiusDisplay);
        pc.printf("temp = %s\r\n", TempCelsiusDisplay);
        myled = !myled;
        wait(1.0);
    }

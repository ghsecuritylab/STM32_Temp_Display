#include "temp_sense.h"
#include "stm32f1xx_nucleo.h"
#include "stm32f1xx_hal_rcc.h"
//#define REG_CHIP_ID 0x00

namespace nucleo_f103rb {
I2C_HandleTypeDef I2cHandle;
HAL_StatusTypeDef status = HAL_OK;
uint8_t register_pointer;
uint16_t register_value;


Temp_Sense::Temp_Sense() noexcept
{
  BSP_i2c_init(I2cHandle);
  Init_Temp_Sensor();
}

Temp_Sense::~Temp_Sense() noexcept
{

}

/*
	Reads temp data from sensor and performs a data to temperature conversion.

*/

void Temp_Sense::Read_Temp_Register(int *Temperature) noexcept
{
  uint8_t data[2];
  data[0] = MCP9808_REG_TEMP;

  // set up to read temp data from sensor
  HAL_I2C_Master_Transmit(&I2cHandle, MCP9808_ADDR, data, 1, TIMEOUT);  

  if(status != HAL_OK)
  {
	// Handle_Error();
  }

  // receive the 2 x 8bit data into the receive buffer
  HAL_I2C_Master_Receive(&I2cHandle, MCP9808_ADDR, data, 2, TIMEOUT);

  if(status != HAL_OK)
  {
	// Handle_Error();
  }

  // Convert the sensor data to Temperature (Deg C)

  data[1] = data[1] & 0x1F; // Clear flag bits

  if ((data[1] & 0x10) == 0x10) // TA < 0°C
  { 
	data[1] = data[1] & 0x0F;
	// Clear SIGN
	*Temperature = 256 - (data[1] * 16 + data[0] / 16);
  }
  else  // TA > 0°C
	*Temperature = (data[1] * 16+data[0] / 16);

}


void Temp_Sense::write_register() noexcept
{
    HAL_StatusTypeDef status = HAL_OK;

	status = HAL_I2C_Mem_Write(&I2cHandle, MCP9808_ADDR, (uint16_t)register_pointer, \
				I2C_MEMADD_SIZE_8BIT, (uint8_t*)(&register_value), NUM_BYTES, TIMEOUT); 

    /* Check the communication status */
    if(status != HAL_OK)
    {
        // Handle_Error();
    }
}


/*
Initialize Temp sensor
*/

void Temp_Sense::Init_Temp_Sensor() noexcept
{

  uint8_t data[3];

  data[0] = LM75_REG_CONF;
  data[1] = 0x02;
  status = HAL_I2C_Master_Transmit(&I2cHandle, MCP9808_ADDR, data, NUM_BYTES, TIMEOUT); 
  
  if(status != HAL_OK)
  {
    // Handle_Error();
  }

  data[0] = MCP9808_REG_CONF;
  data[1] = 0x00;  // config msb
  data[2] = 0x00;  // config lsb
    
  status = HAL_I2C_Master_Transmit(&I2cHandle, MCP9808_ADDR, data, NUM_BYTES, TIMEOUT); 
  
  if(status != HAL_OK)
  {
    // Handle_Error();
  }

}


} // namespace nucleo_f103rb



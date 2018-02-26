#include "display_seg.h"
#include "stm32f1xx_nucleo.h"
#include "stm32f1xx_hal_rcc.h"
#include "stdlib.h"
I2C_HandleTypeDef I2cHandle;
HAL_StatusTypeDef status = HAL_OK;


namespace nucleo_f103rb {

Display_Seg::Display_Seg() noexcept
{
   BSP_i2c_init(I2cHandle);
}

Display_Seg::~Display_Seg() noexcept 
{

}

// function to take an integer value and convert it to ascii


void Display_Seg::display_val(unsigned char DigitSelect,int * Temperature) noexcept
{
  uint8_t data[2];	
  data[0]=DigitSelect;
  char temp_data[3];	
  char *char_ptr = temp_data;
  int intval = *Temperature;
  char Character;

  // Convert the Temperature data from an integer value to an array of car to be displayed.
  itoa(intval,char_ptr,2);

// Send the characters to the display one at a time

for (int i=0; i<=2; i++)
{
  Character = *char_ptr+i;
  if (Character > (unsigned char)'z')
    data[1] = 0x00; // Unsupported characters are set to zero
  else
    data[1] = seven_seg_digits_decode_gfedcba[Character - '/'];

  status = HAL_I2C_Master_Transmit(&I2cHandle, SEVEN_SEG_I2C_ADDRESS, data, NUM_BYTES, TIMEOUT);  
  /* Check the communication status */
  if(status != HAL_OK) {		
	// Handle_Error();
   }
 }

}

} // namespace nucleo_f103rb



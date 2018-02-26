#ifndef TOKEN_NUCLEO_F103RB_TEMP_H
#define TOKEN_NUCLEO_F103RB_TEMP_H
#include "stm32f1xx_nucleo.h"
#include "stm32f1xx_hal_rcc.h"
#include "common/temp_sense.h"
#define NUM_BYTES 2
#define TIMEOUT 100
#define LM75_REG_TEMP (0x00) // Temperature Register
#define LM75_REG_CONF (0x01) // Configuration Register
#define LM75_ADDR     (0x90) // LM75 address
#define MCP9808_REG_TEMP (0x05) // Temperature Register
#define MCP9808_REG_CONF (0x01) // Configuration Register
#define MCP9808_ADDR     (0x30) // MCP9808 base address 0x18<<1

namespace nucleo_f103rb {

class Temp_Sense: public common::Temp_Sense {
public:
    Temp_Sense() noexcept;
    virtual ~Temp_Sense() noexcept;
    Temp_Sense(const Temp_Sense &) = default;
    Temp_Sense(Temp_Sense &&) = default;
    Temp_Sense & operator=(const Temp_Sense &) = default;
    Temp_Sense & operator=(Temp_Sense &&) = default;

   	void Read_Temp_Register(int *) noexcept override;
	void write_register() noexcept override;
	void Init_Temp_Sensor() noexcept override;
};

} // namespace nucleo_f103rb

#endif

#include "led.h"
#include "stm32f1xx_nucleo.h"

namespace nucleo_f103rb {

Led::Led() noexcept
{
    BSP_LED_Init(LED2);
}

Led::~Led() noexcept
{
    BSP_LED_DeInit(LED2);
}

void Led::on() noexcept
{
    BSP_LED_On(LED2);
}

void Led::off() noexcept
{
    BSP_LED_Off(LED2);
}

void Led::toggle() noexcept
{
    BSP_LED_Toggle(LED2);
}

} // namespace nucleo_f103rb

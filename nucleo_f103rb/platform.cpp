#include "platform.h"
#include "stm32f1xx_hal.h"

using nucleo_f103rb::Platform;

void Platform::delay(std::chrono::milliseconds dt) const
{
    HAL_Delay(dt.count());
}

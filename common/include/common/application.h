#ifndef TOKEN_COMMON_APPLICATION_H
#define TOKEN_COMMON_APPLICATION_H

#include "common/led.h"
#include "common/temp_sense.h"
#include "common/display_seg.h"
#include "common/platform.h"

namespace common {

class Application {
public:
    Application(Platform * pPlatform, Led * pLed, Temp_Sense * pTemp, Display_Seg * pDisp);
    ~Application() = default;
    Application(const Application &) = default;
    Application(Application &&) = default;
    Application & operator=(const Application &) = default;
    Application & operator=(Application &&) = default;

    void run_cycle();

private:
    Platform * mpPlatform;
    Led * mpLed;
    Temp_Sense * mpTemp;
	Display_Seg * mpDisp;
};

} // namespace common

#endif

#ifndef TOKEN_NUCLEO_F103RB_PLATFORM_H
#define TOKEN_NUCLEO_F103RB_PLATFORM_H

#include "common/platform.h"

namespace nucleo_f103rb {

class Platform : public common::Platform {
public:
    Platform() = default;
    virtual ~Platform() = default;
    Platform(const Platform &) = default;
    Platform(Platform &&) = default;
    Platform & operator=(const Platform &) = default;
    Platform & operator=(Platform &&) = default;

    void delay(std::chrono::milliseconds dt) const override;
};

} // namespace nucleo_f103rb

#endif

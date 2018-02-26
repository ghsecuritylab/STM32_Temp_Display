#ifndef TOKEN_COMMON_PLATFORM_H
#define TOKEN_COMMON_PLATFORM_H

#include <chrono>

namespace common {

class Platform {
public:
    Platform() = default;
    virtual ~Platform() = default;
    Platform(const Platform &) = default;
    Platform(Platform &&) = default;
    Platform & operator=(const Platform &) = default;
    Platform & operator=(Platform &&) = default;

    virtual void delay(std::chrono::milliseconds dt) const = 0;
};

} // namespace common

#endif

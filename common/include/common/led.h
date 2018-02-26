#ifndef TOKEN_COMMON_LED_H
#define TOKEN_COMMON_LED_H

namespace common {

class Led {
public:
    Led() = default;
    virtual ~Led() = default;
    Led(const Led &) = default;
    Led(Led &&) = default;
    Led & operator=(const Led &) = default;
    Led & operator=(Led &&) = default;

    virtual void on() noexcept = 0;
    virtual void off() noexcept = 0;
    virtual void toggle() noexcept = 0;
};

} // namespace common

#endif

#ifndef TOKEN_NUCLEO_F103RB_LED_H
#define TOKEN_NUCLEO_F103RB_LED_H

#include "common/led.h"

namespace nucleo_f103rb {

class Led : public common::Led {
public:
    Led() noexcept;
    virtual ~Led() noexcept;
    Led(const Led &) = default;
    Led(Led &&) = default;
    Led & operator=(const Led &) = default;
    Led & operator=(Led &&) = default;

    void on() noexcept override;
    void off() noexcept override;
    void toggle() noexcept override;
};

} // namespace nucleo_f103rb

#endif

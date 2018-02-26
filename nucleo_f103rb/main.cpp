#include "common/application.h"
#include "led.h"
#include "temp_sense.h"
#include "display_seg.h"
#include "platform.h"
#include "st_init.h"
#include <cstdint>
#include <cstdlib>


// XXX: Special hack to reduce the amount of C++ library code that gets pulled
// in. Not sure this makes much of a difference when using the nano specs.
namespace __gnu_cxx {

void __verbose_terminate_handler()
{
    std::abort();
}
} // namespace __gnu_cxx

int main()
{
    st_init();  // init Hal and system clock
    nucleo_f103rb::Led led{};
    nucleo_f103rb::Platform platform{};
    nucleo_f103rb::Temp_Sense temp_sense{};
    nucleo_f103rb::Display_Seg disp{};
    common::Application app{&platform, &led, &temp_sense, &disp};

    for (;;) {
        app.run_cycle();
    }

    return 0;
}

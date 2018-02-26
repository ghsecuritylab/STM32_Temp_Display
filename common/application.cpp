#include "common/application.h"
#include <chrono>
#include <gsl/gsl>

using namespace std::chrono_literals;
using common::Application;
uint8_t reg_ptr = 0x0C;
uint8_t Seg,Chr;
int read_buff[1];
int *p1 = read_buff;
uint16_t register_value;


Application::Application(common::Platform * pPlatform, common::Led * pLed, common::Temp_Sense * pTemp, common::Display_Seg * pDisp)
    : mpPlatform{pPlatform}
    , mpLed{pLed}
	, mpTemp{pTemp}
    , mpDisp{pDisp}
{
}

void Application::run_cycle()
{
    mpTemp->Read_Temp_Register(p1); // read sensor format the value from the temp sensor
	mpDisp->display_val(Seg,p1);  // display value
    mpLed->toggle();
    mpPlatform->delay(200ms);

}



# Add the HAL. The reason it's not listed in external/CMakeLists.txt
# is that the ST driver relies on a configuration file provided by the
# application.
set(BASE "${CMAKE_CURRENT_SOURCE_DIR}/../external/STM32Cube_FW_F1_V1.6.0/Drivers/STM32F1xx_HAL_Driver")
set(SRC "${BASE}/Src")

add_library(stm32cube
  ${SRC}/stm32f1xx_hal.c
  ${SRC}/stm32f1xx_hal_adc.c
  ${SRC}/stm32f1xx_hal_adc_ex.c
  ${SRC}/stm32f1xx_hal_can.c
  ${SRC}/stm32f1xx_hal_cec.c
  ${SRC}/stm32f1xx_hal_cortex.c
  ${SRC}/stm32f1xx_hal_crc.c
  ${SRC}/stm32f1xx_hal_dac.c
  ${SRC}/stm32f1xx_hal_dac_ex.c
  ${SRC}/stm32f1xx_hal_dma.c
  ${SRC}/stm32f1xx_hal_eth.c
  ${SRC}/stm32f1xx_hal_flash.c
  ${SRC}/stm32f1xx_hal_flash_ex.c
  ${SRC}/stm32f1xx_hal_gpio.c
  ${SRC}/stm32f1xx_hal_gpio_ex.c
  ${SRC}/stm32f1xx_hal_hcd.c
  ${SRC}/stm32f1xx_hal_i2c.c
  ${SRC}/stm32f1xx_hal_i2s.c
  ${SRC}/stm32f1xx_hal_irda.c
  ${SRC}/stm32f1xx_hal_iwdg.c
  ${SRC}/stm32f1xx_hal_mmc.c
  ${SRC}/stm32f1xx_hal_msp_template.c
  ${SRC}/stm32f1xx_hal_nand.c
  ${SRC}/stm32f1xx_hal_nor.c
  ${SRC}/stm32f1xx_hal_pccard.c
  ${SRC}/stm32f1xx_hal_pcd.c
  ${SRC}/stm32f1xx_hal_pcd_ex.c
  ${SRC}/stm32f1xx_hal_pwr.c
  ${SRC}/stm32f1xx_hal_rcc.c
  ${SRC}/stm32f1xx_hal_rcc_ex.c
  ${SRC}/stm32f1xx_hal_rtc.c
  ${SRC}/stm32f1xx_hal_rtc_ex.c
  ${SRC}/stm32f1xx_hal_sd.c
  ${SRC}/stm32f1xx_hal_smartcard.c
  ${SRC}/stm32f1xx_hal_spi.c
  ${SRC}/stm32f1xx_hal_spi_ex.c
  ${SRC}/stm32f1xx_hal_sram.c
  ${SRC}/stm32f1xx_hal_tim.c
  ${SRC}/stm32f1xx_hal_tim_ex.c
  ${SRC}/stm32f1xx_hal_timebase_rtc_alarm_template.c
  ${SRC}/stm32f1xx_hal_timebase_tim_template.c
  ${SRC}/stm32f1xx_hal_uart.c
  ${SRC}/stm32f1xx_hal_usart.c
  ${SRC}/stm32f1xx_hal_wwdg.c
  ${SRC}/stm32f1xx_ll_adc.c
  ${SRC}/stm32f1xx_ll_crc.c
  ${SRC}/stm32f1xx_ll_dac.c
  ${SRC}/stm32f1xx_ll_dma.c
  ${SRC}/stm32f1xx_ll_exti.c
  ${SRC}/stm32f1xx_ll_fsmc.c
  ${SRC}/stm32f1xx_ll_gpio.c
  ${SRC}/stm32f1xx_ll_i2c.c
  ${SRC}/stm32f1xx_ll_pwr.c
  ${SRC}/stm32f1xx_ll_rcc.c
  ${SRC}/stm32f1xx_ll_rtc.c
  ${SRC}/stm32f1xx_ll_sdmmc.c
  ${SRC}/stm32f1xx_ll_spi.c
  ${SRC}/stm32f1xx_ll_tim.c
  ${SRC}/stm32f1xx_ll_usart.c
  ${SRC}/stm32f1xx_ll_usb.c
  ${SRC}/stm32f1xx_ll_utils.c
  )

add_library(st::cube ALIAS stm32cube)
target_include_directories(stm32cube PUBLIC "${BASE}/Inc" "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(stm32cube st::cmsis)

# As much code as possible should not be in this module.  The only
# code in here should code for specifically targetting the STM32
# Nucleo-F103RB.
add_executable(nucleo_f103rb.elf

  # From the ST LL template, modified from being "main"
  st_init.c
  startup_stm32f103xb.s
  stm32f1xx_hal_msp.c
  stm32f1xx_it.c
  system_stm32f1xx.c
  stm32f1xx_ll_i2c.c

  # Our own files
  main.cpp
  led.cpp
  temp_sense.cpp	
  platform.cpp
  display_seg.cpp
  )

target_link_libraries(nucleo_f103rb.elf
  st::cube
  st::cmsis
  st::nucleo_bsp
  token::common
  )

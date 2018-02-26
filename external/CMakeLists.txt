# Add a header-only library for the Catch2 test framework
# https://github.com/catchorg/Catch2
add_library(catch INTERFACE)
add_library(catch::catch ALIAS catch)
target_include_directories(catch
  INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/Catch2/single_include")

# Make a header-only library for the GSL
# https://github.com/Microsoft/GSL
#
# "GSL" stands for "Guidelines Support Library"; the guidelines being
# referred to are the "C++ Core Guidelines." You can read the
# guidelines on the ISO C++ github page:
# https://github.com/isocpp/CppCoreGuidelines.  Briefly, the C++ Core
# Guidelines are a collection of best practices, techniques,
# suggestions and guidelines to help developers use modern C++
# effectively.  The goal is to prescribe a subset of C++ that is
# generally applicable, powerful, and low-cost, while at the same time
# being safer, easier to use correctly and harder to use incorrectly.
add_library(gsl INTERFACE)
add_library(gsl::gsl ALIAS gsl)
target_include_directories(gsl
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/GSL/include"
  )
# target_compile_features(gsl INTERFACE cxx_)
  

# Reasonable people may disagree, but we believe `Expects(cond)` and
# `Ensures(cond)` should behave as `assert()` would since a contract
# violation indicates a violated assumption made by programmers.  We
# take the stance that programmers should prevent contract violations
# and not rely on pre- and post-condition checks for appropriate error
# handling.  On the target, contract violations will result in
# invoking std::terminate.
#
# Throwing on contract violations is left on for development machine
# builds so that contract violation cases can be unit tested.
if (CMAKE_CROSSCOMPILING)
  target_compile_definitions(gsl
    INTERFACE
      GSL_TERMINATE_ON_CONTRACT_VIOLATION)
else()
  target_compile_definitions(gsl
    INTERFACE
      GSL_THROW_ON_CONTRACT_VIOLATION)
endif()

# Make a header-only library for the FakeIt mock framework
# https://github.com/eranpeer/FakeIt
#
# FakeIt is a mocking framework useful for dynamically creating and
# configuring test doubles.  We try to use it sparingly, preferring to
# roll our own ad-hoc test doubles as necessary.  These take about as
# much effort to create as framework-generated mocks and they tend to
# encourage a more readable and direct style of verifying behavior
# (reasonable people may disagree, but our experience is that
# framework-generated mocks make it too easy to write brittle tests).
add_library(fakeit INTERFACE)
add_library(fakeit::fakeit ALIAS fakeit)
target_include_directories(fakeit
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/FakeIt/single_header/catch/")


# TODO: Add a more general check for the target instead of just
# checking whether we're cross compiling
if (CMAKE_CROSSCOMPILING)
  set(CUBE "${CMAKE_CURRENT_SOURCE_DIR}/STM32Cube_FW_F1_V1.6.0")
  set(CMSIS "${CUBE}/Drivers/CMSIS")

  add_library(cmsis INTERFACE)
  add_library(st::cmsis ALIAS cmsis)
  target_include_directories(cmsis
    INTERFACE
      ${CMSIS}/Include
      ${CMSIS}/Device/ST/STM32F1xx/Include
    )
  target_compile_definitions(cmsis
    INTERFACE
      STM32F103xB=1
    )

add_library(nucleobsp ${CUBE}/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c)
add_library(st::nucleo_bsp ALIAS nucleobsp)
target_include_directories(nucleobsp PUBLIC ${CUBE}/Drivers/BSP/STM32F1xx_Nucleo)
target_link_libraries(nucleobsp st::cmsis st::cube)

endif()

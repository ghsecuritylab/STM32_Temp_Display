add_library(common
  application.cpp)
add_library(token::common ALIAS common)
target_include_directories(common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(common PUBLIC cxx_defaulted_functions cxx_raw_string_literals)
set_target_properties(common
  PROPERTIES
  CXX_STANDARD 14
  )
target_link_libraries(common gsl::gsl)

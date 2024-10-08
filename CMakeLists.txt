cmake_minimum_required(VERSION 3.18.4)
project(leds)

set(CMAKE_CXX_STANDARD 20)

add_library(gpiodcxx STATIC IMPORTED)
set_target_properties(gpiodcxx PROPERTIES
        IMPORTED_LOCATION "/home/pi/libgpiod-install/lib/libgpiodcxx.a"
        INTERFACE_INCLUDE_DIRECTORIES "/home/pi/libgpiod-install/include"
)

add_library(gpiod STATIC IMPORTED)
set_target_properties(gpiod PROPERTIES
        IMPORTED_LOCATION "/home/pi/libgpiod-install/lib/libgpiod.a"
)

add_executable(leds main.cpp
        LedDigit.cpp
        LedDigit.h
        LedTime.cpp
        LedTime.h
        GpioMapper.cpp
        GpioMapper.h)
target_link_libraries(leds gpiodcxx gpiod)
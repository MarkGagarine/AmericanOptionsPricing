cmake_minimum_required(VERSION 3.20)
project(AmericanOptionsPricing)

set(CMAKE_CXX_STANDARD 14)

add_executable(AmericanOptionsPricing main.cpp Stock.cpp Stock.h Option.cpp Option.h Price_American_PSOR.cpp Price_American_PSOR.h)


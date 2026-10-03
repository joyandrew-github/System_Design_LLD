cmake_minimum_required(VERSION 3.20)

project(food_delivery_lld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    food_delivery_lld
    main.cpp
    src/model/User.cpp
    src/model/Customer.cpp
    src/model/Address.cpp
    src/model/Restaurant.cpp
)
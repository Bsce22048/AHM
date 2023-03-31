cmake_minimum_required(VERSION 3.24)
project(oop_semester2)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_semester2
        main.cpp Cabinet.h Medicine.h Prize.h Pharmacy.h Medicine.cpp Prize.cpp Date.h Cabinet.cpp Pharmacy.cpp)

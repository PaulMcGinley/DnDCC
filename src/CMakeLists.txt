cmake_minimum_required(VERSION 3.29)
project(DnDCC)

set(CMAKE_CXX_STANDARD 20)

add_executable(DnDCC main.cpp
        Interfaces/IAbilities.hpp
        Models/Character.cpp
        Models/Character.hpp
)

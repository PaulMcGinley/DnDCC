cmake_minimum_required(VERSION 3.20)
project(DnDCM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable C++20 modules
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-fmodules-ts)
endif()

add_executable(DnDCM main.cpp
        Structures/stat.h
        Structures/abilities.h
        Enumerators/chacter_class.h
        Modules/Player/player.cpp
        Modules/Player/player.h
        Structures/energy.h
        Utilities/utility.h
        Utilities/utility.cpp
        Singletons/DiceRoller.cpp
        Singletons/DiceRoller.h
        Utilities/console_formatter.h
)
cmake_minimum_required(VERSION 3.30)
project(Z80_Emulator)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE
        src/main.cpp
        src/Z80Emulator.cpp
        src/Z80Registers.cpp
        src/Z80Memory.cpp
        src/Instructions.cpp
)

set(HEADERS
        include/Z80Emulator.h
        include/Z80Registers.h
        include/Z80Memory.h
        include/Instructions.h
)


add_executable(Z80_Emulator ${SOURCE} ${HEADERS})

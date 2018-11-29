cmake_minimum_required(VERSION 3.12)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__ src/main.cpp src/Ant.cpp src/Ant.h src/Coord.cpp src/Coord.h src/Worker.cpp src/Worker.h src/Grid.h src/Grid.cpp src/Cell.h src/Cell.cpp src/BadAnt.cpp src/BadAnt.h src/Soldier.cpp src/Soldier.h)
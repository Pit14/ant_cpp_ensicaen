cmake_minimum_required(VERSION 3.12)
project(C__)

set(CMAKE_CXX_STANDARD 14)
set(SFML_ROOT "D:/SFML")
add_executable(C__ src/main.cpp src/Ants/Ant.cpp src/Ants/Ant.h src/Map/Coord.cpp src/Map/Coord.h src/Ants/Worker.cpp src/Ants/Worker.h src/Map/Grid.h src/Map/Grid.cpp src/Map/Cell.h src/Map/Cell.cpp src/Ants/BadAnt.cpp src/Ants/BadAnt.h src/Ants/Soldier.cpp src/Ants/Soldier.h src/Ants/Queen.cpp src/Ants/Queen.h src/Ants/Scout.cpp src/Ants/Scout.h src/define.h)
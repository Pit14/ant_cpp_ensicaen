cmake_minimum_required(VERSION 3.12)
project(C__)
set(PROJECT_NAME mini_projet_cpp)
set(CMAKE_CXX_STANDARD 14)
set(SFML_ROOT D:/Lib/SFML)

add_executable(C__ src/main.cpp src/Ants/Ant.cpp src/Ants/Ant.h src/Map/Coord.cpp src/Map/Coord.h src/Ants/Worker.cpp src/Ants/Worker.h src/Map/Grid.h src/Map/Grid.cpp src/Map/Cell.h src/Map/Cell.cpp src/Ants/BadAnt.cpp src/Ants/BadAnt.h src/Ants/Soldier.cpp src/Ants/Soldier.h src/Ants/Queen.cpp src/Ants/Queen.h src/Ants/Scout.cpp src/Ants/Scout.h src/define.h)


set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()
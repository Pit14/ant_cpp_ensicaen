cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME Project)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)
set(SFML_ROOT D:/Lib/SFML)

add_executable(Project src/main.cpp src/Ants/Ant.cpp include/Ants/Ant.h src/Map/Coord.cpp include/Map/Coord.h src/Ants/Worker.cpp include/Ants/Worker.h include/Map/Grid.h src/Map/Grid.cpp include/Map/Cell.h src/Map/Cell.cpp src/Ants/BadAnt.cpp include/Ants/BadAnt.h src/Ants/Soldier.cpp include/Ants/Soldier.h src/Ants/Queen.cpp include/Ants/Queen.h src/Ants/Scout.cpp include/Ants/Scout.h src/define.h src/Ants/Nest.cpp include/Ants/Nest.h)


set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.4 REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()
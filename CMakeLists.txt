cmake_minimum_required(VERSION 3.25)
project(project_1 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/Headers
    ${CMAKE_SOURCE_DIR}/Headers/ForFactory
)

#Добавили исполняемый фал
add_executable (my_proj
    main.cpp
    src/Transport.cpp
    src/Car.cpp
    src/Boat.cpp
    src/Helicopter.cpp
    src/Spaceship.cpp
    src/WorkWithFile.cpp
    src/Table.cpp
    src/ForFactory/CreateCar.cpp
    src/ForFactory/CreateBoat.cpp
    src/ForFactory/CreateHelicopter.cpp
    src/ForFactory/CreateSpaceship.cpp 
    )
    
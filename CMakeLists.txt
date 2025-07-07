#минимальная версия cmake
cmake_minimum_required(VERSION 3.25)
#выбрали имя проекта, версию и язык
project(project_1 VERSION 1.0 LANGUAGES CXX)

#установили минимальный стандарт C++
set(CMAKE_CXX_STANDARD 20)
#обязательно 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#добавили исполняемый файл
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
    src/ForStrategy/Context.cpp
    src/ForStrategy/Strategy.cpp
    src/ForStrategy/StrategyId.cpp
    src/ForStrategy/StrategyType.cpp
    src/ForStrategy/StrategyBrand.cpp
    src/ForStrategy/StrategyModel.cpp
    src/ForStrategy/StrategyYear.cpp
    src/ForStrategy/StrategyWeight.cpp
    src/ForStrategy/StrategyOwners.cpp
    src/ForStrategy/StrategyMileage.cpp
    src/ForStrategy/StrategyLengthBoat.cpp
    src/ForStrategy/StrategyWidthBoat.cpp
    src/ForStrategy/StrategyCapacity.cpp
    src/ForStrategy/StrategyEnginePower.cpp
    src/ForStrategy/StrategyMaxSpeed.cpp
    src/ForStrategy/StrategyHyperjumpRange.cpp
)

#подключаем директории с заголовки 
target_include_directories(my_proj PRIVATE
    ${CMAKE_SOURCE_DIR}/Headers
    ${CMAKE_SOURCE_DIR}/Headers/ForFactory
    ${CMAKE_SOURCE_DIR}/Headers/ForStrategy
)
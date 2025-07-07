#include "CreateCar.h"

#include "Car.h"

//реализуем фабричного метода
std::unique_ptr<Transport> CreateCar::create(
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans,
    double weightTrans) const 
{
        //возвращаем указатель на базу с дочерним объектом
        return std::make_unique<Car>(brandTrans, modelTrans, yearTrans, weightTrans);
}
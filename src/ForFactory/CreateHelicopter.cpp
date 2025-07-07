#include "CreateHelicopter.h"

#include "Helicopter.h"

//реализуем фабричного метода
std::unique_ptr<Transport> CreateHelicopter::create(
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans,
    double weightTrans) const 
{
        //возвращаем указатель на базу с дочерним объектом
        return std::make_unique<Helicopter>(brandTrans, modelTrans, yearTrans, weightTrans);
}
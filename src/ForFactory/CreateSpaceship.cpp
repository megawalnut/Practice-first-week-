#include "CreateSpaceship.h"

#include "Spaceship.h"

//реализуем фабричного метода
std::unique_ptr<Transport> CreateSpaceship::create(
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans,
    double weightTrans) const 
{
        //возвращаем указатель на базу с дочерним объектом
        return std::make_unique<Spaceship>(brandTrans, modelTrans, yearTrans, weightTrans);
}
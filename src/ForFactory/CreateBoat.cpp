#include "CreateBoat.h"

#include "Boat.h"

//реализуем фабричного метода
std::unique_ptr<Transport> CreateBoat::create(
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans, 
    double weightTrans) const 
{
        //возвращаем указатель на базу с дочерним объектом
        return std::make_unique<Boat>(brandTrans, modelTrans, yearTrans, weightTrans);
}
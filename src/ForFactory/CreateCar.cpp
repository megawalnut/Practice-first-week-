#include "CreateCar.h"

#include "Car.h"

std::unique_ptr<Transport> CreateCar::create(
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans,
    double weightTrans) const {
        return std::make_unique<Car>(brandTrans, modelTrans, yearTrans, weightTrans);
    }
#include "CreateHelicopter.h"

#include "Helicopter.h"

std::unique_ptr<Transport> CreateHelicopter::create(
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans,
    double weightTrans) const {
        return std::make_unique<Helicopter>(brandTrans, modelTrans, yearTrans, weightTrans);
    }

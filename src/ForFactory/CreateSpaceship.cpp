#include "CreateSpaceship.h"

#include "Spaceship.h"

std::unique_ptr<Transport> CreateSpaceship::create(
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans,
    double weightTrans) const {
        return std::make_unique<Spaceship>(brandTrans, modelTrans, yearTrans, weightTrans);
}
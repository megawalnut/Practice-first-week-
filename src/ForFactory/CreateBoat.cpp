#include "CreateBoat.h"

#include "Boat.h"

std::unique_ptr<Transport> CreateBoat::create(
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans, 
    double weightTrans) const {
        return std::make_unique<Boat>(brandTrans, modelTrans, yearTrans, weightTrans);
}

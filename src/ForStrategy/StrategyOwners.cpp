#include "StrategyOwners.h"
#include "Car.h"

#include <algorithm>
#include <iostream>

void StrategyOwners::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Car* first = dynamic_cast<Car*>(a.get());
        Car* second = dynamic_cast<Car*>(b.get());
        if (first && second)
            return first->get_owners() > second->get_owners(); 
        else if (first && !second)
            return true;
        else if (!first && second)
            return false;
        else
            return false;
    });
}

FindType StrategyOwners::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        Car* car = dynamic_cast<Car*>(it.get());
        if (car && car->get_owners() == atoi(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyOwners::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Car* car = dynamic_cast<Car*>(otherVehicles.get());
    if (car)
        car->set_owners(atoi(editClassField.c_str()));
}
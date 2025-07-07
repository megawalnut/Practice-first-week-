#include "StrategyMileage.h"
#include "Car.h"

#include <algorithm>
#include <iostream>

void StrategyMileage::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Car* first = dynamic_cast<Car*>(a.get());
        Car* second = dynamic_cast<Car*>(b.get());
        if (first && second)
            return first->get_mileage() > second->get_mileage(); 
        else if (first && !second)
            return true;
        else if (!first && second)
            return false;
        else
            return false;
    });
}

FindType StrategyMileage::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        Car* car = dynamic_cast<Car*>(it.get());
        if (car && car->get_mileage() == atof(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyMileage::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Car* car = dynamic_cast<Car*>(otherVehicles.get());
    if (car)
        car->set_mileage(atof(editClassField.c_str()));
}
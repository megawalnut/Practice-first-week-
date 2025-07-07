#include "StrategyBrand.h"

#include <algorithm>
#include <iostream>

void StrategyBrand::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
            { return a->get_brand() > b->get_brand(); });
}

FindType StrategyBrand::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        if (it->get_brand() == edit)
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyBrand::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    otherVehicles->set_brand(editClassField);
}
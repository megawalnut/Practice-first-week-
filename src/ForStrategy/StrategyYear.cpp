#include "StrategyYear.h"

#include <algorithm>
#include <iostream>

void StrategyYear::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
            { return a->get_year() > b->get_year(); });
}

FindType StrategyYear::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        if (it->get_year() == atoi(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyYear::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    otherVehicles->set_year(std::atoi(editClassField.c_str()));
}
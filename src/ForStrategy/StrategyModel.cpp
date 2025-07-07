#include "StrategyModel.h"

#include <algorithm>
#include <iostream>

void StrategyModel::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
            { return a->get_model() > b->get_model(); });
}

FindType StrategyModel::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        if (it->get_model() == edit)
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyModel::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    otherVehicles->set_model(editClassField);
}
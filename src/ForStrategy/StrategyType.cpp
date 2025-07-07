#include "StrategyType.h"

#include <algorithm>
#include <iostream>

void StrategyType::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
            { return a->get_type() > b->get_type(); });
}

FindType StrategyType::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        if (it->get_type() == edit)
            vec.push_back(it.get());
    }
    return vec;
}

void StrategyType::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    std::cout << "Редактирование типу недоступно" << std::endl;
}
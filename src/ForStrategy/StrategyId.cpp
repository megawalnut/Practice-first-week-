#include "StrategyId.h"

#include <algorithm>
#include <iostream>

void StrategyId::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
            { return a->get_id() < b->get_id(); });
}

FindType StrategyId::findTransTable(const std::string& edit,  vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        if (it->get_id() == atoi(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
}

void StrategyId::editTransTable(std::string& editClassField, std::unique_ptr<Transport>&otherVehicles)
{
    std::cout << "Редактирование ID недоступно" << std::endl;
}
#include "StrategyType.h"

#include <algorithm>
#include <iostream>

//сортировка по полю
void StrategyType::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        return a->get_type() > b->get_type(); 
    });
}

//поиск по полю
FindType StrategyType::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        //если нашли, добавляем в vector
        if (it->get_type() == edit)
            vec.push_back(it.get());
    }
    return vec;
}

//редактирование по полю
void StrategyType::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    std::cout << "Редактирование типу недоступно" << std::endl;
}
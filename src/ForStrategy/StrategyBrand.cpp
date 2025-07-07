#include "StrategyBrand.h"

#include <algorithm>
#include <iostream>

//сортировка по полю
void StrategyBrand::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        return a->get_brand() > b->get_brand();
    });
}

//поиск по полю
FindType StrategyBrand::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        //если нашли, добавляем в vector
        if (it->get_brand() == edit)
            vec.push_back(it.get());
    }
    return vec;
} 

//редактирование по полю
void StrategyBrand::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    otherVehicles->set_brand(editClassField);
}
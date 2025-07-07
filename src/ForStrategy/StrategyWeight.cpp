#include "StrategyWeight.h"

#include <algorithm>
#include <iostream>

//сортировка по полю
void StrategyWeight::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        return a->get_weight() > b->get_weight();
    });
}

//поиск по полю
FindType StrategyWeight::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        //если нашли, добавляем в vector
        if (it->get_weight() == atof(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

//редактирование по полю
void StrategyWeight::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    otherVehicles->set_weight(std::atof(editClassField.c_str()));
}
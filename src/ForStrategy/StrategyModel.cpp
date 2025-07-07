#include "StrategyModel.h"

#include <algorithm>
#include <iostream>

//сортировка по полю
void StrategyModel::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        return a->get_model() > b->get_model(); 
    });
}

//поиск по полю
FindType StrategyModel::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        //если нашли, добавляем в vector
        if (it->get_model() == edit)
            vec.push_back(it.get());
    }
    return vec;
} 

//редактирование по полю
void StrategyModel::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    otherVehicles->set_model(editClassField);
}
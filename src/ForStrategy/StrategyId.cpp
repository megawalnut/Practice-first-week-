#include "StrategyId.h"

#include <algorithm>
#include <iostream>

//сортировка по полю
void StrategyId::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        return a->get_id() < b->get_id(); 
    });
}

//поиск по полю
FindType StrategyId::findTransTable(const std::string& edit,  vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        //если нашли, добавляем в vector
        if (it->get_id() == atoi(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
}

//редактирование по полю
void StrategyId::editTransTable(std::string& editClassField, std::unique_ptr<Transport>&otherVehicles)
{
    std::cout << "Редактирование ID недоступно" << std::endl;
}
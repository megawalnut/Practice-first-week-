#include "StrategyEnginePower.h"
#include "Helicopter.h"

#include <algorithm>
#include <iostream>

//сортировка по полю
void StrategyEnginePower::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Helicopter* first = dynamic_cast<Helicopter*>(a.get());
        Helicopter* second = dynamic_cast<Helicopter*>(b.get());

        //если нужные типы
        if (first && second)
            return first->get_enginePower() > second->get_enginePower(); 
        //если нужный тип 1-ый
        else if (first && !second)
            return true;
        //если нужный тип 2-ой
        else if (!first && second)
            return false;
        //если нет нужных типов
        else
            return false;
    });
}

//поиск по полю
FindType StrategyEnginePower::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for (const auto& it :  otherVehicles)
    {  
        Helicopter* helicopter = dynamic_cast<Helicopter*>(it.get());
        
        //если нашли, добавляем в vector
        if (helicopter && helicopter->get_enginePower() == atoi(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

//редактирование по полю
void StrategyEnginePower::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Helicopter* helicopter = dynamic_cast<Helicopter*>(otherVehicles.get());

    //если возможно, редактируем
    if (helicopter)
        helicopter->set_enginePower(atoi(editClassField.c_str()));
}
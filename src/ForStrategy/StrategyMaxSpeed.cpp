#include "StrategyMaxSpeed.h"
#include "Spaceship.h"

#include <algorithm>
#include <iostream>

//сортировка по полю
void StrategyMaxSpeed::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Spaceship* first = dynamic_cast<Spaceship*>(a.get());
        Spaceship* second = dynamic_cast<Spaceship*>(b.get());

        //если нужные типы
        if (first && second)
            return first->get_maxSpeed() > second->get_maxSpeed(); 
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
FindType StrategyMaxSpeed::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for (const auto& it :  otherVehicles)
    {  
        Spaceship* spaceship = dynamic_cast<Spaceship*>(it.get());

        //если нашли, добавляем в vector
        if (spaceship && spaceship->get_maxSpeed() == atof(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

//редактирование по полю
void StrategyMaxSpeed::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Spaceship* spaceship = dynamic_cast<Spaceship*>(otherVehicles.get());

    //если возможно, редактируем
    if (spaceship)
        spaceship->set_maxSpeed(atof(editClassField.c_str()));
}
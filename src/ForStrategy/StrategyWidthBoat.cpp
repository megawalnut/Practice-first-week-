#include "StrategyWidthBoat.h"
#include "Boat.h"

#include <algorithm>
#include <iostream>

//сортировка по полю
void StrategyWidthBoat::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Boat* first = dynamic_cast<Boat*>(a.get());
        Boat* second = dynamic_cast<Boat*>(b.get());

        //если нужные типы
        if (first && second)
            return first->get_widthBoat() > second->get_widthBoat(); 
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
FindType StrategyWidthBoat::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for (const auto& it :  otherVehicles)
    {  
        Boat* boat = dynamic_cast<Boat*>(it.get());

        //если нашли, добавляем в vector
        if (boat && boat->get_widthBoat() == atof(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

//редактирование по полю
void StrategyWidthBoat::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Boat* boat = dynamic_cast<Boat*>(otherVehicles.get());

    //если возможно, редактируем
    if (boat)
        boat->set_widthBoat(atof(editClassField.c_str()));
}
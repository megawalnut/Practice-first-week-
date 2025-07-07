#include "StrategyMileage.h"
#include "Car.h"

#include <algorithm>
#include <iostream>

//сортировка по полю
void StrategyMileage::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Car* first = dynamic_cast<Car*>(a.get());
        Car* second = dynamic_cast<Car*>(b.get());

        //если нужные типы
        if (first && second)
            return first->get_mileage() > second->get_mileage(); 
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
FindType StrategyMileage::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for(const auto& it : otherVehicles)
    {
        Car* car = dynamic_cast<Car*>(it.get());

        //если нашли, добавляем в vector
        if (car && car->get_mileage() == atof(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

//редактирование по полю
void StrategyMileage::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Car* car = dynamic_cast<Car*>(otherVehicles.get());

    //если возможно, редактируем
    if (car)
        car->set_mileage(atof(editClassField.c_str()));
}
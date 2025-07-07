#include "StrategyEnginePower.h"
#include "Helicopter.h"

#include <algorithm>
#include <iostream>

void StrategyEnginePower::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Helicopter* first = dynamic_cast<Helicopter*>(a.get());
        Helicopter* second = dynamic_cast<Helicopter*>(b.get());
        if (first && second)
            return first->get_enginePower() > second->get_enginePower(); 
        else if (first && !second)
            return true;
        else if (!first && second)
            return false;
        else
            return false;
    });
}

FindType StrategyEnginePower::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for (const auto& it :  otherVehicles)
    {  
        Helicopter* helicopter = dynamic_cast<Helicopter*>(it.get());
        if (helicopter && helicopter->get_enginePower() == atoi(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyEnginePower::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Helicopter* helicopter = dynamic_cast<Helicopter*>(otherVehicles.get());
    if (helicopter)
        helicopter->set_enginePower(atoi(editClassField.c_str()));
}
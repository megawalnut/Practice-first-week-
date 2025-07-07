#include "StrategyCapacity.h"
#include "Helicopter.h"

#include <algorithm>
#include <iostream>

void StrategyCapacity::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Helicopter* first = dynamic_cast<Helicopter*>(a.get());
        Helicopter* second = dynamic_cast<Helicopter*>(b.get());
        if (first && second)
            return first->get_capacity() > second->get_capacity(); 
        else if (first && !second)
            return true;
        else if (!first && second)
            return false;
        else
            return false;
    });
}

FindType StrategyCapacity::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for (const auto& it :  otherVehicles)
    {  
        Helicopter* helicopter = dynamic_cast<Helicopter*>(it.get());
        if (helicopter && helicopter->get_capacity() == atof(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyCapacity::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Helicopter* helicopter = dynamic_cast<Helicopter*>(otherVehicles.get());
    if (helicopter)
        helicopter->set_capacity(atof(editClassField.c_str()));
}
#include "StrategyHyperjumpRange.h"
#include "Spaceship.h"

#include <algorithm>
#include <iostream>

void StrategyHyperjumpRange::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Spaceship* first = dynamic_cast<Spaceship*>(a.get());
        Spaceship* second = dynamic_cast<Spaceship*>(b.get());
        if (first && second)
            return first->get_hyperjumpRange() > second->get_hyperjumpRange(); 
        else if (first && !second)
            return true;
        else if (!first && second)
            return false;
        else
            return false;
    });
}

FindType StrategyHyperjumpRange::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for (const auto& it :  otherVehicles)
    {  
        Spaceship* spaceship = dynamic_cast<Spaceship*>(it.get());
        if (spaceship && spaceship->get_hyperjumpRange() == atof(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyHyperjumpRange::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Spaceship* spaceship = dynamic_cast<Spaceship*>(otherVehicles.get());
    if (spaceship)
        spaceship->set_hyperjumpRange(atof(editClassField.c_str()));
}
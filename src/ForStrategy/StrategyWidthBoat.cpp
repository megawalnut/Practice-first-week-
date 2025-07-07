#include "StrategyWidthBoat.h"
#include "Boat.h"

#include <algorithm>
#include <iostream>

void StrategyWidthBoat::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Boat* first = dynamic_cast<Boat*>(a.get());
        Boat* second = dynamic_cast<Boat*>(b.get());
        if (first && second)
            return first->get_widthBoat() > second->get_widthBoat(); 
        else if (first && !second)
            return true;
        else if (!first && second)
            return false;
        else
            return false;
    });
}

FindType StrategyWidthBoat::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for (const auto& it :  otherVehicles)
    {  
        Boat* boat = dynamic_cast<Boat*>(it.get());
        if (boat && boat->get_widthBoat() == atof(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyWidthBoat::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Boat* boat = dynamic_cast<Boat*>(otherVehicles.get());
    if (boat)
        boat->set_widthBoat(atof(editClassField.c_str()));
}
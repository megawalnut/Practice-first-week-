#include "StrategyLengthBoat.h"
#include "Boat.h"

#include <algorithm>
#include <iostream>

void StrategyLengthBoat::sortTable(vectorType& otherVehicles)
{
    std::sort(otherVehicles.begin(), otherVehicles.end(), [](const auto &a, const auto &b) 
    { 
        Boat* first = dynamic_cast<Boat*>(a.get());
        Boat* second = dynamic_cast<Boat*>(b.get());
        if (first && second)
            return first->get_lengthBoat() > second->get_lengthBoat(); 
        else if (first && !second)
            return true;
        else if (!first && second)
            return false;
        else
            return false;
    });
}

FindType StrategyLengthBoat::findTransTable(const std::string& edit, vectorType& otherVehicles)
{
    FindType vec;
    for (const auto& it :  otherVehicles)
    {  
        Boat* boat = dynamic_cast<Boat*>(it.get());
        if (boat && boat->get_lengthBoat() == atof(edit.c_str()))
            vec.push_back(it.get());
    }
    return vec;
} 

void StrategyLengthBoat::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{
    Boat* boat = dynamic_cast<Boat*>(otherVehicles.get());
    if (boat)
        boat->set_lengthBoat(atof(editClassField.c_str()));
}
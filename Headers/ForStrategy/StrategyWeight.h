#pragma once

#include "Strategy.h"

class StrategyWeight : public Strategy 
{
    public:
        //сортировка по полю
        void sortTable(vectorType& otherVehicles) override;
        //поиск по полю
        FindType findTransTable(const std::string& edit, vectorType& otherVehicles) override;
        //редактирование поля
        void editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles) override;
                
        //деструктор
        ~StrategyWeight() = default;
};
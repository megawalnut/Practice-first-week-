#pragma once

#include "Transport.h"

#include <vector>
#include <memory>

using FindType = std::vector<Transport*>;
using vectorType = std::vector<std::unique_ptr<Transport>>;

class Strategy {
    public:
        //сортировка по полю
        virtual void sortTable(vectorType& otherVehicles);
        //поиск по полю
        virtual FindType findTransTable(const std::string& edit, vectorType& otherVehicles);
        //редактирование поля
        virtual void editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles);
        //деструктор
        virtual ~Strategy();
};

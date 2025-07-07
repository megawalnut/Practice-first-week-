#pragma once

#include "Strategy.h"

class Context {
    private:
        //объект интерфейса Strategy
        std::unique_ptr<Strategy> m_strategy;
    public:
        //конструктор
        explicit Context(std::unique_ptr<Strategy>&& otherStrategy);
        //вызов ф-ции сортировки
        void callSortStrategy(vectorType& otherVehicles);
        //вызов ф-ции поиска
        FindType callFindStrategy(const std::string& edit, vectorType& otherVehicles);
        //вызов ф-ции редактирования
        void callEditStrategy(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles);
        //установка стратегии
        void setStrategy(std::unique_ptr<Strategy> otherStrategy);
};
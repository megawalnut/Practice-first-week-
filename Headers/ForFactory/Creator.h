#pragma once

#include "Transport.h"

#include <memory>

//фабричный метод
//базовый класс
class Creator 
{
    public:
        //создание дочернего объекта(Car, Boat ...)
        virtual std::unique_ptr<Transport> create(
            const std::string& brandTrans, 
            const std::string& modelTrans, 
            int yearTrans, 
            double weightTrans) const = 0;
    
        //деструктор
        virtual ~Creator() = default;
};
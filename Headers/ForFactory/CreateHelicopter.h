#pragma once

#include "Creator.h"

class CreateHelicopter : public Creator 
{
    public:
        //создаем дочерний класс и возвращаем указатель на базовый
        std::unique_ptr<Transport> create(
            const std::string& brandTrans, 
            const std::string& modelTrans, 
            int yearTrans, 
            double weightTrans) const override;

        //деструктор
        ~CreateHelicopter() = default;
};

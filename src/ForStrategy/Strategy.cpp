#include "Strategy.h"

#include <iostream>

//сортировка по полю
void Strategy::sortTable(vectorType& otherVehicles) 
{
    std::cerr << "Ошибка!У данного объекта метод не определён." << std::endl;
    return;
}

//поиск по полю
FindType Strategy::findTransTable(const std::string& edit, vectorType& otherVehicles) 
{
    FindType vec;
    std::cerr << "Ошибка!У данного объекта метод не определён." << std::endl;
    return vec;
}

//редактирование поля
void Strategy::editTransTable(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles) 
{
    std::cerr << "Ошибка!У данного объекта метод не определён." << std::endl;
    return;
}

//деструктор
Strategy::~Strategy() {}
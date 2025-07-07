#include "Context.h"

//конструктор
Context::Context(std::unique_ptr<Strategy>&& otherStrategy) 
    : m_strategy{std::move(otherStrategy)} {}

//вызов сортировки у заданной стратегии
void Context::callSortStrategy(vectorType& otherVehicles) 
{ 
    m_strategy->sortTable(otherVehicles); 
}

//вызов поиска у заданной стратегии
FindType Context::callFindStrategy(const std::string& edit, vectorType& otherVehicles)
{ 
    return m_strategy->findTransTable(edit, otherVehicles); 
}

//вызов редактирования поля у заданной стратегии
void Context::callEditStrategy(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
{ 
    m_strategy->editTransTable(editClassField, otherVehicles); 
}

//установка стратегии
void Context::setStrategy(std::unique_ptr<Strategy> otherStrategy)
{ 
    m_strategy= std::move(otherStrategy); 
}
#include "Context.h"

Context::Context(std::unique_ptr<Strategy>&& otherStrategy) : 
        m_strategy{std::move(otherStrategy)} {}

void Context::callSortStrategy(vectorType& otherVehicles) 
        { m_strategy->sortTable(otherVehicles); }

FindType Context::callFindStrategy(const std::string& edit, vectorType& otherVehicles)
        { return m_strategy->findTransTable(edit, otherVehicles); }

void Context::callEditStrategy(std::string& editClassField, std::unique_ptr<Transport>& otherVehicles)
        { m_strategy->editTransTable(editClassField, otherVehicles); }

void Context::setStrategy(std::unique_ptr<Strategy> otherStrategy)
        { m_strategy= std::move(otherStrategy); }
#include "Helicopter.h"

#include <iostream>
#include <iomanip>

// конструктор
Helicopter::Helicopter(const std::string &brandTrans, const std::string &modelTrans, 
        int yearTrans, double weightTrans) : Transport(
            std::string("Helicopter"),
            brandTrans,
            modelTrans,
            yearTrans,
            weightTrans), m_capacity{0.0}, m_enginePower{0} {}
// конструктор и оператор копирования
Helicopter::Helicopter(const Helicopter &other) : Transport(other), 
    m_capacity{other.m_capacity} , m_enginePower{other.m_enginePower} {}
Helicopter& Helicopter::operator=(const Helicopter &other) {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(other);

    m_capacity = other.m_capacity;
    m_enginePower = other.m_enginePower;

    return *this;
}
// конструктор и оператор перемещения
Helicopter::Helicopter(Helicopter &&other) noexcept : Transport(std::move(other)), 
    m_capacity{std::move(other.m_capacity)} , m_enginePower{std::move(other.m_enginePower)} {}
Helicopter& Helicopter::operator=(Helicopter &&other) noexcept {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(std::move(other));

    m_capacity = std::move(other.m_capacity);
    m_enginePower = std::move(other.m_enginePower);

    return *this;
}

//get
double Helicopter::get_capacity() const { return m_capacity; }
int Helicopter::get_enginePower() const { return m_enginePower; }
//set
void Helicopter::set_capacity(double capacityTrans) { m_capacity = capacityTrans; }
void Helicopter::set_enginePower(int enginePowerTrans) { m_enginePower = enginePowerTrans; }

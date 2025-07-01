#include "Spaceship.h"

#include <iostream>
#include <iomanip>

// конструктор
Spaceship::Spaceship(const std::string &brandTrans, const std::string &modelTrans, 
        int yearTrans, double weightTrans) : Transport(
            std::string("Spaceship"), 
            brandTrans, 
            modelTrans, 
            yearTrans, 
            weightTrans), m_maxSpeed{0.0}, m_hyperjumpRange{0.0} {}
// конструктор и оператор копирования
Spaceship::Spaceship(const Spaceship &other) : Transport(other), 
    m_maxSpeed{other.m_maxSpeed}, m_hyperjumpRange{other.m_hyperjumpRange} {}
Spaceship& Spaceship::operator=(const Spaceship &other) {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(other);

    m_maxSpeed = other.m_maxSpeed;
    m_hyperjumpRange = other.m_hyperjumpRange;

    return *this;
}
// конструктор и оператор перемещения
Spaceship::Spaceship(Spaceship &&other) noexcept : Transport(std::move(other)), 
    m_maxSpeed{std::move(other.m_maxSpeed)}, m_hyperjumpRange{std::move(other.m_hyperjumpRange)} {}
Spaceship& Spaceship::operator=(Spaceship &&other) noexcept {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(std::move(other));

    m_maxSpeed = std::move(other.m_maxSpeed);
    m_hyperjumpRange = std::move(other.m_hyperjumpRange);

    return *this;
}

//get
double Spaceship::get_maxSpeed() const { return m_maxSpeed; }
double Spaceship::get_hyperjumpRange() const { return m_hyperjumpRange; }
//set
void Spaceship::set_maxSpeed(double maxSpeedTrans) { m_maxSpeed = maxSpeedTrans; }
void Spaceship::set_hyperjumpRange(double hyperjumpRangeTrans) { m_hyperjumpRange = hyperjumpRangeTrans; }
//info
void Spaceship::info() const 
{
	Transport::info();
	std::cout << std::left
		<< std::setw(2) << "X" << "| "
		<< std::setw(10) << "X" << "| "
		<< std::setw(9) << "X" << "| "
		<< std::setw(8) << "X" << "| "
		<< std::setw(6) << "X" << "| "
		<< std::setw(6) << "X" << "| "
		<< std::setw(6) << get_maxSpeed() << "| "
		<< std::setw(9) << get_hyperjumpRange() << "| " << std::endl;
}
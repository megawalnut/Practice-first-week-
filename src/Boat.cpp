#include "Boat.h"

#include <iostream>
#include <iomanip>

//конструктор
Boat::Boat(const std::string& brandTrans, const std::string& modelTrans, 
        int yearTrans, double weightTrans) : Transport(
            std::string("Boat"), brandTrans, 
            modelTrans, yearTrans, 
            weightTrans), m_lengthBoat{0.0}, m_widthBoat{0.0} {}
// конструктор и оператор копирования
Boat::Boat(const Boat &other) : Transport(other), 
    m_lengthBoat{other.m_lengthBoat}, m_widthBoat{other.m_widthBoat} {}
Boat& Boat::operator=(const Boat &other) {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(other);

    m_lengthBoat = other.m_lengthBoat;
    m_widthBoat = other.m_widthBoat;

    return *this;
}
// конструктор и оператор перемещения
Boat::Boat(Boat &&other) noexcept : Transport(std::move(other)), 
    m_lengthBoat{std::move(other.m_lengthBoat)}, m_widthBoat{std::move(other.m_widthBoat)} {}
Boat& Boat::operator=(Boat &&other) noexcept {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(std::move(other));

    m_lengthBoat = std::move(other.m_lengthBoat);
    m_widthBoat = std::move(other.m_widthBoat);

    return *this;
}
//get
int Boat::get_lengthBoat() const { return m_lengthBoat; }
double Boat::get_widthBoat() const { return m_widthBoat; }
//set
void Boat::set_lengthBoat(double lengthBoatTrans) { m_lengthBoat = lengthBoatTrans; }
void Boat::set_widthBoat(double widthBoatTrans) { m_widthBoat = widthBoatTrans; }
//info
void Boat::info() const 
{
	Transport::info();
	std::cout << std::left
		<< std::setw(2) << "X" << "| "
		<< std::setw(10) << "X" << "| "
		<< std::setw(9) << get_lengthBoat() << "| "
		<< std::setw(8) << get_widthBoat() << "| "
		<< std::setw(6) << "X" << "| "
		<< std::setw(6) << "X" << "| "
		<< std::setw(6) << "X" << "| "
		<< std::setw(9) << "X" << "| " << std::endl;
}
#include "Car.h"

#include <iostream>
#include <iomanip>

//конструктор
Car::Car(const std::string& brandTrans, const std::string& modelTrans, 
		int yearTrans, double weightTrans): Transport(
			std::string("Car"), brandTrans,
			modelTrans, yearTrans,
			weightTrans), m_owners{0}, m_mileage{0.0} {}
//конструктор и оператор копирования
Car::Car(const Car& other) : Transport(other), 
	m_owners{other.m_owners}, m_mileage{other.m_mileage} {}
Car& Car::operator=(const Car& other) {
	if (&other == this) {
		return *this;
	}
	Transport::operator=(other);

	m_owners = other.m_owners;
	m_mileage = other.m_mileage;

	return *this;
}
//конструктор и оператор перемещения
Car::Car(Car&& other) : Transport(std::move(other)),  
	m_owners{std::move(other.m_owners)}, m_mileage{std::move(other.m_mileage)} {}
Car& Car::operator=(Car&& other) noexcept {
	if (&other == this) {
		return *this;
	}
	Transport::operator=(std::move(other));

	m_owners = std::move(other.m_owners);
	m_mileage = std::move(other.m_mileage);

	return *this;
}
//get
int Car::get_owners() const { return m_owners; }
double Car::get_mileage() const { return m_mileage; }
//set
void Car::set_owners(int ownersTrans) { m_owners = ownersTrans; }
void Car::set_mileage(double mileageTrans) { m_mileage = mileageTrans; }
//info
void Car::info() const
{
	Transport::info();
	std::cout << std::left
		<< std::setw(2) << get_owners() << "| "
		<< std::setw(10) << get_mileage() << "| "
		<< std::setw(9) << "X" << "| "
		<< std::setw(8) << "X" << "| "
		<< std::setw(6) << "X" << "| "
		<< std::setw(6) << "X" << "| "
		<< std::setw(6) << "X" << "| "
		<< std::setw(9) << "X" << "| " << std::endl;
}
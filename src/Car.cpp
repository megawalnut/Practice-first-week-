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

//для редактирования owners и mileage
void Car::edit()
{
	int ownersTrans;
	double mileageTrans;
	std::cout << "Введите число владельцев: \n";
	std::cin >> ownersTrans;
	std::cout << "Введите пробег(км): \n";
	std::cin >> mileageTrans;
	set_owners(ownersTrans);
	set_mileage(mileageTrans);
}

//для чтения доп. полей из файла
void Car::read_from_file(std::istream& in)
{
	int ownersTrans; 
	double mileageTrans;
	if(!(in >> ownersTrans >> mileageTrans))
	{    	
		set_owners(0);
  		set_mileage(0.0);
		return;
	}
	set_owners(ownersTrans);
    set_mileage(mileageTrans);
}

//для записи доп. полей в файл
std::string Car::load_to_file() const
{
    return std::to_string(get_owners()) + " " + std::to_string(get_mileage());
}

//для вывода информации
void Car::info() const
{
    std::cout << "ID: " << get_id() << "\n";
    std::cout << "Тип: " << get_type() << "\n";
    std::cout << "Марка: " << get_brand() << "\n";
    std::cout << "Модель: " << get_model() << "\n";
    std::cout << "Год: " << get_year() << "\n";
    std::cout << "Вес: " << get_weight() << "\n";
    std::cout << "Число владельцев: " << get_owners() << "\n";
    std::cout << "Пробег(км): " << get_mileage() << std::endl;
}
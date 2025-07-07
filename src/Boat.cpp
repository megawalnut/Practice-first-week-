#include "Boat.h"

#include <iostream>
#include <iomanip>

//конструктор
Boat::Boat(const std::string& brandTrans, 
           const std::string& modelTrans, 
           int yearTrans, 
           double weightTrans) 
    : Transport("Boat", brandTrans, modelTrans, yearTrans, weightTrans), 
      m_lengthBoat{0.0}, 
      m_widthBoat{0.0} {}

// конструктор и оператор копирования
Boat::Boat(const Boat &other) 
    : Transport(other), 
      m_lengthBoat{other.m_lengthBoat}, 
      m_widthBoat{other.m_widthBoat} {}

Boat& Boat::operator=(const Boat &other) 
{
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
Boat::Boat(Boat &&other) noexcept 
    : Transport(std::move(other)), 
      m_lengthBoat{std::move(other.m_lengthBoat)}, 
      m_widthBoat{std::move(other.m_widthBoat)} {}

Boat& Boat::operator=(Boat &&other) noexcept 
{
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

//для редактирования owners и mileage
void Boat::edit()
{
	double lengthBoatTrans;
	double widthBoatTrans;
	std::cout << "Введите длину судна(м): \n";
	std::cin >> lengthBoatTrans;
	std::cout << "Введите ширину судна(м): \n";
	std::cin >> widthBoatTrans;
	set_lengthBoat(lengthBoatTrans);
	set_widthBoat(widthBoatTrans);
}

//для чтения доп. полей из файла
void Boat::read_from_file(std::istream& in)
{
	double lengthBoatTrans;
	double widthBoatTrans;
	if(!(in >> lengthBoatTrans >> widthBoatTrans))
	{    	
		set_lengthBoat(0.0);
  		set_widthBoat(0.0);
		return;
	}
	set_lengthBoat(lengthBoatTrans);
    set_widthBoat(widthBoatTrans);
}

//для записи доп. полей в файл
std::string Boat::load_to_file() const
{
    return std::to_string(get_lengthBoat()) + " " + std::to_string(get_widthBoat());
}

//для вывода информации
void Boat::info() const
{
    std::cout << "ID: " << get_id() << "\n";
    std::cout << "Тип: " << get_type() << "\n";
    std::cout << "Марка: " << get_brand() << "\n";
    std::cout << "Модель: " << get_model() << "\n";
    std::cout << "Год: " << get_year() << "\n";
    std::cout << "Вес: " << get_weight() << "\n";
    std::cout << "Длина судна(м): " << get_lengthBoat() << "\n";
    std::cout << "Ширина судна(м): " << get_widthBoat() << std::endl;
}
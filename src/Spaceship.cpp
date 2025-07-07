#include "Spaceship.h"

#include <iostream>
#include <iomanip>

// конструктор
Spaceship::Spaceship(const std::string &brandTrans, 
                     const std::string &modelTrans, 
                     int yearTrans, 
                     double weightTrans) 
    : Transport("Spaceship", brandTrans, modelTrans, yearTrans, weightTrans), 
      m_maxSpeed{0.0}, 
      m_hyperjumpRange{0.0} {}

// конструктор и оператор копирования
Spaceship::Spaceship(const Spaceship &other) 
    : Transport(other), 
      m_maxSpeed{other.m_maxSpeed}, 
      m_hyperjumpRange{other.m_hyperjumpRange} {}

Spaceship& Spaceship::operator=(const Spaceship &other) 
{
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
Spaceship::Spaceship(Spaceship &&other) noexcept 
    : Transport(std::move(other)), 
      m_maxSpeed{std::move(other.m_maxSpeed)}, 
      m_hyperjumpRange{std::move(other.m_hyperjumpRange)} {}

Spaceship& Spaceship::operator=(Spaceship &&other) noexcept 
{
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

//для редактирования owners и mileage
void Spaceship::edit()
{
    double maxSpeedTrans;
    double hyperjumpRangeTrans;
    std::cout << "Введите макс скорость(км.с): \n";
    std::cin >> maxSpeedTrans;
    std::cout << "Введите дальность прыжка(а.е): \n";
    std::cin >> hyperjumpRangeTrans;
    set_maxSpeed(maxSpeedTrans);
    set_hyperjumpRange(hyperjumpRangeTrans);
}

//для чтения доп. полей из файла
void Spaceship::read_from_file(std::istream& in)
{
    double maxSpeedTrans;
    double hyperjumpRangeTrans;
    if(!(in >> maxSpeedTrans >> hyperjumpRangeTrans))
    {        
        set_maxSpeed(0.0);
          set_hyperjumpRange(0);
        return;
    }
    set_maxSpeed(maxSpeedTrans);
    set_hyperjumpRange(hyperjumpRangeTrans);
}

//для записи доп. полей в файл
std::string Spaceship::load_to_file() const
{
    return std::to_string(get_maxSpeed()) + " " + std::to_string(get_hyperjumpRange());
}

//для вывода информации
void Spaceship::info() const
{
    std::cout << "ID: " << get_id() << "\n";
    std::cout << "Тип: " << get_type() << "\n";
    std::cout << "Марка: " << get_brand() << "\n";
    std::cout << "Модель: " << get_model() << "\n";
    std::cout << "Год: " << get_year() << "\n";
    std::cout << "Вес: " << get_weight() << "\n";
    std::cout << "Макс.скорость(км.с): " << get_maxSpeed() << "\n";
    std::cout << "Дальность гиперпрыжка(а.е): " << get_hyperjumpRange() << std::endl;
}
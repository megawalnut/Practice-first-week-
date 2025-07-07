#include "Helicopter.h"

#include <iostream>
#include <iomanip>

// конструктор
Helicopter::Helicopter(const std::string &brandTrans, 
                       const std::string &modelTrans, 
                       int yearTrans, 
                       double weightTrans) 
    : Transport("Helicopter", brandTrans, modelTrans,yearTrans, weightTrans), 
      m_capacity{0.0}, 
      m_enginePower{0} {}

// конструктор и оператор копирования
Helicopter::Helicopter(const Helicopter &other) 
    : Transport(other), 
      m_capacity{other.m_capacity} , 
      m_enginePower{other.m_enginePower} {}

Helicopter& Helicopter::operator=(const Helicopter &other)
{
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
Helicopter::Helicopter(Helicopter &&other) noexcept
    : Transport(std::move(other)), 
      m_capacity{std::move(other.m_capacity)} , 
      m_enginePower{std::move(other.m_enginePower)} {}

Helicopter& Helicopter::operator=(Helicopter &&other) noexcept 
{
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

//для редактирования owners и mileage
void Helicopter::edit()
{
    double capacityTrans;
    int enginePowerTrans;
    std::cout << "Введите грузоподъемность(т): \n";
    std::cin >> capacityTrans;
    std::cout << "Введите мощность(лс): \n";
    std::cin >> enginePowerTrans;
    set_capacity(capacityTrans);
    set_enginePower(enginePowerTrans);
}

//для чтения доп. полей из файла
void Helicopter::read_from_file(std::istream& in)
{
    double capacityTrans;
    int enginePowerTrans;
    if(!(in >> capacityTrans >> enginePowerTrans))
    {        
        set_capacity(0.0);
          set_enginePower(0);
        return;
    }
    set_capacity(capacityTrans);
    set_enginePower(enginePowerTrans);
}

//для записи доп. полей в файл
std::string Helicopter::load_to_file() const
{
    return std::to_string(get_capacity()) + " " + std::to_string(get_enginePower());
}

//для вывода информации
void Helicopter::info() const
{
    std::cout << "ID: " << get_id() << "\n";
    std::cout << "Тип: " << get_type() << "\n";
    std::cout << "Марка: " << get_brand() << "\n";
    std::cout << "Модель: " << get_model() << "\n";
    std::cout << "Год: " << get_year() << "\n";
    std::cout << "Вес: " << get_weight() << "\n";
    std::cout << "Грузоподъемность(т): " << get_capacity() << "\n";
    std::cout << "Мощность(лс): " << get_enginePower() << std::endl;
}
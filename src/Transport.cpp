#include "Transport.h"
#include <iostream>
#include <string>
#include <iomanip>

	//конструктор
Transport::Transport(const std::string& typeTrans, const std::string& brandTrans, const std::string& modelTrans, int yearTrans, double weightTrans) :
	m_unique_id{ m_for_id++ },
	m_type{ typeTrans },
	m_brand{ brandTrans },
	m_model{ modelTrans },
	m_year{ yearTrans },
	m_weight{ weightTrans } {}

//конструктор и оператор копирования
Transport::Transport(const Transport& other) :
	m_unique_id{ m_for_id++ },
	m_type{ other.m_type },
	m_brand{ other.m_brand },
	m_model{ other.m_model },
	m_year{ other.m_year },
	m_weight{ other.m_weight } {}

Transport& Transport::operator=(const Transport& other) {
	if (&other == this) {
		return *this;
	}

	m_for_id++;
	m_unique_id = m_for_id;
	m_type = other.m_type;
	m_brand = other.m_brand;
	m_model = other.m_model;
	m_year = other.m_year;
	m_weight = other.m_weight;

	return *this;
}
//конструктор и оператор перемещения
Transport::Transport(Transport&& other) noexcept :
	m_unique_id{ m_for_id++ },
	m_type{ std::move(other.m_type) },
	m_brand{ std::move(other.m_brand) },
	m_model{ std::move(other.m_model) },
	m_year{ std::move(other.m_year) },
	m_weight{ std::move(other.m_weight) } {
}
Transport& Transport::operator=(Transport&& other) noexcept {
	if (&other == this) {
		return *this;
	}

	m_for_id++;
	m_unique_id = m_for_id;
	m_type = std::move(other.m_type);
	m_brand = std::move(other.m_brand);
	m_model = std::move(other.m_model);
	m_year = std::move(other.m_year);
	m_weight = std::move(other.m_weight);

	return *this;
}

//get 
int Transport::get_id() const { return m_unique_id; }
std::string Transport::get_type() const { return m_type; }
std::string Transport::get_brand() const { return m_brand; }
std::string Transport::get_model() const { return m_model; }
int Transport::get_year() const { return m_year; }
double Transport::get_weight() const { return m_weight; }

//set 
void Transport::set_type(const std::string& str) { m_type = str; }
void Transport::set_brand(const std::string& str) { m_brand = str; }
void Transport::set_model(const std::string& str) { m_model = str; }
void Transport::set_year(const int str) { m_year = str; }
void Transport::set_weight(const double str) { m_weight = str; }

//информация
void Transport::info() const {
	std::cout << std::left
		<< std::setw(2) << get_id() << "| "
		<< std::setw(10) << get_type() << "| "
		<< std::setw(9) << get_brand() << "| "
		<< std::setw(8) << get_model() << "| "
		<< std::setw(6) << get_year() << "| "
		<< std::setw(9) << get_weight() << std::endl;
}
int Transport::m_for_id = 1;
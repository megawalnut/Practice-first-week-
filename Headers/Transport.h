#pragma once

#include <string>

class Transport {
private:
	static int m_for_id;	//для уникальности
	int m_unique_id;			//уникальный id
	std::string m_type;		//тип транспортного средства
	std::string m_brand;	//марка
	std::string m_model;	//модель
	int m_year;				//год
	double m_weight;		//вес

public:
	//конструктор
	Transport(const std::string& typeTrans, 
		const std::string& brandTrans, 
		const std::string& modelTrans, 
		int yearTrans, 
		double weightTrans);
	//конструктор и оператор копирования
	Transport(const Transport& other);
	Transport& operator=(const Transport& other);

	//конструктор и оператор перемещения
	Transport(Transport&& other) noexcept;
	Transport& operator=(Transport&& other) noexcept;

	//деструктор
	virtual ~Transport() = default;

	//get 
	virtual int get_id() const;
	virtual std::string get_type() const;
	virtual std::string get_brand() const;
	virtual std::string get_model() const;
	virtual int get_year() const;
	virtual double get_weight() const;

	//set 
	virtual void set_type(const std::string& str);
	virtual void set_brand(const std::string& str);
	virtual void set_model(const std::string& str);
	virtual void set_year(const int str);
	virtual void set_weight(const double str);

	//информация
	virtual void info() const;
};
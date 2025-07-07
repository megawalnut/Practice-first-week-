#pragma once

#include <string>

class Transport {
	private:
		static int m_for_id;	//для уникальности
		int m_unique_id;		//уникальный id
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
		virtual ~Transport();

		//get 
		int get_id() const;
		std::string get_type() const;
		std::string get_brand() const;
		std::string get_model() const;
		int get_year() const;
		double get_weight() const;

		//set 
		void set_type(const std::string& str);
		void set_brand(const std::string& str);
		void set_model(const std::string& str);
		void set_year(const int str);
		void set_weight(const double str);

		//для редактирования доп. полей
		virtual void edit() = 0;

		//для чтения доп. полей из файла
		virtual void read_from_file(std::istream& in) = 0;

		//для записи доп. полей в файл
		virtual std::string load_to_file() const = 0;

		//для вывода информации
		virtual void info() const = 0;
};
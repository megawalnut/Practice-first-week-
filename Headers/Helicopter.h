#pragma once

#include "Transport.h"

class Helicopter : public Transport {
	private:
		double m_capacity;		 //грузоподъемность
		int m_enginePower;		 //мощность двигателя (в л.с.)
	public:
		//конструктор
		Helicopter(const std::string& brandTrans, 
			const std::string& modelTrans, 
			int yearTrans, 
			double weightTrans);
		//конструктор и оператор копирования
		Helicopter(const Helicopter& other);
		Helicopter& operator=(const Helicopter& other);
		//конструктор и оператор перемещения
		Helicopter(Helicopter&& other) noexcept;
		Helicopter& operator=(Helicopter&& other) noexcept;
		//деструктор
		~Helicopter() = default;
		
		//get
		double get_capacity() const;
		int get_enginePower() const;
		
		//set
		void set_capacity(double capacityTrans);
		void set_enginePower(int enginePowerTrans);

		//для редактирования capacity и enginePower
		void edit() override;

		//для чтения доп. полей из файла
		void read_from_file(std::istream& in) override;

		//для записи доп. полей в файл
		std::string load_to_file() const override;

		//для вывода информации
		void info() const override;
};
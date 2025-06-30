#pragma once

#include "Transport.h"

class Car : public Transport {
	private:
		int m_owners;		//число владельцев
		double m_mileage;	//пробег
	public:
		//конструктор
		Car(const std::string& brandTrans, 
			const std::string& modelTrans, 
			int yearTrans, 
			double weightTrans);
		//конструктор и оператор копирования
		Car(const Car& other);
		Car& operator=(const Car& other);
		//конструктор и оператор перемещения
		Car(Car&& other);
		Car& operator=(Car&& other) noexcept;
		//деструктор
		~Car() = default;

		//get
		int get_owners() const;
		double get_mileage() const;
		
		//set
		void set_owners(int ownersTrans);
		void set_mileage(double mileageTrans);

		//информация об объекте
		void info() const override;
		
};
#pragma once

#include "Transport.h"

class Car : public Transport {

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
};
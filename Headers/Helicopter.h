#pragma once

#include "Transport.h"

class Helicopter : public Transport {
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

};
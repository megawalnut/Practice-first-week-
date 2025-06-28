#pragma once

#include "Transport.h"

class Spaceship : public Transport {
	public:
		//конструктор
		Spaceship(const std::string& brandTrans, 
			const std::string& modelTrans, 
			int yearTrans, 
			double weightTrans);
		//конструктор и оператор копирования
		Spaceship(const Spaceship& other);
		Spaceship& operator=(const Spaceship& other);
		//конструктор и оператор перемещения
		Spaceship(Spaceship&& other) noexcept;
		Spaceship& operator=(Spaceship&& other) noexcept;
		//деструктор
		~Spaceship() = default;
	
};
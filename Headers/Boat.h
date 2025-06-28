#pragma once

#include "Transport.h"

class Boat : public Transport {
	private:


	public:
		//конструктор
		Boat(const std::string& brandTrans, 
			const std::string& modelTrans, 
			int yearTrans, 
			double weightTrans);
		//конструктор и оператор копирования
		Boat(const Boat& other);
		Boat& operator=(const Boat& other);
		//конструктор и оператор перемещения
		Boat(Boat&& other) noexcept;
		Boat& operator=(Boat&& other) noexcept;
		//деструктор
		~Boat() = default;
		
};
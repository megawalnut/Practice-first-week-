#pragma once

#include "Transport.h"

class Boat : public Transport {
	private:
		double m_lengthBoat;	//длина судна
		double m_widthBoat;		//ширина судна

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
		
		//get
		int get_lengthBoat() const;
		double get_widthBoat() const;
		
		//set
		void set_lengthBoat(double lengthBoatTrans);
		void set_widthBoat(double widthBoatTrans);
};
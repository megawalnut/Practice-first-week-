#pragma once

#include "Transport.h"

class Spaceship : public Transport {
	private:
		double m_maxSpeed;		//макс. скорость км/c
		double m_hyperjumpRange;	//дальность гиперпрыжка(а.е.)

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
			
		//get
		double get_maxSpeed() const;
		double get_hyperjumpRange() const;
		
		//set
		void set_maxSpeed(double maxSpeedTrans);
		void set_hyperjumpRange(double hyperjumpRangeTrans);

		//информация об объекте
		void info() const override;
};
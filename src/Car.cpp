#include "Car.h"

//конструктор
Car::Car(const std::string& brandTrans, const std::string& modelTrans, int yearTrans, double weightTrans) : Transport(
	std::string("Car"),
	brandTrans,
	modelTrans,
	yearTrans,
	weightTrans) {
}
//конструктор и оператор копирования
Car::Car(const Car& other) : Transport(other) {}
Car& Car::operator=(const Car& other) {
	if (&other == this) {
		return *this;
	}
	Transport::operator=(other);
	return *this;
}
//конструктор и оператор перемещения
Car::Car(Car&& other) : Transport(std::move(other)) {}
Car& Car::operator=(Car&& other) noexcept {
	if (&other == this) {
		return *this;
	}
	Transport::operator=(std::move(other));

	return *this;
}
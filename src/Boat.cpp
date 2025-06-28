#include "Boat.h"


//конструктор
Boat::Boat(const std::string& brandTrans, const std::string& modelTrans, int yearTrans, double weightTrans) : Transport(
	std::string("Boat"), 
	brandTrans, 
	modelTrans, 
	yearTrans, 
	weightTrans) {}
// конструктор и оператор копирования
Boat::Boat(const Boat &other) : Transport(other) {}
Boat& Boat::operator=(const Boat &other) {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(other);
    return *this;
}
// конструктор и оператор перемещения
Boat::Boat(Boat &&other) noexcept : Transport(std::move(other)) {}
Boat& Boat::operator=(Boat &&other) noexcept {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(std::move(other));

    return *this;
}
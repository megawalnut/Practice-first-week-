#include "Spaceship.h"

// конструктор
Spaceship::Spaceship(const std::string &brandTrans, const std::string &modelTrans, int yearTrans, double weightTrans) : Transport(
    std::string("Spaceship"), 
    brandTrans, 
    modelTrans, 
    yearTrans, 
    weightTrans) {}
// конструктор и оператор копирования
Spaceship::Spaceship(const Spaceship &other) : Transport(other) {}
Spaceship& Spaceship::operator=(const Spaceship &other) {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(other);
    return *this;
}
// конструктор и оператор перемещения
Spaceship::Spaceship(Spaceship &&other) noexcept : Transport(std::move(other)) {}
Spaceship& Spaceship::operator=(Spaceship &&other) noexcept {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(std::move(other));

    return *this;
}
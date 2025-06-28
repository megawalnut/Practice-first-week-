#include "Helicopter.h"

// конструктор
Helicopter::Helicopter(const std::string &brandTrans, const std::string &modelTrans, int yearTrans, double weightTrans) : Transport(
    std::string("Helicopter"),
    brandTrans,
    modelTrans,
    yearTrans,
    weightTrans) {}
// конструктор и оператор копирования
Helicopter::Helicopter(const Helicopter &other) : Transport(other) {}
Helicopter& Helicopter::operator=(const Helicopter &other) {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(other);
    return *this;
}
// конструктор и оператор перемещения
Helicopter::Helicopter(Helicopter &&other) noexcept : Transport(std::move(other)) {}
Helicopter& Helicopter::operator=(Helicopter &&other) noexcept {
    if (&other == this)
    {
        return *this;
    }
    Transport::operator=(std::move(other));

    return *this;
}
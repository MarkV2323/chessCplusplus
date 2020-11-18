#include "Coord.hpp"

Coord::Coord(int x, int y): x(x), y(y) {};

void Coord::add(const Coord &c) {
    x += c.x;
    y += c.y;
}

void Coord::addWrapped(const Coord &c) {
    x += c.x;
    y += c.y;
    x = x % 8;
    y = y % 8;
}

Coord& Coord::operator+=(const Coord& rhs) {
    this->add(rhs);
    return *this;
}

Coord Coord::operator+(const Coord& rhs) const {
    Coord n = *this;
    n += rhs;
    return n;
}

bool Coord::operator==(const Coord& rhs) const {
    return x == rhs.x && y == rhs.y;
}

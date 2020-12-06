#include "../header/Coord.hpp"

#include <cstdlib>

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
    if (x < 0) x = 8+x;
    if (y < 0) y = 8+y;
}

bool Coord::isInBounds() {
    return (x >= 0) && (y >= 0) && (x < 8) && (y < 8);
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

// returns a string version of X and Y values.
std::string Coord::stringify() {
    std::string string = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    return string;
}

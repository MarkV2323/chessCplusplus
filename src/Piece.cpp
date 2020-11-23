#include "../header/Piece.hpp"
#include <stdexcept>

// Constructor
Piece::Piece(std::string aSymbol, int aValue, enum enumTeam aTeam, Coord *aCoord) {
    this->symbol = std::move(aSymbol);
    this->value = aValue;
    this->team = aTeam;
    // Checks if passed coordinates are out of bounds.
    if (aCoord->x < 0 || aCoord->x > 8 || aCoord->y < 0 || aCoord->y > 8) {
        throw std::invalid_argument("Invalid Coordinate Parameter!");
    } else {
        this->currentLocation = aCoord;
    }

}

// Destructor
Piece::~Piece() {
    delete this->currentLocation;
}

// Implemented non virtual functions
std::string Piece::getSymbol() {
    return this->symbol;
}

int Piece::getValue() const {
    return this->value;
}

enum enumTeam Piece::getTeam() {
    return this->team;
}

Coord* Piece::getLocation() {
    return this->currentLocation;
}

void Piece::updateLocation(Coord *newPosition) {
    // Frees the currentLocation
    delete currentLocation;
    this->currentLocation = newPosition;
}

enum enumTeam Piece::getTeam() {
    return this->team;
}

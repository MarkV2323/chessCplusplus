#include "../header/Piece.hpp"

// Constructor
Piece::Piece(std::string aSymbol, int aValue, enum enumTeam aTeam, Coord *aCoord) {
    this->symbol = std::move(aSymbol);
    this->value = aValue;
    this->team = aTeam;
    this->currentLocation = aCoord;
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

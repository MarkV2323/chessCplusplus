#include "../header/Board.hpp"
#include "../header/Piece.hpp"
#include <stdexcept>

// Constructor
Piece::Piece(std::string aSymbol, int aValue, enum Team aTeam, Coord aCoord) : currentLocation(0,0) {
    this->symbol = std::move(aSymbol);
    this->value = aValue;
    this->team = aTeam;
    // Checks if passed coordinates are out of bounds.
    if (aCoord.x < 0 || aCoord.x > 8 || aCoord.y < 0 || aCoord.y > 8) {
        throw std::invalid_argument("Invalid Coordinate Parameter!");
    } else {
        this->currentLocation = aCoord;
    }

}

// Destructor
Piece::~Piece() = default;

// Implemented non virtual functions
std::string Piece::getSymbol() {
    return this->symbol;
}

int Piece::getValue() const {
    return this->value;
}

enum Team Piece::getTeam() {
    return this->team;
}

Coord Piece::getLocation() {
    return this->currentLocation;
}

// THIS CURRENTLY IS BUGGED
void Piece::updateLocation(int x, int y) {
    // Ensures new location is within bounds.
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        this->currentLocation.x = x;
        this->currentLocation.y = y;
    } else {
        throw std::invalid_argument("Invalid Coordinate Parameter!");
    }

}

void Piece::capture(Coord dst) {
    Board::get().maybeRemovePiece(dst);
}

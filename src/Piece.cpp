#include "Piece.hpp"

std::string Piece::getSymbol() {
    return this->symbol;
}

enum enumTeam Piece::getTeam() {
    return this->team;
}

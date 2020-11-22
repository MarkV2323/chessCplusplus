#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include "Coord.hpp"

#include <string>

enum enumTeam {WHITE, BLACK};

class Piece {
private:
    std::string symbol;
    enum enumTeam team;
    int value;
    Coord* currentLocation;
public:
    Piece() : symbol(" "), value(0), team(BLACK), currentLocation(nullptr) { }; // DEFAULTS
    Piece(std::string aSymbol, int aValue, enum enumTeam aTeam, Coord* aCoord) : symbol(aSymbol), value(aValue), team(aTeam), currentLocation(aCoord) {};

    std::string getSymbol();
    enum enumTeam getTeam();
};

#endif //__PIECE_HPP__

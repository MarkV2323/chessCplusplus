#ifndef FINALPROJECT_ROOK_HPP
#define FINALPROJECT_ROOK_HPP
#include "Piece.hpp"

class Rook : public Piece {
private:

public:
    // Constructors
    Rook() : Piece() { };
    Rook(enum Team aTeam, Coord aCoord)
            : Piece("R", 25, aTeam, aCoord){ };

    // Destructor
    ~Rook() { };

    // Non Virtual Functions

    // Virtual Functions from parent
    std::vector<Coord> possibleMoves();

};
#endif //FINALPROJECT_ROOK_HPP

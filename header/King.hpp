#ifndef FINALPROJECT_KING_HPP
#define FINALPROJECT_KING_HPP
#include "Piece.hpp"

class King : public Piece {
private:

public:
    // Constructors
    King() : Piece() { };
    King(enum Team aTeam, Coord aCoord)
            : Piece("K", 100, aTeam, aCoord){ };

    // Destructor
    ~King() { };

    // Non Virtual Functions

    // Virtual Functions from parent
    std::vector<Coord> possibleMoves();

};
#endif //FINALPROJECT_KING_HPP

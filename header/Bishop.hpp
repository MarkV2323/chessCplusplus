#ifndef FINALPROJECT_BISHOP_HPP
#define FINALPROJECT_BISHOP_HPP
#include "Piece.hpp"

class Bishop : public Piece {
private:

public:
    // Constructors
    Bishop() : Piece() { };
    Bishop(enum enumTeam aTeam, Coord aCoord)
            : Piece("B", 25, aTeam, aCoord){ };

    // Destructor
    ~Bishop() { };

    // Non Virtual Functions

    // Virtual Functions from parent
    std::vector<Coord> possibleMoves();

};

#endif //FINALPROJECT_BISHOP_HPP

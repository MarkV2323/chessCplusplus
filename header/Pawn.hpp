#ifndef FINALPROJECT_PAWN_HPP
#define FINALPROJECT_PAWN_HPP
#include "Piece.hpp"

class Pawn : public Piece {
public:
    // Constructors
    Pawn() : Piece() { };
    Pawn(enum enumTeam aTeam, Coord* aCoord)
            : Piece("P", 1, aTeam, aCoord) { };

    // Destructor
    ~Pawn() { };

    // Non Virtual Functions

    // Virtual Functions from parent
    std::vector<Coord*> possibleMoves();

};


#endif //FINALPROJECT_PAWN_HPP

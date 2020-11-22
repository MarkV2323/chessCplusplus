#ifndef FINALPROJECT_PAWN_HPP
#define FINALPROJECT_PAWN_HPP
#include "Piece.hpp"

class Pawn : public Piece {
public:
    // Constructors
    Pawn() : Piece() { };
    Pawn(std::string aSymbol, int aValue, enum enumTeam aTeam, Coord* aCoord)
            : Piece(aSymbol, aValue, aTeam, aCoord) { };

    // Destructor
    ~Pawn() { };

    // Non Virtual Functions

    // Virtual Functions from parent
    std::vector<Coord*> possibleMoves();

};


#endif //FINALPROJECT_PAWN_HPP

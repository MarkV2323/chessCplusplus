#ifndef FINALPROJECT_KNIGHT_HPP
#define FINALPROJECT_KNIGHT_HPP
#include "Piece.hpp"
class Knight : public Piece {
private:

public:
    // Constructors
    Knight() : Piece() { };
    Knight(enum enumTeam aTeam, Coord aCoord)
            : Piece("Kn", 10, aTeam, aCoord){ };

    // Destructor
    ~Knight() { };

    // Non Virtual Functions

    // Virtual Functions from parent
    std::vector<Coord> possibleMoves();

};
#endif //FINALPROJECT_KNIGHT_HPP

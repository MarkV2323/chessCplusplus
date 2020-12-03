#ifndef FINALPROJECT_QUEEN_HPP
#define FINALPROJECT_QUEEN_HPP
#include "Piece.hpp"

class Queen : public Piece {
private:

public:
    // Constructors
    Queen() : Piece() { };
    Queen(enum enumTeam aTeam, Coord aCoord)
            : Piece("Q", 50, aTeam, aCoord){ };

    // Destructor
    ~Queen() { };

    // Non Virtual Functions

    // Virtual Functions from parent
    std::vector<Coord> possibleMoves();

};
#endif //FINALPROJECT_QUEEN_HPP

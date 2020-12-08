#include "../header/Queen.hpp"
#include <vector>
#include <iostream>

// returns a vector of the possible moves.
std::vector<Coord> Queen::possibleMoves() {
    std::vector<Coord> possibleMoves;
    tryMovesOnRay(possibleMoves, Coord(0,-1));
    tryMovesOnRay(possibleMoves, Coord(1,0));
    tryMovesOnRay(possibleMoves, Coord(0,1));
    tryMovesOnRay(possibleMoves, Coord(-1,0));
    tryMovesOnRay(possibleMoves, Coord(1,-1));
    tryMovesOnRay(possibleMoves, Coord(1,1));
    tryMovesOnRay(possibleMoves, Coord(-1,1));
    tryMovesOnRay(possibleMoves, Coord(-1,-1));
    return possibleMoves;
}

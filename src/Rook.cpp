#include "../header/Rook.hpp"
#include <vector>
#include <iostream>

// returns a vector of the possible moves.
std::vector<Coord> Rook::possibleMoves() {
    std::vector<Coord> possibleMoves;
    tryMovesOnRay(possibleMoves, Coord(0,-1));
    tryMovesOnRay(possibleMoves, Coord(1,0));
    tryMovesOnRay(possibleMoves, Coord(0,1));
    tryMovesOnRay(possibleMoves, Coord(-1,0));
    return possibleMoves;
}

#include "../header/Bishop.hpp"
#include <vector>

// returns a vector of the possible moves.
std::vector<Coord> Bishop::possibleMoves() {
    std::vector<Coord> possibleMoves;
    // Checks NorthEAST (negative y direction)
    tryMovesOnRay(possibleMoves, Coord(1,-1));
    // Checks SOUTHEast (positive x direction)
    tryMovesOnRay(possibleMoves, Coord(1,1));
    // Checks SouthWEST (positive y direction)
    tryMovesOnRay(possibleMoves, Coord(-1,1));
    // Checks WestNOTH (negative x direction)
    tryMovesOnRay(possibleMoves, Coord(-1,-1));
    return possibleMoves;
}

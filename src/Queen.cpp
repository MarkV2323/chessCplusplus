#include "../header/Queen.hpp"
#include "../header/Board.hpp"
#include <vector>
#include <iostream>

// in-line function for checking basic principals of available moves
// (null ptr, friendly piece, out of bounds)
inline bool basicCheck(Coord testCoord, Board &board, Team team) {
    if (testCoord.isInBounds()) {
        Piece *p = board.piece(testCoord);
        return (p == nullptr) || (p->getTeam() != team);
    }
    return false;
}

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

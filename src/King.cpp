#include "../header/King.hpp"
#include "../header/Board.hpp"
#include <vector>
#include <iostream>

// in-line function for checking bounds on testLocations.
inline bool inBounds(Coord testCoord) {
    // Checks X
    if (testCoord.x < 0 || testCoord.x > 7) {
        return false;
    }
    // Checks Y
    if (testCoord.y < 0 || testCoord.y > 7) {
        return false;
    }
    // testCoord is within the bounds.
    return true;
}


std::vector<Coord> King::possibleMoves() {
    // vector to return.
    std::vector<Coord> possibleMoves;

    // board instance.
    Board board = Board::get();

    // Current location
    Coord testLocation = this->getLocation();

    // Gets the team membership of this pawn.
    enumTeam testTeam = getTeam();

    // returns an empty vector if no possible moves exist.
    if (possibleMoves.empty()) {
        return {};
    }

    // returns the possibleMoves vector.
    return possibleMoves;

}
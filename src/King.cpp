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

// in-line function for checking basic principals of available moves
// (null ptr, friendly piece, out of bounds)
inline bool basicCheck(Coord testCoord, Board board, enumTeam team) {
    if (team == WHITE) {
        if ((board.piece(testCoord) == nullptr || board.piece(testCoord)->getTeam() != WHITE)
            && inBounds(testCoord)) {
            return true;
        }
    } else if (team == BLACK) {
        if ((board.piece(testCoord) == nullptr || board.piece(testCoord)->getTeam() != BLACK)
            && inBounds(testCoord)) {
            return true;
        }
    }
    return false;
}

std::vector<Coord> King::possibleMoves() {

    // vector to return.
    std::vector<Coord> possibleMoves;
    Board board = Board::get();
    enumTeam team = getTeam();
    Coord currentLocation = this->getLocation();
    Coord testLocation = currentLocation;

    // checks north.
    for (int i = -1; i < 2; i++) {
        testLocation.add(Coord(i, -1));
        if (basicCheck(testLocation, board, team)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = currentLocation;
    }

    // checks center.
    for (int i = -1; i < 2;) {
        testLocation.add(Coord(i, 0));
        if (basicCheck(testLocation, board, team)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = currentLocation;
        i += 2;
    }

    // checks south.
    for (int i = -1; i < 2; i++) {
        testLocation.add(Coord(i, 1));
        if (basicCheck(testLocation, board, team)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = currentLocation;
    }

    // returns an empty vector if no possible moves exist.
    if (possibleMoves.empty()) {
        return {};
    }

    // returns the possibleMoves vector.
    return possibleMoves;

}
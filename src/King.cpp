#include "../header/King.hpp"
#include "../header/Board.hpp"
#include <vector>
#include <iostream>

// // in-line function for checking basic principals of available moves
// // (null ptr, friendly piece, out of bounds)
// inline bool moveIsValid(Coord testCoord) {
//     if (testCoord.isInBounds()) {
//         Piece *p = board.piece(testCoord);
//         return (p == nullptr) || (p->getTeam() != team);
//     }
//     return false;
// }

std::vector<Coord> King::possibleMoves() {

    // vector to return.
    std::vector<Coord> possibleMoves;
    Board &board = Board::get();
    Team team = getTeam();
    Coord currentLocation = this->getLocation();
    Coord testLocation = currentLocation;

    // checks north.
    for (int i = -1; i < 2; i++) {
        testLocation.add(Coord(i, -1));
        if (moveIsValid(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = currentLocation;
    }

    // checks center.
    for (int i = -1; i < 2; i+=2) {
        testLocation.add(Coord(i, 0));
        if (moveIsValid(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = currentLocation;
    }

    // checks south.
    for (int i = -1; i < 2; i++) {
        testLocation.add(Coord(i, 1));
        if (moveIsValid(testLocation)) {
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


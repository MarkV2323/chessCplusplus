#include "../header/Pawn.hpp"
#include "../header/Board.hpp"
#include <vector>
#include <iostream>

/*
 * Pawn chess pieces can only directly forward one square, with two exceptions.
 * Pawns can move directly forward two squares on their first move only.
 * Pawns can move diagonally forward when capturing an opponent's chess piece.
 * Once a pawn chess piece reaches the other side of the chess board, the player may "trade" the pawn in
 * for any other chess piece if they choose, except another king.
 */
class Board;

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

// Non-virtual function from parent.
bool Pawn::isFirstMove() {
    // Checks the current position for the first move.
    // pawns eligible for first move must be in spawn position.
    // North side: (0, 1) to (7, 1) team black, South side: (0, 6) to (7, 6) team white.
    if (this->getTeam() == BLACK && getLocation().y == 1) {
        return true;
    } else if (this->getTeam() == WHITE && getLocation().y == 6) {
        return true;
    } else {
        if (firstMove) {
            removeFirstMove();
        }
        return false;
    }
}

// Virtual function from parent.
std::vector<Coord> Pawn::possibleMoves() {
    // vector to return.
    std::vector<Coord> possibleMoves;

    // board instance.
    Board &board = Board::get();

    // Current location
    Coord testLocation = this->getLocation();

    // Gets the team membership of this pawn.
    Team testTeam = getTeam();

    // North side: (0, 1) to (7, 1) team black.
    // South side: (0, 6) to (7, 6) team white.

    // checks if its the first move for this pawn.
    if (isFirstMove()) {
        // for black first move.
        if (testTeam == BLACK) {
            // should move in the positive coordinate direction (south).
            // adds 2 y
            testLocation.add(Coord(0,2));
            // checks if valid
            if ((board.piece(testLocation) == nullptr || board.piece(testLocation)->getTeam() != BLACK)
                && inBounds(testLocation)) {
                // add valid location to possibleMoves
                possibleMoves.push_back(testLocation);
            }
            testLocation = this->getLocation();
        }
        // for white first move.
        if (testTeam == WHITE) {
            // should move in the negative coordinate direction (north).
            // subs 2 y
            testLocation.add(Coord(0,-2));
            // checks if valid
            if ((board.piece(testLocation) == nullptr || board.piece(testLocation)->getTeam() != WHITE)
                && inBounds(testLocation)) {
                // add valid location to possibleMoves
                possibleMoves.push_back(testLocation);
            }
            testLocation = this->getLocation();
        }
    }

    // checks for possible enemy pieces (diagonal move)
    if (testTeam == BLACK) {
        // checks 1 east 1 south
        testLocation.add(Coord(1,1));
        if ((board.piece(testLocation) != nullptr && board.piece(testLocation)->getTeam() != BLACK)
            && inBounds(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = this->getLocation();

        // checks 1 west 1 south
        testLocation.add(Coord(-1,1));
        if ((board.piece(testLocation) != nullptr && board.piece(testLocation)->getTeam() != BLACK)
            && inBounds(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = this->getLocation();
    }
    if (testTeam == WHITE) {
        // checks 1 east 1 north
        testLocation.add(Coord(1,-1));
        if ((board.piece(testLocation) != nullptr && board.piece(testLocation)->getTeam() != WHITE)
            && inBounds(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = this->getLocation();

        // checks 1 west 1 north
        testLocation.add(Coord(-1,-1));
        if ((board.piece(testLocation) != nullptr && board.piece(testLocation)->getTeam() != WHITE)
            && inBounds(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = this->getLocation();
    }

    // checks for possible 1 space move.
    if (testTeam == BLACK) {
        // checks 1 south
        testLocation.add(Coord(0,1));
        if ((board.piece(testLocation) == nullptr || board.piece(testLocation)->getTeam() != BLACK)
            && inBounds(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = this->getLocation();
    }
    if (testTeam == WHITE) {
        // checks 1 north
        testLocation.add(Coord(0,-1));
        if ((board.piece(testLocation) == nullptr || board.piece(testLocation)->getTeam() != WHITE)
            && inBounds(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = this->getLocation();
    }

    // returns an empty vector if no possible moves exist.
    if (possibleMoves.empty()) {
        return {};
    }

    // returns the possibleMoves vector.
    return possibleMoves;

}

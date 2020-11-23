#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"
#include "../header/Board.hpp"
#include <vector>

/*
 * Pawn chess pieces can only directly forward one square, with two exceptions.
 * Pawns can move directly forward two squares on their first move only.
 * Pawns can move diagonally forward when capturing an opponent's chess piece.
 * Once a pawn chess piece reaches the other side of the chess board, the player may "trade" the pawn in
 * for any other chess piece if they choose, except another king.
 */
class Board;

std::vector<Coord *> Pawn::possibleMoves() {
    // STUB for now
    // vector to return.
    std::vector<Coord*> possibleMoves;

    // board instance.
    Board board = Board::get();

    // Current location
    Coord* testLocation = this->getLocation();

    if (firstMove) {
        // Checks if two squares ahead is valid
        testLocation->add(Coord(0,2));
        // Must be either an open space (nullptr) or an enemy piece to be a valid move.
        if (board.piece(*testLocation) == nullptr ||
            board.piece(*testLocation)->getTeam() != this->getTeam()) {
            possibleMoves.push_back(testLocation);
        }

        // Checks if one square ahead is valid
        testLocation->add(Coord(0, -1));
        if (board.piece(*testLocation) == nullptr ||
            board.piece(*testLocation)->getTeam() != this->getTeam()) {
            possibleMoves.push_back(testLocation);
        }

        // Checks for valid diagonal pieces
        testLocation->add(Coord(1, 0));
        if (board.piece(*testLocation) == nullptr ||
            board.piece(*testLocation)->getTeam() != this->getTeam()) {
            possibleMoves.push_back(testLocation);
        }

        testLocation->add(Coord(-2, -1));
        if (board.piece(*testLocation) == nullptr ||
            board.piece(*testLocation)->getTeam() != this->getTeam()) {
            possibleMoves.push_back(testLocation);
        }
        return possibleMoves;
    }
    else {
        // Checks if one square ahead is valid
        testLocation->add(Coord(0, -1));
        if (board.piece(*testLocation) == nullptr ||
            board.piece(*testLocation)->getTeam() != this->getTeam()) {
            possibleMoves.push_back(testLocation);
        }

        // Checks for valid diagonal pieces
        testLocation->add(Coord(1, 0));
        if (board.piece(*testLocation) == nullptr ||
            board.piece(*testLocation)->getTeam() != this->getTeam()) {
            possibleMoves.push_back(testLocation);
        }

        testLocation->add(Coord(-2, -1));
        if (board.piece(*testLocation) == nullptr ||
            board.piece(*testLocation)->getTeam() != this->getTeam()) {
            possibleMoves.push_back(testLocation);
        }
        return possibleMoves;
    }

}
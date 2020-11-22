#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"
#include <vector>

/*
 * Pawn chess pieces can only directly forward one square, with two exceptions.
 * Pawns can move directly forward two squares on their first move only.
 * Pawns can move diagonally forward when capturing an opponent's chess piece.
 * Once a pawn chess piece reaches the other side of the chess board, the player may "trade" the pawn in
 * for any other chess piece if they choose, except another king.
 */
std::vector<Coord *> Pawn::possibleMoves() {
    // STUB for now
    std::vector<Coord*> possibleMoves;

    if (firstMove) {
        // Checks if two squares ahead is valid
        // Checks if one square ahead is valid
        // Checks for valid diagonal pieces
        return possibleMoves;
    }
    else {
        // Checks if one square ahead is valid
        // Checks for valid diagonal pieces
        return possibleMoves;
    }

}
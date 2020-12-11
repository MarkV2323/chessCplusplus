#ifndef FINAL_PROJECT_MVINC006_ZNAPI001_CLUU009_PIECE_HPP
#define FINAL_PROJECT_MVINC006_ZNAPI001_CLUU009_PIECE_HPP
#include <string>
#include <vector>
#include "Coord.hpp"
#include "global.h"

// Interface for Chess Pieces
/*
 * Includes the following:
 * string symbol - This is what the piece will display as on the chess board.
 *
 * int value - This integer is used for scoring, allows a different value to be set for each chess piece.
 *
 * enum Team - This enum holds what team the chess piece belongs to, either WHITE or BLACK.
 *
 * Coord currentLocation - This is where the chess piece is currently located on the chess board.
 *
 * possibleMoves() - This function handles returning locations available for the chess piece to move.
 * It is planned to return an vector with possible valid moves (coordinates) for the chess piece.
 */

class Piece {
private:
    std::string symbol;
    int value;
    enum Team team;
    Coord currentLocation;

protected:
    // Returns true if moving to DST is valid (no friendly piece
    // there, does not put self into check, is in bounds) It does NOT
    // check if the path to this square in unobstructed and assumes it
    // is unobstructed.
    bool moveIsValid(Coord dst);

    // Return valid moves on a path starting at the piece and moving by
    // INCREMENT
    void tryMovesOnRay(std::vector<Coord> &result, Coord increment);

public:
    // Constructor
    Piece() : symbol(" "), value(0), team(BLACK), currentLocation(Coord(0,0)) { }; // DEFAULTS
    Piece(std::string aSymbol, int aValue, enum Team aTeam, Coord aCoord);

    // Destructor
    virtual ~Piece();

    // Non Virtual Functions
    int getValue() const;
    std::string getSymbol();
    enum Team getTeam();
    Coord getLocation();
    void updateLocation(int x, int y);

    // Virtual Functions
    virtual std::vector<Coord> possibleMoves() = 0;

    // Returns coord of piece that should be captured (if there is one
    // there) when moving to dst. For most pieces this is simply DST
    // so the default behavior of this function is to just return dst.
    virtual Coord captureCoord(Coord dst);
    // Returns true if moving this piece to DST would put this piece's
    // own team in checkmate
    bool moveWouldCauseCheckmate(Coord dst);
    virtual bool isPawn();

    // returns true if the piece reached the enemies's side of the
    // board.
    bool reachedEndOfBoard();
};


#endif

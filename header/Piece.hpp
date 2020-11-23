#ifndef FINAL_PROJECT_MVINC006_ZNAPI001_CLUU009_PIECE_HPP
#define FINAL_PROJECT_MVINC006_ZNAPI001_CLUU009_PIECE_HPP
#include <string>
#include <vector>
#include "Coord.hpp"

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

// Define Enum
enum enumTeam {WHITE, BLACK};

class Piece {
private:
    std::string symbol;
    int value;
    enum enumTeam team;
    Coord* currentLocation; // aStub for now.

public:
    // Constructor
    Piece() : symbol(" "), value(0), team(BLACK), currentLocation(nullptr) { }; // DEFAULTS
    Piece(std::string aSymbol, int aValue, enum enumTeam aTeam, Coord* aCoord);

    // Destructor
    ~Piece();

    // Non Virtual Functions
    int getValue() const;
    std::string getSymbol();
    enum enumTeam getTeam();
    Coord* getLocation();
    void updateLocation(int x, int y);

    // Virtual Functions
    virtual std::vector<Coord*> possibleMoves() = 0;

};


#endif

#ifndef __BOARD_H__
#define __BOARD_H__

#include "Coord.hpp"
#include "Draw.hpp"
#include "Piece.hpp"
#include "Player.hpp"
#include "Timer.hpp"

#include <vector>

enum Direction {UP, DOWN, LEFT, RIGHT};

class Board {
private:
    // These are private so that Board can properly update graphics when they change
    Piece *board[8][8] = {{nullptr}};
    Coord cursor_ = Coord(0, 0);
    std::vector<Coord> highlightedSquares_;

    void drawSquare(const Coord &c, enum BorderType border);
    void drawCursor();
    void eraseCursor();

    Piece** pieceSlot(Coord);
    Board() = default;

public:
    Board(const Board&) = delete;

    // Returns the singleton instance
    static Board& get();

    // Creates an NCurses session, taking over the terminal and
    // drawing a chess board. This needs to be called before the board
    // is used for anything else.
    void initNCurses();
    // Deletes all Pieces, resets member variables to initial states,
    // and destroys the NCurses session.
    void reset();

    // Removes all pieces from the board, deleting them.
    void clearBoard();

    // Moves the cursor one square, wrapping around the board if the edge is reached
    void moveCursor(enum Direction);
    // Returns the current cursor position
    Coord cursor();

    void highlightedSquares(std::vector<Coord>);
    const std::vector<Coord>& highlightedSquares();

    // Properly deletes the piece at LOC, freeing its used memory
    void maybeRemovePiece(Coord loc);
    // Sets the piece at LOC to P. Does not delete the piece at loc if
    // there is one.
    void placePiece(Piece* p, Coord loc);
    Piece* piece(Coord loc);

    bool isInCheck(enum Team team);
    bool canMakeMove(enum Team team);

    void drawTick();
};

#endif //__BOARD_H__

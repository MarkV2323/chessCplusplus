#include "../header/Board.hpp"
#include "../header/Coord.hpp"
#include "../header/Draw.hpp"
#include "../header/Piece.hpp"

#include <algorithm>
#include <array>
#include <iostream>

// Graphics

void Board::drawSquare(const Coord &c, enum BorderType border) {
    ::drawSquare(piece(c), c, border);
}

void Board::eraseCursor() {
    eraseBorder(cursor_);
    if (std::find(highlightedSquares_.begin(),
                  highlightedSquares_.end(),
                  cursor_)
        != highlightedSquares_.end())
        // The square with the cursor is highlighted. Make sure to restore its highlighting.
        drawSquare(cursor_, HIGHLIGHTED);
}

void Board::drawCursor() {
    drawSquare(cursor_, CURSOR);
}

// Board

void Board::reset() {
    Piece **b = (Piece**)board;
    for (int i = 0; i < 8*8; ++i)
        if (b[i]) delete b[i];
    bzero(b, 8*8*sizeof(*b));
    cursor_ = Coord(0,0);
    highlightedSquares_.clear();
    cleanupNCurses();
}

// sets all pieces on the board to nullptrs.
void Board::clearBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete piece(Coord(j, i));
            placePiece(nullptr, Coord(j, i));
        }
    }
}

void Board::moveCursor(enum Direction dir) {
    eraseCursor();
    switch(dir) {
    case UP: cursor_.addWrapped(Coord(0,-1)); break;
    case DOWN: cursor_.addWrapped(Coord(0,1)); break;
    case LEFT: cursor_.addWrapped(Coord(-1,0)); break;
    case RIGHT: cursor_.addWrapped(Coord(1,0)); break;
    }
    drawCursor();
}

Coord Board::cursor() {
    return cursor_;
}

void Board::highlightedSquares(std::vector<Coord> v) {
    for (auto c: highlightedSquares_)
        eraseBorder(c);
    highlightedSquares_ = std::move(v);
    for (auto c: highlightedSquares_)
        drawSquare(c, HIGHLIGHTED);
    // cursor may have been erased or covered up; redraw
    drawCursor();
}

const std::vector<Coord>& Board::highlightedSquares() {
    return highlightedSquares_;
}

Board& Board::get() {
    static Board board;
    return board;
}

void Board::placePiece(Piece *p, Coord loc) {
    if (p != nullptr) {
        p->updateLocation(loc.x, loc.y);
    }
    board[loc.y][loc.x] = p;
    drawPiece(p, loc);
}

Piece* Board::piece(Coord loc) {
    return board[loc.y][loc.x];
}

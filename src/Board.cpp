#include "../header/Board.hpp"
#include "../header/Coord.hpp"
#include "../header/Draw.hpp"
#include "../header/Piece.hpp"

#include <algorithm>
#include <array>
#include <iostream>

#include <strings.h>

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

Piece** Board::pieceSlot(Coord c) {
    return &(board[c.y][c.x]);
}

Piece* Board::piece(Coord c) {
    return *pieceSlot(c);
}

void Board::maybeRemovePiece(Coord c) {
    Piece **p = pieceSlot(c);
    if (*p) {
        delete *p;
        *p = nullptr;
    }
    drawPiece(nullptr, c);
}

void Board::placePiece(Piece *p, Coord c) {
    Piece **slot = pieceSlot(c);
    if (p != nullptr) {
        p->updateLocation(c.x, c.y);
    }
    *slot = p;
    drawPiece(p, c);
}

bool Board::isInCheck(enum Team team) {
    // TODO: find TEAM's king on the board, check if he is in one of
    // the other team's pieces possibleMoves
    return false;
}

bool Board::canMakeMove(enum Team team) {
    // TODO: go through all of TEAM's pieces on the board, check if
    // any of them return a nonempty possibleMoves    
    return true;
}

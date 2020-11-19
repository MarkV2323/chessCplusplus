#include "Board.hpp"

#include <algorithm>
#include <array>
#include <curses.h>
#include <iostream>

// Graphics

#define NUM_SQUARES 8
#define SQUAREW 5
#define SQUAREH 3

static WINDOW* wsquares[NUM_SQUARES*NUM_SQUARES] = {nullptr};

static WINDOW* getSquare(int i, int j) {
    return wsquares[i*NUM_SQUARES + j];
}

static WINDOW* getSquare(const Coord &c) {
    return getSquare(c.y, c.x);
}

static void drawAllSquares() {
    for (auto square: wsquares) {
        wnoutrefresh(square);
        wrefresh(square);
    }
    doupdate();
}

static bool isBlackSquare(const Coord &c) {
    return ((c.y + c.x) % 2) == 0;
}

static void drawBorder(const Coord &c, bool isCursor) {
    if (isCursor) {
        WINDOW* w = getSquare(c);
        assert(w);
        if (isBlackSquare(c))
            wbkgd(w, COLOR_PAIR(1));
        else
            wbkgd(w, COLOR_PAIR(2));
        box(w, '|', '-');
    } else {
        WINDOW* w = getSquare(c);
        if (isBlackSquare(c))
            wbkgd(w, COLOR_PAIR(3));
        else
            wbkgd(w, COLOR_PAIR(4));
        box(w, '|', '-');
    }
}

static void eraseBorder(const Coord &c) {
    wborder(getSquare(c), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
}

void Board::eraseCursor() {
    eraseBorder(cursor_);
    if (std::find(highlightedSquares_.begin(),
                  highlightedSquares_.end(),
                  cursor_)
        != highlightedSquares_.end())
        // The square with the cursor is highlighted. Make sure to restore its highlighting.
        drawBorder(cursor_, false);
}

void Board::drawCursor() {
    drawBorder(cursor_, true);
}

void Board::initNCurses() {
    initscr();
    //cbreak(); // disable line buffering
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();

    assert(has_colors() == TRUE);
    assert(init_pair(1, COLOR_RED, COLOR_BLACK) != ERR); // red on white square
    assert(init_pair(2, COLOR_RED, COLOR_WHITE) != ERR); // red on black square
    assert(init_pair(3, COLOR_GREEN, COLOR_BLACK) != ERR); // green on white square
    assert(init_pair(4, COLOR_GREEN, COLOR_WHITE) != ERR); // green on black square

    refresh();
    for (int i = 0; i < sizeof(wsquares)/sizeof(wsquares[0]); ++i) {
        wsquares[i] =
            newwin(SQUAREH, SQUAREW, i/NUM_SQUARES*SQUAREH, i%NUM_SQUARES*SQUAREW);
        wbkgd(wsquares[i], COLOR_PAIR((i+i/NUM_SQUARES)%2 + 1));
    }
    drawCursor();
    drawAllSquares();
}

void Board::cleanupNCurses() {
    for (auto square: wsquares)
        delwin(square);
    endwin();
}

void Board::drawTick() {
    //refresh();
    drawAllSquares();

    assert(getch()==ERR);
}

// Board

void Board::moveCursor(enum Direction dir) {
    eraseCursor();
    switch(dir) {
    case UP: cursor_.addWrapped(Coord(0,1)); break;
    case DOWN: cursor_.addWrapped(Coord(0,-1)); break;
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
        drawBorder(c, false);
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

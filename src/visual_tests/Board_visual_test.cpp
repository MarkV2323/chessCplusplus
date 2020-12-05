// Crude visual test of Board.cpp's drawing

#include "../../header/Pawn.hpp"
#include "../../header/Board.hpp"
#include <curses.h>

inline void wait_key_press() {
    while (getch() != 'n');
    while (getch() == 'n');
}

int main() {
    Board &b = Board::get();
    initNCurses();
    Coord c (1,0);
    Pawn *p = new Pawn(WHITE, c);
    b.placePiece(p, c);
    Coord c2 = c+Coord(0,1);
    Pawn *p2 = new Pawn(BLACK, c2);
    b.placePiece(p2, c2);
    Pawn *p3 = new Pawn(BLACK, c);
    b.placePiece(p3, c+Coord(2,0));
    Pawn *p4 = new Pawn(WHITE, c);
    b.placePiece(p4, c2+Coord(2,0));
    std::vector<Coord> hs = {c+Coord(1,0), c2+Coord(1,0)};
    b.highlightedSquares(hs);

    // move cursor over various elements
    drawTick();
    wait_key_press();
    b.moveCursor(RIGHT);
    drawTick();
    wait_key_press();
    b.moveCursor(RIGHT);
    drawTick();
    wait_key_press();
    b.moveCursor(RIGHT);
    drawTick();
    wait_key_press();
    b.moveCursor(RIGHT);
    drawTick();
    wait_key_press();

    // move piece over various elements
    b.placePiece(nullptr, c);
    c.addWrapped(Coord(1,0));
    b.placePiece(p, c);
    drawTick();
    wait_key_press();
    b.placePiece(nullptr, c2);
    c2.addWrapped(Coord(1,0));
    b.placePiece(p2, c2);
    drawTick();
    wait_key_press();

    b.placePiece(nullptr, c);
    c.addWrapped(Coord(1,0));
    b.placePiece(p, c);
    drawTick();
    wait_key_press();
    b.placePiece(nullptr, c2);
    c2.addWrapped(Coord(1,0));
    b.placePiece(p2, c2);
    drawTick();
    wait_key_press();

    b.placePiece(nullptr, c);
    c.addWrapped(Coord(1,0));
    b.placePiece(p, c);
    drawTick();
    wait_key_press();
    b.placePiece(nullptr, c2);
    c2.addWrapped(Coord(1,0));
    b.placePiece(p2, c2);
    drawTick();
    wait_key_press();

    b.placePiece(nullptr, c);
    c.addWrapped(Coord(1,0));
    b.placePiece(p, c);
    b.placePiece(nullptr, c2);
    c2.addWrapped(Coord(1,0));
    b.placePiece(p2, c2);
    drawTick();
    wait_key_press();

    b.reset();
    return 0;
}


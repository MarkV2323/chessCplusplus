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
    b.initNCurses();
    Coord c (1,0);
    Pawn p (WHITE, c);
    b.placePiece(&p, c);
    Coord c2 (1,1);
    Pawn p2 (WHITE, c2);
    b.placePiece(&p2, c2);
    std::vector<Coord> hs = {Coord(2,0), Coord(2,1)};
    b.highlightedSquares(hs);

    // move cursor over various elements
    b.drawTick();
    wait_key_press();
    b.moveCursor(RIGHT);
    b.drawTick();
    wait_key_press();
    b.moveCursor(RIGHT);
    b.drawTick();
    wait_key_press();
    b.moveCursor(RIGHT);
    b.drawTick();
    wait_key_press();

    // move piece over various elements
    b.placePiece(nullptr, c);
    c.addWrapped(Coord(1,0));
    b.placePiece(&p, c);
    b.drawTick();
    wait_key_press();
    b.placePiece(nullptr, c2);
    c2.addWrapped(Coord(1,0));
    b.placePiece(&p2, c2);
    b.drawTick();
    wait_key_press();

    b.placePiece(nullptr, c);
    c.addWrapped(Coord(1,0));
    b.placePiece(&p, c);
    b.drawTick();
    wait_key_press();
    b.placePiece(nullptr, c2);
    c2.addWrapped(Coord(1,0));
    b.placePiece(&p2, c2);
    b.drawTick();
    wait_key_press();

    b.placePiece(nullptr, c);
    c.addWrapped(Coord(1,0));
    b.placePiece(&p, c);
    b.drawTick();
    wait_key_press();
    b.placePiece(nullptr, c2);
    c2.addWrapped(Coord(1,0));
    b.placePiece(&p2, c2);
    b.drawTick();
    wait_key_press();

    b.placePiece(nullptr, c);
    c.addWrapped(Coord(1,0));
    b.placePiece(&p, c);
    b.placePiece(nullptr, c2);
    c2.addWrapped(Coord(1,0));
    b.placePiece(&p2, c2);
    b.drawTick();
    wait_key_press();

    b.cleanupNCurses();
    return 0;
}


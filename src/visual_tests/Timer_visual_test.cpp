// Visual test of drawing Timer

#include "../../header/Draw.hpp"
#include "../../header/Game.hpp"
#include "../../header/Human.hpp"

#include <curses.h>

inline void wait_key_press() {
    while (getch() != 'n');
    while (getch() == 'n');
}

int main() {
    initNCurses();

    Human p1 (WHITE);
    Human p2 (BLACK);
    Game g (p1, p2, 600);

    drawGameInfoTick(g);
    drawTick();
    wait_key_press();

    // make sure that text gets erased/overwritten properly
    Game g1 (p1, p2, 1);
    g1.advanceTurn();
    drawGameInfoTick(g1);
    drawTick();

    wait_key_press();

    cleanupNCurses();
    return 0;
}


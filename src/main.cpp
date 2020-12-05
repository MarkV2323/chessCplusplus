#include "../header/global.h"
#include "../header/Board.hpp"
#include "../header/Draw.hpp"
#include "../header/Game.hpp"
#include "../header/Human.hpp"

int main() {
    Human p1 (WHITE);
    Human p2 (BLACK);
    Game g (p1, p2, 5);
    initNCurses();
    g.runGame();
    cleanupNCurses();
    return 0;
}

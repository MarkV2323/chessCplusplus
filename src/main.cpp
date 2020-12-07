#include "../header/global.h"
#include "../header/Board.hpp"
#include "../header/Draw.hpp"
#include "../header/Game.hpp"
#include "../header/Idiot.hpp"

#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));

    Idiot p1 (WHITE, 1);
    Idiot p2 (BLACK, 2);
    Game g (p1, p2, 20);
    Board &b = Board::get();
    initNCurses();
    b.placeInitialPieces();
    g.runGame();
    cleanupNCurses();
    return 0;
}

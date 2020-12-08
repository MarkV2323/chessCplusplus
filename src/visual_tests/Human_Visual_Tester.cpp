#include "../../header/global.h"
#include "../../header/Board.hpp"
#include "../../header/Draw.hpp"
#include "../../header/Game.hpp"
#include "../../header/Idiot.hpp"
#include "../../header/Human.hpp"

#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));

    // Setup game.
    Human h1 (WHITE);
    Idiot p2 (BLACK, 2);
    Game g (h1, p2, 60);
    Board &b = Board::get();
    initNCurses();
    b.placeInitialPieces();
    g.runGame();

    // cleanup and exit.
    cleanupNCurses();
    return 0;
}

#include "../header/global.h"
#include "../header/Board.hpp"
#include "../header/Draw.hpp"
#include "../header/Game.hpp"
#include "../header/Idiot.hpp"
#include "../header/Human.hpp"
#include "../header/savestrategy.hpp"
#include "../header/csvstrat.hpp"

#include <ctime>
#include <cstdlib>

int main(int argc, char **argv) {
    srand(time(0));

    // Idiot p1 (WHITE, 1);
    // Idiot p2 (BLACK, 2);
    Human p1 (WHITE);
    Human p2 (BLACK);
    Game g (p1, p2, 600);
    Board &b = Board::get();
    initNCurses();
    b.placeInitialPieces();

    if (argc > 1) {
        // // read first argument as filename
        // char *name = argv[1];
        // size_t len = strlen(name);

        // SaveStrategy *s;
        // if (strncmp("csv", name+len-4, 3))
        //     s = new CSVstrat();
        // else if (strncmp("json", name+len-4, 3)) {
        //     std::cout << "JSON not supported yet" << std::endl;
        //     return 1;
        //     // s = new JSONstrat;
        // }

        // s->read(/*name*/);
        // g.move(s->moves);
        // g.set_save_strategy(s);
    }

    g.runGame();
    cleanupNCurses();
    return 0;
}

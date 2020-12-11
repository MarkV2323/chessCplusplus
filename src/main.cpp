#include "../header/global.h"
#include "../header/Board.hpp"
#include "../header/Draw.hpp"
#include "../header/Game.hpp"
#include "../header/Idiot.hpp"
#include "../header/Human.hpp"
#include "../header/savestrategy.hpp"
#include "../header/csvstrat.hpp"
#include "../header/jsonstrat.hpp"

#include <ctime>
#include <cstdlib>

int main(int argc, char **argv) {
    srand(time(0));
    int userInput;
    int userInput2;
    int timePerSide;    
    Player* player1;
    Player* player2;

    cout << "How would you like to start the game? Enter [1] - new game, [2] - load game, [3] - exit" << endl;
    
    do{
        cout << "Input: ";
        cin >> userInput;
    }while(userInput != 1 && userInput != 2 && userInput != 3);

    if(userInput == 1)
    {       
        cout << "[1] - Player VS Player [2] - Player VS AI [3] - AI VS AI" << endl;
        do{
            cout << "Input: ";
            cin >> userInput2;
        }while(userInput2 != 1 && userInput2 != 2 && userInput2 != 3);
        
        if(userInput2 == 1) {
            player1 = new Human(WHITE);
            player2 = new Human(BLACK);    
        }
        else if(userInput2 == 2) {
            player1 = new Human(WHITE);
            player2 = new Idiot(BLACK, 2);
        }
        else{
            player1 = new Idiot(WHITE, 1);
            player2 = new Idiot(BLACK, 1);
        }
    }
    else if(userInput == 2) {
        //loading file 
    }
    else
        return 0;

    
    cout << "Total time per side(seconds): ";
    cin >> timePerSide;

    Game g (*player1, *player2, timePerSide);
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

    enum ExitReason exit_status = g.runGame();
    cleanupNCurses();

    if(exit_status == UserQuit){
        cout << "Game ended because user quit." << endl;
    }
    else if(exit_status == BlackVictory){
        cout << "Black won the chess game." << endl;
    }
    else{
        cout << "White won the chess game." << endl;
    }

    return 0;
}

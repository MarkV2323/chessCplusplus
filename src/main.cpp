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
    int loadFile = 0;
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
        cout << "Load file from: [1] - CSV [2] - JSON" << endl;
        do{
            cout << "Input: ";
            cin >> loadFile;
        }while(loadFile != 1 && loadFile != 2);

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
    else
        return 0;

    
    cout << "Total time per side(seconds): ";
    cin >> timePerSide;

    SaveStrategy *s = nullptr;
    if (loadFile != 0) {
        switch (loadFile) {
        case 1: s = new CSVstrat(); break;
        case 2: s = new JSONstrat(); break;
        default: cout << "Invalid file type" << endl; return 1;
        }
    }
    Game g (*player1, *player2, timePerSide, s);
    Board &b = Board::get();
    initNCurses();
    b.placeInitialPieces();

    if (s) {
        vector<Command> cs;
        s->read(cs);
        g.move(cs);
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

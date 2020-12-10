#ifndef __GAME_H__
#define __GAME_H__

#include "global.h"
#include "command.hpp"
#include "Player.hpp"
#include "Timer.hpp"
#include "savestrategy.hpp"

#include <vector>

enum ExitReason {UserQuit, WhiteVictory, BlackVictory};

class Game {
private:
    Player &player1;
    Timer timer1;
    Player &player2;
    Timer timer2;
    int currentPlayer;
    bool shouldEndGame;
    SaveStrategy* save_strat = nullptr;
    vector<Command> history;
    enum ExitReason exitReason;

    Player& getCurrentPlayer();
    Timer& getCurrentTimer();
    // poll current player for move, decrement timer appropriately,
    // update screen
    void tick();

public:
    Game(Player &p1, Player &p2, int timerStart);
    Game(Player &p1, Player &p2, int timerStart, SaveStrategy *saveStrategy);
    ~Game();

    Player& getPlayer(int number);
    Timer& getTimer(int number);
    enum Team getCurrentTurn();
    void advanceTurn();

    // starts save process
    void save();
    // Human can call this function to end the game
    void setShouldEndGame();


    // Player and game loading should call this function to play a
    // move. It will update the board and check for checkmate/game end
    // and switch it to the other players turn (if they can still make
    // a move)
    void move(Command);
    // play multiple commands
    void move(vector<Command>);
    // call this just before entering the game loop that calls tick
    enum ExitReason runGame();
};

#endif //__GAME_H__

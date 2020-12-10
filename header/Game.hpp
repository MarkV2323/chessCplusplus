#ifndef __GAME_H__
#define __GAME_H__

#include "global.h"
#include "command.hpp"
#include "Player.hpp"
#include "Timer.hpp"
#include "savestrategy.hpp"

class Game {
private:
    Player &player1;
    Timer timer1;
    Player &player2;
    Timer timer2;
    int currentPlayer;
    bool shouldEndGame;
    SaveStrategy* save_strat = nullptr;

    Player& getCurrentPlayer();
    Timer& getCurrentTimer();
    // poll current player for move, decrement timer appropriately,
    // update screen
    void tick();

public:
    Game(Player &p1, Player &p2, int timerStart);

    Player& getPlayer(int number);
    Timer& getTimer(int number);
    enum Team getCurrentTurn();
    void advanceTurn();
    void set_save_strategy(SaveStrategy* save_strat);

    // Player and game loading should call this function to play a
    // move. It will update the board and check for checkmate/game end
    // and switch it to the other players turn (if they can still make
    // a move)
    void move(Command);
    // call this just before entering the game loop that calls tick
    void runGame();
};

#endif //__GAME_H__

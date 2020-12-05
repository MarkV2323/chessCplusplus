#ifndef __GAME_H__
#define __GAME_H__

#include "global.h"
#include "Player.hpp"
#include "Timer.hpp"

class Game {
private:
    Player &player1;
    Timer timer1;
    Player &player2;
    Timer timer2;
    enum Team currentTurn;
public:
    Game(Player &p1, Player &p2, int timerStart): player1(p1), player2(p2), timer1(timerStart), timer2(timerStart), currentTurn(WHITE) {};

    Player& getPlayer(int number) {
        return (number == 0) ? player1 : player2;
    }

    Timer& getTimer(int number) {
        return (number == 0) ? timer1 : timer2;
    }

    enum Team getCurrentTurn() { return currentTurn; }
    void advanceTurn() {
        currentTurn = (currentTurn == WHITE) ? BLACK : WHITE;
    }
};

#endif //__GAME_H__

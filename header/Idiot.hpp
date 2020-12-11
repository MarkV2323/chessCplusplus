#ifndef __IDIOT_H__
#define __IDIOT_H__

#include "global.h"

#include "Player.hpp"
#include "Timer.hpp"

class Idiot: public Player {
private:
    Timer timer;
    int thinkingTime;
    bool isMoving;
public:
    Idiot(enum Team team, int thinkingTimeSeconds):
        Player(team),
        timer(Timer(thinkingTimeSeconds)),
        thinkingTime(thinkingTimeSeconds),
        isMoving(false) {};
    virtual void tick(Game &g);
    virtual void upgradePawn(Game&, Coord pawnCoord);
};

#endif //__IDIOT_H__

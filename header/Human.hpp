#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "global.h"
#include "Player.hpp"
#include "Timer.hpp"

class Human: public Player {

public:
    Human(enum Team team): Player(team){};

    virtual void tick(Game &g);
    virtual void upgradePawn(Game&, Coord pawnCoord);
};

#endif //__HUMAN_H__

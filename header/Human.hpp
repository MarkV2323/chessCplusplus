#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "global.h"
#include "Player.hpp"

class Human: public Player {
public:
    Human(enum Team team): Player(team) {};
    virtual void tick();
};

#endif //__HUMAN_H__

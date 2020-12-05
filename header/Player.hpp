#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "global.h"

class Player {
private:
    enum Team team;
public:
    Player(enum Team team): team(team) {};
    enum Team getTeam() { return team; };
    virtual void tick() = 0;
};

#endif //__PLAYER_H__

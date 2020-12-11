#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "global.h"

#include "Coord.hpp"

class Game;

class Player {
private:
    enum Team team;
public:
    Player(enum Team team): team(team) {};
    enum Team getTeam() { return team; };
    virtual void tick(Game &g) = 0;
    virtual void upgradePawn(Game&, Coord pawnCoord) = 0;
};

#endif //__PLAYER_H__

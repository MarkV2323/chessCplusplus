#ifndef __PAWN_UPGRADE_COMMAND_HPP__
#define __PAWN_UPGRADE_COMMAND_HPP__

#include "global.h"

#include "command.hpp"
#include "Coord.hpp"
#include <iostream>

using namespace std;

enum UpgradePiece {QUEEN, ROOK, KNIGHT, BISHOP};

class PawnUpgradeCommand : public Command {
    private:
    enum UpgradePiece piece;
    enum Team team;

    public:
    PawnUpgradeCommand(Coord s, enum UpgradePiece piece, enum Team team);
    string stringify();
    bool execute();
};

#endif


#include "../header/Idiot.hpp"

#include "../header/Board.hpp"
#include "../header/Game.hpp"
#include "../header/PawnUpgradeCommand.hpp"
#include "../header/command.hpp"

#include <cstdlib>

void Idiot::upgradePawn(Game &g, Coord pawnCoord) {
    PawnUpgradeCommand c (pawnCoord, QUEEN, getTeam());
    g.move(c);
}

void Idiot::tick(Game &g) {
    if (!isMoving) {
        isMoving = true;
        timer = Timer(thinkingTime);
        timer.startTimer();
    }
    else {
        timer.tick();
        if (timer.getTime() <= 0.0) {
            isMoving = false;
            // perform move
            Board &b = Board::get();
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    Piece *p = b.piece(Coord(i,j));
                    if (p && (p->getTeam() == this->getTeam())) {
                        vector<Coord> moves = p->possibleMoves();
                        if (!moves.empty()) {
                            Command c (p->getLocation(), moves[rand() % moves.size()]);
                            g.move(c);
                            if (p->isPawn() && p->reachedEndOfBoard())
                                upgradePawn(g, p->getLocation());
                            return;
                        }
                    }
                }
            }
        }
    }
}

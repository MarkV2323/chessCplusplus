#include "../header/Idiot.hpp"

#include "../header/Board.hpp"
#include "../header/Game.hpp"

#include <cstdlib>

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
                            g.move(Command(p->getLocation(), moves[rand() % moves.size()]));
                            return;
                        }
                    }
                }
            }
        }
    }
}

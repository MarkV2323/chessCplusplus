#include "../header/PawnUpgradeCommand.hpp"

#include "../header/global.h"

#include "../header/Board.hpp"
#include "../header/Queen.hpp"
#include "../header/Rook.hpp"
#include "../header/Bishop.hpp"
#include "../header/Knight.hpp"

PawnUpgradeCommand::PawnUpgradeCommand(Coord s, enum UpgradePiece piece, enum Team team): Command(s, s) {
    this->piece = piece;
    this->team = team;
}

std::string PawnUpgradeCommand::stringify() {
    std::string s;
    s.push_back('a'+source.x);
    s.push_back('1'+source.y);
    return s;
}

bool PawnUpgradeCommand::execute() {
    Board &b = Board::get();
    b.maybeRemovePiece(source);
    Piece *p;
    switch (piece) {
    case QUEEN: p = new Queen(team, source); break;
    case ROOK: p = new Rook(team, source); break;
    case KNIGHT: p = new Knight(team, source); break;
    case BISHOP: p = new Bishop(team, source); break;
    }
    b.placePiece(p, source);
    return false;
}

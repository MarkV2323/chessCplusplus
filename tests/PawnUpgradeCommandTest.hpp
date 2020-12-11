#ifndef __PAWN_UPGRADE_COMMAND_TEST_HPP__
#define __PAWN_UPGRADE_COMMAND_TEST_HPP__

#include "../header/Board.hpp"
#include "../header/Coord.hpp"
#include "../header/Pawn.hpp"
#include "../header/King.hpp"
#include "../header/PawnUpgradeCommand.hpp"

TEST(PawnUpgradeCommandTest, PawnUpgradeCommandTest) { // NOLINT(cert-err58-cpp)
    Board &b = Board::get();
    King *wk = new King(WHITE, Coord(7,7));
    King *bk = new King(BLACK, Coord(0,0));
    Coord co (7,0);
    Pawn *bp = new Pawn(WHITE, co);
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.placePiece(bp, bp->getLocation());
    b.setKings(wk, bk);
    PawnUpgradeCommand c (bp->getLocation(), QUEEN, BLACK);
    c.execute();

    EXPECT_NE(b.piece(co), bp);
    EXPECT_NE(b.piece(co), nullptr);

    b.clearBoard();
}

#endif //__PAWN_UPGRADE_COMMAND_TEST_HPP__

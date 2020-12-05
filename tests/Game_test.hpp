#include "gtest/gtest.h"

#include "../header/global.h"
#include "../header/Game.hpp"
#include "../header/Human.hpp"

TEST(GameTest, AdvanceCurrentTurn) {
    Human p1 (WHITE);
    Human p2 (BLACK);
    Game g (p1, p2, 600);

    EXPECT_EQ(g.getCurrentTurn(), WHITE);
    g.advanceTurn();
    EXPECT_EQ(g.getCurrentTurn(), BLACK);
    g.advanceTurn();
    EXPECT_EQ(g.getCurrentTurn(), WHITE);
}

TEST(GameTest, GetPlayer) {
    Human p1 (WHITE);
    Human p2 (BLACK);
    Game g (p1, p2, 600);

    EXPECT_EQ(&g.getPlayer(0), &p1);
    EXPECT_EQ(&g.getPlayer(1), &p2);
}

TEST(GameTest, GetTimer) {
    Human p1 (WHITE);
    Human p2 (BLACK);
    Game g (p1, p2, 600);

    EXPECT_EQ(g.getTimer(0).getTime(), 600);
    EXPECT_EQ(g.getTimer(1).getTime(), 600);
}

TEST(GameTest, MoveSimpleMoveAndCapture) {
    Human pl1 (WHITE);
    Human pl2 (BLACK);
    Game g (pl1, pl2, 600);
    Board &b = Board::get();

    Coord c0 (0,7);
    Pawn *p0 = new Pawn(WHITE, c0);
    Pawn *p1 = new Pawn(BLACK, c0+Coord(0,-1));
    b.placePiece(p0, p0->getLocation());
    b.placePiece(p1, p1->getLocation());

    Command command (p0->getLocation(), p1->getLocation());
    g.move(command);
    EXPECT_EQ(b.piece(c0), nullptr);
    EXPECT_EQ(b.piece(c0+Coord(0,-1)), p0);

    b.reset();
}

TEST(GameTest, MoveAdvancesTurn) {
    Human pl1 (WHITE);
    Human pl2 (BLACK);
    Game g (pl1, pl2, 600);
    Board &b = Board::get();

    Coord c0 (0,7);
    Pawn *p0 = new Pawn(WHITE, c0);
    Pawn *p1 = new Pawn(BLACK, c0+Coord(0,-1));
    Pawn *p2 = new Pawn(BLACK, Coord(5,5));
    b.placePiece(p0, p0->getLocation());
    b.placePiece(p1, p1->getLocation());
    b.placePiece(p2, p2->getLocation());

    Command command (p0->getLocation(), p1->getLocation());
    g.move(command);
    EXPECT_EQ(g.getCurrentTurn(), BLACK);

    b.reset();
}

// test Game::move for not advancing the turn, declaring checkmate,
// accepting forfeit, pawn upgrade

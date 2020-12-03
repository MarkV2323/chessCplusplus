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

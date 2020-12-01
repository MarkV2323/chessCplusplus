#ifndef FINALPROJECT_KNIGHTTESTS_HPP
#define FINALPROJECT_KNIGHTTESTS_HPP
#include "../header/Knight.hpp"
#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"

// Tests if a new King can be created successfully.
TEST(KnightTest, createNewKnight) { // NOLINT(cert-err58-cpp)
    auto *knight1 = new Knight(WHITE, Coord(2, 3));

    EXPECT_EQ(knight1->getSymbol(), "Kn");
    EXPECT_EQ(knight1->getValue(), 10);
    EXPECT_EQ(knight1->getTeam(), 0);
    EXPECT_EQ(knight1->getLocation().stringify(), "(2,3)");

    auto *knight2 = new Knight(BLACK, Coord(8, 8));

    EXPECT_EQ(knight2->getSymbol(), "Kn");
    EXPECT_EQ(knight2->getValue(), 10);
    EXPECT_EQ(knight2->getTeam(), 1);
    EXPECT_EQ(knight2->getLocation().stringify(), "(8,8)");
}

// Tests if a new King can be created successfully w/ bad Coordinates..
TEST(KnightTest, badNewKnightObj) { // NOLINT(cert-err58-cpp)
    EXPECT_ANY_THROW(new Knight(WHITE, Coord(10, 3)));
    EXPECT_ANY_THROW(new Knight(WHITE, Coord(1, 9)));
    EXPECT_ANY_THROW(new Knight(WHITE, Coord(-1, 3)));
    EXPECT_ANY_THROW(new Knight(WHITE, Coord(1, -3)));
}

// Tests the updateLocation() function for a King.
TEST(KnightTest, updateLocationOfKnight) { // NOLINT(cert-err58-cpp)
    auto *knight1 = new Knight(WHITE, Coord(2, 3));
    knight1->updateLocation(4, 4);
    EXPECT_EQ(knight1->getLocation().stringify(), "(4,4)");
}

#endif //FINALPROJECT_KNIGHTTESTS_HPP

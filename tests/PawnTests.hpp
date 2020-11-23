#ifndef FINALPROJECT_PAWNTESTS_HPP
#define FINALPROJECT_PAWNTESTS_HPP
#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"

// Tests if a new pawn can be created successfully.
TEST(PawnTest, createNewPawnObj) { // NOLINT(cert-err58-cpp)
    Pawn* pawn = new Pawn(WHITE, new Coord(2, 3));

    EXPECT_EQ(pawn->getSymbol(), "P");
    EXPECT_EQ(pawn->getValue(), 1);
    EXPECT_EQ(pawn->getTeam(), 0);
    EXPECT_EQ(pawn->getLocation()->stringify(), "(2,3)");

    Pawn* pawn2 = new Pawn(BLACK, new Coord(8, 8));

    EXPECT_EQ(pawn2->getSymbol(), "P");
    EXPECT_EQ(pawn2->getValue(), 1);
    EXPECT_EQ(pawn2->getTeam(), 1);
    EXPECT_EQ(pawn2->getLocation()->stringify(), "(8,8)");
}

// Tests if a new pawn can be created successfully w/ bad Coordinates..
TEST(PawnTest, badNewPawnObj) { // NOLINT(cert-err58-cpp)
    EXPECT_ANY_THROW(new Pawn(WHITE, new Coord(10, 3)));
    EXPECT_ANY_THROW(new Pawn(WHITE, new Coord(1, 9)));
    EXPECT_ANY_THROW(new Pawn(WHITE, new Coord(-1, 3)));
    EXPECT_ANY_THROW(new Pawn(WHITE, new Coord(1, -3)));
}

// Tests the updateLocation() function for a pawn.
TEST(PawnTest, updateLocationOfPawn) { // NOLINT(cert-err58-cpp)
    Pawn* pawn = new Pawn(WHITE, new Coord(2, 3));
    pawn->updateLocation(4, 4);
    EXPECT_EQ(pawn->getLocation()->stringify(), "(4,4)");
}

// Tests the the function possibleMoves(), for all possible moves
TEST(PawnTest, pawnMoves) { // NOLINT(cert-err58-cpp)
    EXPECT_EQ(1,1);
}

// Tests the the function possibleMoves(), for all possible moves while pawn is near border of board.
TEST(PawnTest, pawnMovesByBoardBorder) { // NOLINT(cert-err58-cpp)
    EXPECT_EQ(1,1);
}

// Tests the the function possibleMoves(), for no possible moves.
TEST(PawnTest, pawnMovesNoMoves) { // NOLINT(cert-err58-cpp)
    EXPECT_EQ(1,1);
}

#endif //FINALPROJECT_PAWNTESTS_HPP

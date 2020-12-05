#ifndef FINALPROJECT_KNIGHTTESTS_HPP
#define FINALPROJECT_KNIGHTTESTS_HPP
#include "../header/Knight.hpp"
#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"

// Tests if a new Knight can be created successfully.
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

// Tests if a new Knight can be created successfully w/ bad Coordinates..
TEST(KnightTest, badNewKnightObj) { // NOLINT(cert-err58-cpp)
    EXPECT_ANY_THROW(new Knight(WHITE, Coord(10, 3)));
    EXPECT_ANY_THROW(new Knight(WHITE, Coord(1, 9)));
    EXPECT_ANY_THROW(new Knight(WHITE, Coord(-1, 3)));
    EXPECT_ANY_THROW(new Knight(WHITE, Coord(1, -3)));
}

// Tests the updateLocation() function for a Knight.
TEST(KnightTest, updateLocationOfKnight) { // NOLINT(cert-err58-cpp)
    auto *knight1 = new Knight(WHITE, Coord(2, 3));
    knight1->updateLocation(4, 4);
    EXPECT_EQ(knight1->getLocation().stringify(), "(4,4)");
}

// Tests the possibleMoves() function for a Knight.
TEST(KnightTest, knightMoves) { // NOLINT(cert-err58-cpp)
    auto *knight1 = new Knight(WHITE, Coord(3, 3));

    std::vector<Coord> knight1Moves = knight1->possibleMoves();

    EXPECT_EQ(knight1Moves.size(), 8);
    EXPECT_EQ(knight1Moves[0].stringify(), "(1,2)");
    EXPECT_EQ(knight1Moves[1].stringify(), "(2,1)");
    EXPECT_EQ(knight1Moves[2].stringify(), "(4,1)");
    EXPECT_EQ(knight1Moves[3].stringify(), "(5,2)");
    EXPECT_EQ(knight1Moves[4].stringify(), "(1,4)");
    EXPECT_EQ(knight1Moves[5].stringify(), "(2,5)");
    EXPECT_EQ(knight1Moves[6].stringify(), "(4,5)");
    EXPECT_EQ(knight1Moves[7].stringify(), "(5,4)");
}

// Tests the possibleMoves() function for a Knight.
TEST(KnightTest, knightMovesByBorder) { // NOLINT(cert-err58-cpp)
    auto *knight1 = new Knight(WHITE, Coord(0, 0));

    std::vector<Coord> knight1Moves = knight1->possibleMoves();

    EXPECT_EQ(knight1Moves.size(), 2);
    EXPECT_EQ(knight1Moves[0].stringify(), "(1,2)");
    EXPECT_EQ(knight1Moves[1].stringify(), "(2,1)");
}

// Tests the possibleMoves() function for a Knight.
TEST(KnightTest, knightMovesByFriendly) { // NOLINT(cert-err58-cpp)
    auto *knight1 = new Knight(WHITE, Coord(0, 0));

    // init board.
    Board &b = Board::get();
    b.clearBoard();

    // place pawns
    auto *pawn1 = new Pawn(WHITE, Coord(1,2));
    auto *pawn2 = new Pawn(BLACK, Coord(2,1));
    b.placePiece(pawn1, pawn1->getLocation());
    b.placePiece(pawn2, pawn2->getLocation());

    std::vector<Coord> knight1Moves = knight1->possibleMoves();

    EXPECT_EQ(knight1Moves.size(), 1);
    EXPECT_EQ(knight1Moves[0].stringify(), "(2,1)");
}

// Tests the possibleMoves() function for a Knight.
TEST(KnightTest, knightNoMoves) { // NOLINT(cert-err58-cpp)
    auto *knight1 = new Knight(WHITE, Coord(0, 0));

    // init board.
    Board &b = Board::get();
    b.clearBoard();

    // place pawns
    auto *pawn1 = new Pawn(WHITE, Coord(1,2));
    auto *pawn2 = new Pawn(WHITE, Coord(2,1));
    b.placePiece(pawn1, pawn1->getLocation());
    b.placePiece(pawn2, pawn2->getLocation());

    std::vector<Coord> knight1Moves = knight1->possibleMoves();

    EXPECT_EQ(knight1Moves.size(), 0);
}

TEST(KnightTest, captureCoord) { // NOLINT(cert-err58-cpp)
    Knight p (WHITE, Coord(0,0));
    Coord d = Coord(1,0);
    EXPECT_EQ(p.captureCoord(d), d);
}

#endif //FINALPROJECT_KNIGHTTESTS_HPP

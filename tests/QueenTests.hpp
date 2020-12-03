#ifndef FINALPROJECT_QUEENTESTS_HPP
#define FINALPROJECT_QUEENTESTS_HPP
#include "../header/Queen.hpp"
#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"

// Tests if a new Queen can be created successfully.
TEST(QueenTest, createNewQueen) { // NOLINT(cert-err58-cpp)
auto *queen1 = new Queen(WHITE, Coord(2, 3));
EXPECT_EQ(queen1->getSymbol(), "Q");
EXPECT_EQ(queen1->getValue(), 50);
EXPECT_EQ(queen1->getTeam(), 0);
EXPECT_EQ(queen1->getLocation().stringify(), "(2,3)");

auto *queen2 = new Queen(BLACK, Coord(8, 8));
EXPECT_EQ(queen2->getSymbol(), "Q");
EXPECT_EQ(queen2->getValue(), 50);
EXPECT_EQ(queen2->getTeam(), 1);
EXPECT_EQ(queen2->getLocation().stringify(), "(8,8)");
}

// Tests if a new Queen can be created successfully w/ bad Coordinates..
TEST(QueenTest, badNewQueenObj) { // NOLINT(cert-err58-cpp)
    EXPECT_ANY_THROW(new Queen(WHITE, Coord(10, 3)));
    EXPECT_ANY_THROW(new Queen(WHITE, Coord(1, 9)));
    EXPECT_ANY_THROW(new Queen(WHITE, Coord(-1, 3)));
    EXPECT_ANY_THROW(new Queen(WHITE, Coord(1, -3)));
}

// Tests the updateLocation() function for a Queen.
TEST(QueenTest, updateLocationOfQueen) { // NOLINT(cert-err58-cpp)
    auto *queen1 = new Queen(WHITE, Coord(2, 3));
    queen1->updateLocation(4, 4);
    EXPECT_EQ(queen1->getLocation().stringify(), "(4,4)");
}

TEST(QueenTest, queenMoves) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    auto *queen1 = new Queen(WHITE, Coord(3, 3));
    std::vector<Coord> queen1Moves = queen1->possibleMoves();

//    for (int i = 0; i < queen1Moves.size(); i++) {
//        std::cout << "Element " << i << ": " << queen1Moves[i].stringify() << "\n";
//    }

    // Tests for correct size on possible moves
    EXPECT_EQ(queen1Moves.size(), 27);
    b.clearBoard();
}

TEST(QueenTest, queenMovesByBorder) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    auto *queen1 = new Queen(WHITE, Coord(0, 0));
    // spawns some enemy pawns
    auto *pawn1 = new Pawn(BLACK, Coord(2,0));
    auto *pawn2 = new Pawn(BLACK, Coord(0,2));
    b.placePiece(pawn1, pawn1->getLocation());
    b.placePiece(pawn2, pawn2->getLocation());

    std::vector<Coord> queen1Moves = queen1->possibleMoves();

    // Tests for correct size on possible moves
    EXPECT_EQ(queen1Moves.size(), 11);
    b.clearBoard();
}

TEST(QueenTest, queenMovesByFriendly) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    auto *queen1 = new Queen(WHITE, Coord(0, 0));
    // spawns some enemy pawns
    auto *pawn1 = new Pawn(WHITE, Coord(2,0));
    auto *pawn2 = new Pawn(WHITE, Coord(0,2));
    b.placePiece(pawn1, pawn1->getLocation());
    b.placePiece(pawn2, pawn2->getLocation());

    std::vector<Coord> queen1Moves = queen1->possibleMoves();

    // Tests for correct size on possible moves
    EXPECT_EQ(queen1Moves.size(), 9);
    b.clearBoard();
}

TEST(QueenTest, noMoves) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    auto *queen1 = new Queen(WHITE, Coord(0, 0));
    // spawns some enemy pawns
    auto *pawn1 = new Pawn(WHITE, Coord(1,0));
    auto *pawn2 = new Pawn(WHITE, Coord(0,1));
    auto *pawn3 = new Pawn(WHITE, Coord(1,1));
    b.placePiece(pawn1, pawn1->getLocation());
    b.placePiece(pawn2, pawn2->getLocation());
    b.placePiece(pawn3, pawn3->getLocation());

    std::vector<Coord> queen1Moves = queen1->possibleMoves();

    // Tests for correct size on possible moves
    EXPECT_EQ(queen1Moves.size(), 0);
    b.clearBoard();
}

TEST(QueenTest, captureCoord) { // NOLINT(cert-err58-cpp)
    Queen p (WHITE, Coord(0,0));
    Coord d = Coord(1,0);
    EXPECT_EQ(p.captureCoord(d), d);
}

#endif //FINALPROJECT_QUEENTESTS_HPP

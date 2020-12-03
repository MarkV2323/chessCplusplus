#ifndef FINALPROJECT_BISHOPTESTS_HPP
#define FINALPROJECT_BISHOPTESTS_HPP
#include "../header/Bishop.hpp"
#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"

// Tests if a new Bishop can be created successfully.
TEST(BishopTest, createNewBishop) { // NOLINT(cert-err58-cpp)
auto *bishop1 = new Bishop(WHITE, Coord(2, 3));
EXPECT_EQ(bishop1->getSymbol(), "B");
EXPECT_EQ(bishop1->getValue(), 25);
EXPECT_EQ(bishop1->getTeam(), 0);
EXPECT_EQ(bishop1->getLocation().stringify(), "(2,3)");

auto *bishop2 = new Bishop(BLACK, Coord(8, 8));
EXPECT_EQ(bishop2->getSymbol(), "B");
EXPECT_EQ(bishop2->getValue(), 25);
EXPECT_EQ(bishop2->getTeam(), 1);
EXPECT_EQ(bishop2->getLocation().stringify(), "(8,8)");
}

// Tests if a new Bishop can be created successfully w/ bad Coordinates..
TEST(BishopTest, badNewBishopObj) { // NOLINT(cert-err58-cpp)
    EXPECT_ANY_THROW(new Bishop(WHITE, Coord(10, 3)));
    EXPECT_ANY_THROW(new Bishop(WHITE, Coord(1, 9)));
    EXPECT_ANY_THROW(new Bishop(WHITE, Coord(-1, 3)));
    EXPECT_ANY_THROW(new Bishop(WHITE, Coord(1, -3)));
}

// Tests the updateLocation() function for a Bishop.
TEST(BishopTest, updateLocationOfBishop) { // NOLINT(cert-err58-cpp)
    auto *bishop1 = new Bishop(WHITE, Coord(2, 3));
    bishop1->updateLocation(4, 4);
    EXPECT_EQ(bishop1->getLocation().stringify(), "(4,4)");
}

TEST(BishopTest, bishopMoves) {
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    auto *bishop1 = new Bishop(WHITE, Coord(3, 3));
    std::vector<Coord> bishop1Moves = bishop1->possibleMoves();
//    for (int i = 0; i < bishop1Moves.size(); i++) {
//        std::cout << "Element " << i << ": " << bishop1Moves[i].stringify() << "\n";
//    }
    // Tests for correct size on possible moves
    EXPECT_EQ(bishop1Moves.size(), 13);
    b.clearBoard();
}

TEST(BishopTest, bishopMovesByBorder) {
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    auto *bishop1 = new Bishop(WHITE, Coord(0, 0));

    auto *pawn2 = new Pawn(BLACK, Coord(4,4));
    b.placePiece(pawn2, pawn2->getLocation());

    std::vector<Coord> bishop1Moves = bishop1->possibleMoves();

    // Tests for correct size on possible moves
    EXPECT_EQ(bishop1Moves.size(), 4);
    b.clearBoard();
}

TEST(BishopTest, bishopMovesByFriendly) {
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    auto *bishop1 = new Bishop(WHITE, Coord(0, 0));

    // places a pawn on the board
    auto *pawn1 = new Pawn(WHITE, Coord(5,5));
    b.placePiece(pawn1, pawn1->getLocation());

    std::vector<Coord> bishop1Moves = bishop1->possibleMoves();

    // Tests for correct size on possible moves
    EXPECT_EQ(bishop1Moves.size(), 4);
    b.clearBoard();
}

TEST(BishopTest, bishopNoMoves) {
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    auto *bishop1 = new Bishop(WHITE, Coord(0, 0));

    // places a pawn on the board
    auto *pawn1 = new Pawn(WHITE, Coord(1,1));
    b.placePiece(pawn1, pawn1->getLocation());

    std::vector<Coord> bishop1Moves = bishop1->possibleMoves();

    // Tests for correct size on possible moves
    EXPECT_EQ(bishop1Moves.size(), 0);
    b.clearBoard();
}

#endif //FINALPROJECT_BISHOPTESTS_HPP

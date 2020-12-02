#ifndef FINALPROJECT_ROOKTESTS_HPP
#define FINALPROJECT_ROOKTESTS_HPP
#include "../header/Rook.hpp"
#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"

// Tests if a new Rook can be created successfully.
TEST(RookTest, createNewRook) { // NOLINT(cert-err58-cpp)
    auto *rook1 = new Rook(WHITE, Coord(2, 3));
    EXPECT_EQ(rook1->getSymbol(), "R");
    EXPECT_EQ(rook1->getValue(), 25);
    EXPECT_EQ(rook1->getTeam(), 0);
    EXPECT_EQ(rook1->getLocation().stringify(), "(2,3)");

    auto *rook2 = new Rook(BLACK, Coord(8, 8));
    EXPECT_EQ(rook2->getSymbol(), "R");
    EXPECT_EQ(rook2->getValue(), 25);
    EXPECT_EQ(rook2->getTeam(), 1);
    EXPECT_EQ(rook2->getLocation().stringify(), "(8,8)");
}

// Tests if a new Rook can be created successfully w/ bad Coordinates..
TEST(RookTest, badNewRookObj) { // NOLINT(cert-err58-cpp)
    EXPECT_ANY_THROW(new Rook(WHITE, Coord(10, 3)));
    EXPECT_ANY_THROW(new Rook(WHITE, Coord(1, 9)));
    EXPECT_ANY_THROW(new Rook(WHITE, Coord(-1, 3)));
    EXPECT_ANY_THROW(new Rook(WHITE, Coord(1, -3)));
}

// Tests the updateLocation() function for a Rook.
TEST(RookTest, updateLocationOfRook) { // NOLINT(cert-err58-cpp)
    auto *rook1 = new Rook(WHITE, Coord(2, 3));
    rook1->updateLocation(4, 4);
    EXPECT_EQ(rook1->getLocation().stringify(), "(4,4)");
}

// Tests the possibleMoves() function for a Rook.
TEST(RookTest, rookMoves) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    auto *rook1 = new Rook(WHITE, Coord(3, 3));
    std::vector<Coord> rook1Moves = rook1->possibleMoves();
//    for (int i = 0; i < rook1Moves.size(); i++) {
//        std::cout << "Element " << i << ": " << rook1Moves[i].stringify() << "\n";
//    }
    // Tests for correct size on possible moves
    EXPECT_EQ(rook1Moves.size(), 14);
    // Tests for northern locations
    EXPECT_EQ(rook1Moves[0].stringify(), "(3,2)");
    EXPECT_EQ(rook1Moves[1].stringify(), "(3,1)");
    EXPECT_EQ(rook1Moves[2].stringify(), "(3,0)");
    // Tests for eastern locations
    EXPECT_EQ(rook1Moves[3].stringify(), "(4,3)");
    EXPECT_EQ(rook1Moves[4].stringify(), "(5,3)");
    EXPECT_EQ(rook1Moves[5].stringify(), "(6,3)");
    EXPECT_EQ(rook1Moves[6].stringify(), "(7,3)");
    // Tests for southern locations
    EXPECT_EQ(rook1Moves[7].stringify(), "(3,4)");
    EXPECT_EQ(rook1Moves[8].stringify(), "(3,5)");
    EXPECT_EQ(rook1Moves[9].stringify(), "(3,6)");
    EXPECT_EQ(rook1Moves[10].stringify(), "(3,7)");
    // Tests for western locations
    EXPECT_EQ(rook1Moves[11].stringify(), "(2,3)");
    EXPECT_EQ(rook1Moves[12].stringify(), "(1,3)");
    EXPECT_EQ(rook1Moves[13].stringify(), "(0,3)");
}

// Tests the possibleMoves() function for a Rook.
TEST(RookTest, rookMovesByBorder) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    // Place rook on the board.
    auto *rook1 = new Rook(WHITE, Coord(1, 1));
    b.placePiece(rook1, rook1->getLocation());

    // place pawns
    auto *pawn1 = new Pawn(BLACK, Coord(4,1));
    auto *pawn2 = new Pawn(BLACK, Coord(1,5));
    b.placePiece(pawn1, pawn1->getLocation());
    b.placePiece(pawn2, pawn2->getLocation());

    std::vector<Coord> rook1Moves = rook1->possibleMoves();

    // Tests for correct size on possible moves
    EXPECT_EQ(rook1Moves.size(), 9);
    // Tests for northern locations
    EXPECT_EQ(rook1Moves[0].stringify(), "(1,0)");
    // Tests for eastern locations
    EXPECT_EQ(rook1Moves[1].stringify(), "(2,1)");
    EXPECT_EQ(rook1Moves[2].stringify(), "(3,1)");
    EXPECT_EQ(rook1Moves[3].stringify(), "(4,1)");
    // Tests for southern locations
    EXPECT_EQ(rook1Moves[4].stringify(), "(1,2)");
    EXPECT_EQ(rook1Moves[5].stringify(), "(1,3)");
    EXPECT_EQ(rook1Moves[6].stringify(), "(1,4)");
    EXPECT_EQ(rook1Moves[7].stringify(), "(1,5)");
    // Tests for western locations
    EXPECT_EQ(rook1Moves[8].stringify(), "(0,1)");
}

// Tests the possibleMoves() function for a Rook.
TEST(RookTest, rookMovesByFriendly) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    // Place rook on the board.
    auto *rook1 = new Rook(WHITE, Coord(1, 1));
    b.placePiece(rook1, rook1->getLocation());

    // place pawns
    auto *pawn1 = new Pawn(BLACK, Coord(4,1));
    auto *pawn2 = new Pawn(WHITE, Coord(1,5));
    b.placePiece(pawn1, pawn1->getLocation());
    b.placePiece(pawn2, pawn2->getLocation());

    std::vector<Coord> rook1Moves = rook1->possibleMoves();

    // Tests for correct size on possible moves
    EXPECT_EQ(rook1Moves.size(), 8);
    // Tests for northern locations
    EXPECT_EQ(rook1Moves[0].stringify(), "(1,0)");
    // Tests for eastern locations
    EXPECT_EQ(rook1Moves[1].stringify(), "(2,1)");
    EXPECT_EQ(rook1Moves[2].stringify(), "(3,1)");
    EXPECT_EQ(rook1Moves[3].stringify(), "(4,1)");
    // Tests for southern locations
    EXPECT_EQ(rook1Moves[4].stringify(), "(1,2)");
    EXPECT_EQ(rook1Moves[5].stringify(), "(1,3)");
    EXPECT_EQ(rook1Moves[6].stringify(), "(1,4)");
    // Tests for western locations
    EXPECT_EQ(rook1Moves[7].stringify(), "(0,1)");
}

// Tests the possibleMoves() function for a Rook.
TEST(RookTest, rookNoMoves) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();
    b.clearBoard();

    // Place rook on the board.
    auto *rook1 = new Rook(WHITE, Coord(1, 1));
    b.placePiece(rook1, rook1->getLocation());

    // place pawns
    auto *pawn1 = new Pawn(WHITE, Coord(1,0));
    auto *pawn2 = new Pawn(WHITE, Coord(2,1));
    auto *pawn3 = new Pawn(WHITE, Coord(1,2));
    auto *pawn4 = new Pawn(WHITE, Coord(0,1));
    b.placePiece(pawn1, pawn1->getLocation());
    b.placePiece(pawn2, pawn2->getLocation());
    b.placePiece(pawn3, pawn3->getLocation());
    b.placePiece(pawn4, pawn4->getLocation());

    std::vector<Coord> rook1Moves = rook1->possibleMoves();

    // Tests for correct size on possible moves
    EXPECT_EQ(rook1Moves.size(), 0);
}

#endif //FINALPROJECT_ROOKTESTS_HPP

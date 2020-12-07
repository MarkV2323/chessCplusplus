#ifndef FINALPROJECT_KINGTESTS_HPP
#define FINALPROJECT_KINGTESTS_HPP
#include "../header/King.hpp"
#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"

#include <algorithm>

// Tests if a new King can be created successfully.
TEST(KingTest, createNewKing) { // NOLINT(cert-err58-cpp)
    King* king1 = new King(WHITE, Coord(2, 3));

    EXPECT_EQ(king1->getSymbol(), "K");
    EXPECT_EQ(king1->getValue(), 100);
    EXPECT_EQ(king1->getTeam(), 0);
    EXPECT_EQ(king1->getLocation().stringify(), "(2,3)");

    King* king2 = new King(BLACK, Coord(8, 8));

    EXPECT_EQ(king2->getSymbol(), "K");
    EXPECT_EQ(king2->getValue(), 100);
    EXPECT_EQ(king2->getTeam(), 1);
    EXPECT_EQ(king2->getLocation().stringify(), "(8,8)");
}

// Tests if a new King can be created successfully w/ bad Coordinates..
TEST(KingTest, badNewKingObj) { // NOLINT(cert-err58-cpp)
    EXPECT_ANY_THROW(new King(WHITE, Coord(10, 3)));
    EXPECT_ANY_THROW(new King(WHITE, Coord(1, 9)));
    EXPECT_ANY_THROW(new King(WHITE, Coord(-1, 3)));
    EXPECT_ANY_THROW(new King(WHITE, Coord(1, -3)));
}

// Tests the updateLocation() function for a King.
TEST(KingTest, updateLocationOfKing) { // NOLINT(cert-err58-cpp)
    King* king1 = new King(WHITE, Coord(2, 3));
    king1->updateLocation(4, 4);
    EXPECT_EQ(king1->getLocation().stringify(), "(4,4)");
}

// Tests the the function possibleMoves(), for all possible moves
TEST(KingTest, kingMoves) { // NOLINT(cert-err58-cpp)

    // init board.
    Board &b = Board::get();

    // Places a white king on the board.
    King *king1 = new King(WHITE, Coord(3, 3));
    b.placePiece(king1, king1->getLocation());

    // Gets possible moves of king1.
    std::vector<Coord> king1Moves = king1->possibleMoves();

    // Goes through the possible moves, ensuring each one is correct.
    EXPECT_EQ(king1Moves.size(),8);
    EXPECT_EQ(king1Moves[0].stringify(),"(2,2)"); // 1 west, 1 north
    EXPECT_EQ(king1Moves[1].stringify(),"(3,2)"); // 1 north
    EXPECT_EQ(king1Moves[2].stringify(),"(4,2)"); // 1 east, 1 north
    EXPECT_EQ(king1Moves[3].stringify(),"(2,3)"); // 1 west
    EXPECT_EQ(king1Moves[4].stringify(),"(4,3)"); // 1 east
    EXPECT_EQ(king1Moves[5].stringify(),"(2,4)"); // 1 west, 1 south
    EXPECT_EQ(king1Moves[6].stringify(),"(3,4)"); // 1 south
    EXPECT_EQ(king1Moves[7].stringify(),"(4,4)"); // 1 east, 1 south

//    for(int i = 0; i < king1Moves.size(); i++) {
//        std::cout << "index " << i << ": " << king1Moves[i].stringify() << "\n";
//    }

    // clears the board.
    b.clearBoard();
}

// Tests the the function possibleMoves(), for all possible moves near chess board border.
TEST(KingTest, kingMovesByBoardBorder) { // NOLINT(cert-err58-cpp)

    // init board.
    Board &b = Board::get();

    // Places a white king on the board.
    King *king1 = new King(WHITE, Coord(0, 3));
    b.placePiece(king1, king1->getLocation());

    // Gets possible moves of king1.
    std::vector<Coord> king1Moves = king1->possibleMoves();

    // Goes through the possible moves, ensuring each one is correct.
    EXPECT_EQ(king1Moves.size(),5);
    EXPECT_EQ(king1Moves[0].stringify(),"(0,2)"); // 1 north
    EXPECT_EQ(king1Moves[1].stringify(),"(1,2)"); // 1 east, 1 north
    EXPECT_EQ(king1Moves[2].stringify(),"(1,3)"); // 1 east
    EXPECT_EQ(king1Moves[3].stringify(),"(0,4)"); // 1 south
    EXPECT_EQ(king1Moves[4].stringify(),"(1,4)"); // 1 east, south

//    for(int i = 0; i < king1Moves.size(); i++) {
//        std::cout << "index " << i << ": " << king1Moves[i].stringify() << "\n";
//    }

    // clears the board.
    b.clearBoard();
}

// Tests the the function possibleMoves(), for all possible moves near Friendly piece.
TEST(KingTest, kingMovesByFriendly) { // NOLINT(cert-err58-cpp)

    // init board.
    Board &b = Board::get();

    // Places a white king on the board.
    King *king1 = new King(WHITE, Coord(0, 0));
    b.placePiece(king1, king1->getLocation());

    // Places a black pawn on the board.
    Pawn *pawn1 = new Pawn(BLACK, Coord(1,0));
    b.placePiece(pawn1, pawn1->getLocation());

    // Places a white pawn on the board.
    Pawn *pawn2 = new Pawn(WHITE, Coord(0,1));
    b.placePiece(pawn2, pawn2->getLocation());

    // Gets possible moves of king1.
    std::vector<Coord> king1Moves = king1->possibleMoves();

    // Goes through the possible moves, ensuring each one is correct.
    EXPECT_EQ(king1Moves.size(),2);
    EXPECT_EQ(king1Moves[0].stringify(),"(1,0)"); // 1 east
    EXPECT_EQ(king1Moves[1].stringify(),"(1,1)"); // 1 east, 1 south

    // clears the board.
    b.clearBoard();
}

// Tests the the function possibleMoves(), for all possible moves
TEST(KingTest, kingNoMoves) { // NOLINT(cert-err58-cpp)

    // init board.
    Board &b = Board::get();
    b.clearBoard();

    // Places a white king on the board.
    King *king1 = new King(WHITE, Coord(0, 0));
    b.placePiece(king1, king1->getLocation());

    // Places a white pawn on the board.
    Pawn *pawn1 = new Pawn(WHITE, Coord(1,0));
    b.placePiece(pawn1, pawn1->getLocation());

    // Places a white pawn on the board.
    Pawn *pawn2 = new Pawn(WHITE, Coord(1,1));
    b.placePiece(pawn2, pawn2->getLocation());

    // Places a white pawn on the board.
    Pawn *pawn3 = new Pawn(WHITE, Coord(0,1));
    b.placePiece(pawn3, pawn3->getLocation());

    // Gets possible moves of king1.
    std::vector<Coord> king1Moves = king1->possibleMoves();

    // Goes through the possible moves, ensuring each one is correct.
    EXPECT_EQ(king1Moves.size(),0);

    // clears the board.
    b.clearBoard();
}

TEST(KingTest, captureCoord) { // NOLINT(cert-err58-cpp)
    King p (WHITE, Coord(0,0));
    Coord d = Coord(1,0);
    EXPECT_EQ(p.captureCoord(d), d);
}

// test that king can't move itself into check
TEST(KingTest, moveSelfIntoCheck) { // NOLINT(cert-err58-cpp)
    Board &b = Board::get();
    King *wk = new King(WHITE, Coord(0,0));
    King *bk = new King(BLACK, Coord(2,0));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.setKings(wk, bk);
    vector<Coord> moves = wk->possibleMoves();
    EXPECT_TRUE(std::find(moves.begin(), moves.end(), Coord(1,0)) == moves.end());
    EXPECT_TRUE(std::find(moves.begin(), moves.end(), Coord(1,1)) == moves.end());
    EXPECT_FALSE(std::find(moves.begin(), moves.end(), Coord(0,1)) == moves.end());
    EXPECT_EQ(moves.size(), 1);
    b.clearBoard();
}

#endif //FINALPROJECT_KINGTESTS_HPP

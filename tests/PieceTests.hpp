#ifndef __PIECE_TEST_HPP__
#define __PIECE_TEST_HPP__

#include "../header/Board.hpp"
#include "../header/Coord.hpp"
#include "../header/Pawn.hpp"
#include "../header/King.hpp"
#include "../header/Rook.hpp"

TEST(PieceTest, MoveWouldCauseCheckmate) {
    Board &b = Board::get();
    King* wk = new King(WHITE, Coord(7, 7));
    King* bk = new King(BLACK, Coord(0, 0));
    Rook* wr = new Rook(WHITE, Coord(5, 7));
    Rook* br = new Rook(BLACK, Coord(0, 7));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.placePiece(wr, wr->getLocation());
    b.placePiece(br, br->getLocation());
    b.setKings(wk, bk);

    EXPECT_TRUE(wr->moveWouldCauseCheckmate(Coord(5, 6))); // move white rook out of way
    EXPECT_FALSE(wr->moveWouldCauseCheckmate(Coord(0, 7))); // capture black rook
    EXPECT_FALSE(wr->moveWouldCauseCheckmate(Coord(6, 7))); // move white rook, still in way
    EXPECT_FALSE(br->moveWouldCauseCheckmate(Coord(0, 6))); // move black rook
    EXPECT_FALSE(br->moveWouldCauseCheckmate(Coord(5, 7))); // capture white rook

    b.clearBoard();
}


// test that Pawn won't allow itself to be moved to a spot that puts
// its own team into check
TEST(PieceTest, pawnMoveSelfIntoCheck) { // NOLINT(cert-err58-cpp)
    Board &b = Board::get();
    King *wk = new King(WHITE, Coord(7,5));
    King *bk = new King(BLACK, Coord(0,0));
    Pawn *wp = new Pawn(WHITE, Coord(5,5));
    Rook *br = new Rook(BLACK, Coord(0,5));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.placePiece(wp, wp->getLocation());
    b.placePiece(br, br->getLocation());
    b.setKings(wk, bk);
    vector<Coord> moves = wp->possibleMoves();
    EXPECT_EQ(moves.size(), 0);
    b.clearBoard();
}

// test that Bishop won't allow itself to be moved to a spot that puts
// its own team into check
TEST(PieceTest, bishopMoveSelfIntoCheck) { // NOLINT(cert-err58-cpp)
    Board &b = Board::get();
    King *wk = new King(WHITE, Coord(7,7));
    King *bk = new King(BLACK, Coord(0,0));
    Bishop *wb = new Bishop(WHITE, Coord(6,7));
    Rook *br = new Rook(BLACK, Coord(0,7));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.placePiece(wb, wb->getLocation());
    b.placePiece(br, br->getLocation());
    b.setKings(wk, bk);
    vector<Coord> moves = wb->possibleMoves();
    EXPECT_EQ(moves.size(), 0);
    b.clearBoard();
}

// test that Rook won't allow itself to be moved to a spot that puts
// its own team into check
TEST(PieceTest, rookMoveSelfIntoCheck) { // NOLINT(cert-err58-cpp)
    Board &b = Board::get();
    King *wk = new King(WHITE, Coord(7,7));
    King *bk = new King(BLACK, Coord(0,0));
    Rook *wb = new Rook(WHITE, Coord(6,7));
    Rook *br = new Rook(BLACK, Coord(0,7));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.placePiece(wb, wb->getLocation());
    b.placePiece(br, br->getLocation());
    b.setKings(wk, bk);
    vector<Coord> expectedMoves = {Coord(0,7), Coord(1,7), Coord(2,7), Coord(3,7), Coord(4,7), Coord(5,7)};
    vector<Coord> moves = wb->possibleMoves();
    EXPECT_EQ(moves.size(), 6);
    while (!expectedMoves.empty()) {
        auto i = std::find(moves.begin(), moves.end(), expectedMoves.back());
        EXPECT_TRUE(i != moves.end());
        expectedMoves.pop_back();
    }

    b.clearBoard();
}

// test that Queen won't allow itself to be moved to a spot that puts
// its own team into check
TEST(PieceTest, queenMoveSelfIntoCheck) { // NOLINT(cert-err58-cpp)
    Board &b = Board::get();
    King *wk = new King(WHITE, Coord(7,7));
    King *bk = new King(BLACK, Coord(0,0));
    Queen *wb = new Queen(WHITE, Coord(6,7));
    Rook *br = new Rook(BLACK, Coord(0,7));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.placePiece(wb, wb->getLocation());
    b.placePiece(br, br->getLocation());
    b.setKings(wk, bk);
    vector<Coord> expectedMoves = {Coord(0,7), Coord(1,7), Coord(2,7), Coord(3,7), Coord(4,7), Coord(5,7)};
    vector<Coord> moves = wb->possibleMoves();
    EXPECT_EQ(moves.size(), 6);
    while (!expectedMoves.empty()) {
        auto i = std::find(moves.begin(), moves.end(), expectedMoves.back());
        EXPECT_TRUE(i != moves.end());
        expectedMoves.pop_back();
    }

    b.clearBoard();
}

// test that knight won't allow itself to be moved to a spot that puts
// its own team into check
TEST(PieceTest, knightMoveSelfIntoCheck) { // NOLINT(cert-err58-cpp)
    Board &b = Board::get();
    King *wk = new King(WHITE, Coord(7,7));
    King *bk = new King(BLACK, Coord(0,0));
    Knight *wb = new Knight(WHITE, Coord(6,7));
    Rook *br = new Rook(BLACK, Coord(0,7));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.placePiece(wb, wb->getLocation());
    b.placePiece(br, br->getLocation());
    b.setKings(wk, bk);
    vector<Coord> moves = wb->possibleMoves();
    EXPECT_EQ(moves.size(), 0);

    b.clearBoard();
}

#endif //__PIECE_TEST_HPP__

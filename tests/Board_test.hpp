#include "gtest/gtest.h"

#include "../header/Board.hpp"
#include "../header/Coord.hpp"
#include "../header/King.hpp"
#include "../header/Pawn.hpp"
#include "../header/Rook.hpp"

TEST(BoardTest, Cursor) {
    Board &b = Board::get();
    Coord expected = b.cursor();
    expected.addWrapped(Coord(0,-1));
    b.moveCursor(UP);
    EXPECT_EQ(expected, b.cursor());
    expected = b.cursor();
    expected.addWrapped(Coord(0,1));
    b.moveCursor(DOWN);
    EXPECT_EQ(expected, b.cursor());
    expected = b.cursor();
    expected.addWrapped(Coord(-1,0));
    b.moveCursor(LEFT);
    EXPECT_EQ(expected, b.cursor());
    expected = b.cursor();
    expected.addWrapped(Coord(1,0));
    b.moveCursor(RIGHT);
    EXPECT_EQ(expected, b.cursor());
}

TEST(BoardTest, HighlightedSquares) {
    Board &b = Board::get();
    Coord a (0,1);
    std::vector<Coord> v = {a, Coord(5,6)};
    b.highlightedSquares(v);
    for (int i = 0; i < v.size(); ++i)
        EXPECT_EQ(b.highlightedSquares()[i], v[i]);

    // test that Board creates its own vector
    v[0] = Coord(7,7);
    EXPECT_EQ(b.highlightedSquares()[0], a);
}

TEST(BoardTest, Pieces) {
    Board &b = Board::get();
    Coord a (0,1);
    Pawn* p = new Pawn();
    std::vector<Coord> v;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            v.push_back(Coord(i,j));

    // board should start empty
    for (auto c: v)
        EXPECT_EQ(b.piece(c), nullptr);
    Coord c = v.back();
    v.pop_back();
    // place a piece
    b.placePiece(p, c);
    EXPECT_EQ(b.piece(c), p);
    for (auto c: v)
        EXPECT_EQ(b.piece(c), nullptr);

    b.reset();
}

TEST(BoardTest, Reset) {
    Board &b = Board::get();
    Pawn *p = new Pawn();
    std::vector<Coord> v;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            v.push_back(Coord(i,j));

    Coord c = v.back();
    v.pop_back();
    // place a piece
    b.placePiece(p, c);
    EXPECT_EQ(b.piece(c), p);
    for (auto c: v)
        EXPECT_EQ(b.piece(c), nullptr);

    b.reset();

    // board should be empty
    for (auto c: v)
        EXPECT_EQ(b.piece(c), nullptr);
    EXPECT_TRUE(b.highlightedSquares().empty());
    EXPECT_EQ(b.cursor(), Coord(0,0));
}

TEST(BoardTest, removePiece) {
    Board &b = Board::get();
    Pawn *p1 = new Pawn();
    Pawn *p2 = new Pawn();
    std::vector<Coord> v;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            v.push_back(Coord(i,j));

    Coord c1 = v.back();
    v.pop_back();
    Coord c2 = v.back();
    v.pop_back();

    // place pieces
    b.placePiece(p1, c1);
    b.placePiece(p2, c2);
    EXPECT_EQ(b.piece(c1), p1);
    EXPECT_EQ(b.piece(c2), p2);
    for (auto c: v)
        EXPECT_EQ(b.piece(c), nullptr);

    // remove one piece
    b.maybeRemovePiece(c2);
    EXPECT_EQ(b.piece(c1), p1);
    EXPECT_EQ(b.piece(c2), nullptr);
    for (auto c: v)
        EXPECT_EQ(b.piece(c), nullptr);

    b.reset();
}

TEST(BoardTest, isInCheck) {
    Board &b = Board::get();
    Coord c (0,0);
    King *wk = new King(WHITE, c);
    King *bk = new King(BLACK, c);
    Rook *wr = new Rook(WHITE, c);
    b.setKings(wk, bk);
    b.placePiece(wk, Coord(0,0));
    b.placePiece(bk, Coord(7,7));
    b.placePiece(wr, Coord(0,7));
    EXPECT_FALSE(b.isInCheck(WHITE));
    EXPECT_TRUE(b.isInCheck(BLACK));

    b.reset();
}

TEST(BoardTest, canMakeMoveEmpty) {
    Board &b = Board::get();

    // can't move on board where you have no pieces
    EXPECT_FALSE(b.canMakeMove(WHITE));
}

TEST(BoardTest, canMakeMoveNoPieces) {
    Board &b = Board::get();

    King *wk = new King(WHITE, Coord(0,0));
    b.placePiece(wk, wk->getLocation());
    // can't move on board where you have no pieces
    EXPECT_FALSE(b.canMakeMove(BLACK));
    EXPECT_TRUE(b.canMakeMove(WHITE));
    b.reset();
}

TEST(BoardTest, canMakeMoveYes) {
    Board &b = Board::get();

    King *wk = new King(WHITE, Coord(0,0));
    King *bk = new King(BLACK, Coord(7,7));
    b.setKings(wk, bk);
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    // can't move on board where you have no pieces
    EXPECT_TRUE(b.canMakeMove(WHITE));
    EXPECT_TRUE(b.canMakeMove(BLACK));
    b.reset();
}

TEST(BoardTest, canMakeMoveNotIntoCheck) {
    // test that you can't move when you would put yourself in check
    Board &b = Board::get();

    King *wk = new King(WHITE, Coord(0,0));
    King *bk = new King(BLACK, Coord(2,0));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.setKings(wk, bk);

    Rook *br = new Rook(BLACK, Coord(7,1));
    b.placePiece(br, br->getLocation());

    EXPECT_FALSE(b.canMakeMove(WHITE));
    EXPECT_TRUE(b.canMakeMove(BLACK));

    b.reset();
}

TEST(BoardTest, canMakeMoveCheckmate) {
    // test that you can't move when you are checkmated
    Board &b = Board::get();

    King *wk = new King(WHITE, Coord(0,0));
    King *bk = new King(BLACK, Coord(2,0));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.setKings(wk, bk);

    Rook *br = new Rook(BLACK, Coord(0,2));
    b.placePiece(br, br->getLocation());

    EXPECT_FALSE(b.canMakeMove(WHITE));

    b.reset();
}

TEST(BoardTest, canMakeMoveOutOfCheck) {
    // test that you can move out of check
    Board &b = Board::get();

    King *wk = new King(WHITE, Coord(0,0));
    King *bk = new King(BLACK, Coord(2,0));
    b.placePiece(wk, wk->getLocation());
    b.placePiece(bk, bk->getLocation());
    b.setKings(wk, bk);

    Rook *br = new Rook(BLACK, Coord(0,1)); // white king captures this rook
    b.placePiece(br, br->getLocation());

    EXPECT_TRUE(b.canMakeMove(WHITE));

    b.reset();
}

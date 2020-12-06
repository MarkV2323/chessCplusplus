#ifndef __PIECE_TEST_HPP__
#define __PIECE_TEST_HPP__

#include "../header/Board.hpp"
#include "../header/Coord.hpp"
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
}

#endif //__PIECE_TEST_HPP__

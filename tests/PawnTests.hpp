#ifndef FINALPROJECT_PAWNTESTS_HPP
#define FINALPROJECT_PAWNTESTS_HPP
#include "../header/Pawn.hpp"
#include "../header/Coord.hpp"

// Tests if a new pawn can be created successfully.
TEST(PawnTest, createNewPawnObj) { // NOLINT(cert-err58-cpp)
    Pawn* pawn = new Pawn(WHITE, Coord(2, 3));

    EXPECT_EQ(pawn->getSymbol(), "P");
    EXPECT_EQ(pawn->getValue(), 1);
    EXPECT_EQ(pawn->getTeam(), 0);
    EXPECT_EQ(pawn->getLocation().stringify(), "(2,3)");

    Pawn* pawn2 = new Pawn(BLACK, Coord(8, 8));

    EXPECT_EQ(pawn2->getSymbol(), "P");
    EXPECT_EQ(pawn2->getValue(), 1);
    EXPECT_EQ(pawn2->getTeam(), 1);
    EXPECT_EQ(pawn2->getLocation().stringify(), "(8,8)");
}

// Tests if a new pawn can be created successfully w/ bad Coordinates..
TEST(PawnTest, badNewPawnObj) { // NOLINT(cert-err58-cpp)
    EXPECT_ANY_THROW(new Pawn(WHITE, Coord(10, 3)));
    EXPECT_ANY_THROW(new Pawn(WHITE, Coord(1, 9)));
    EXPECT_ANY_THROW(new Pawn(WHITE, Coord(-1, 3)));
    EXPECT_ANY_THROW(new Pawn(WHITE, Coord(1, -3)));
}

// Tests the updateLocation() function for a pawn.
TEST(PawnTest, updateLocationOfPawn) { // NOLINT(cert-err58-cpp)
    Pawn* pawn = new Pawn(WHITE, Coord(2, 3));
    pawn->updateLocation(4, 4);
    EXPECT_EQ(pawn->getLocation().stringify(), "(4,4)");
}

// Tests the the function possibleMoves(), for all 4 type possible moves
TEST(PawnTest, pawnMoves) { // NOLINT(cert-err58-cpp)

    // init board.
    Board &b = Board::get();

    // Places a black pawn on the board.
    Pawn p1 (BLACK, Coord(1,1));
    b.placePiece(&p1, p1.getLocation());

    // Places two enemy pawns on the board.
    Pawn badPawn1 (WHITE, Coord(0, 2));
    Pawn badPawn2 (WHITE, Coord(2, 2));
    b.placePiece(&badPawn1, badPawn1.getLocation());
    b.placePiece(&badPawn2, badPawn2.getLocation());

    // Gets possible moves of p1.
    std::vector<Coord> pawn1Moves = p1.possibleMoves();

    // Goes through the possible moves, ensuring each one is correct.
    EXPECT_EQ(pawn1Moves.size(),4);
    EXPECT_EQ(pawn1Moves[0].stringify(),"(1,3)"); // 2 spaces south (first turn)
    EXPECT_EQ(pawn1Moves[1].stringify(),"(2,2)"); // 1 south, 1 east (enemy piece on diagonal)
    EXPECT_EQ(pawn1Moves[2].stringify(),"(0,2)"); // 1 south, 1 west (enemy piece on diagonal)
    EXPECT_EQ(pawn1Moves[3].stringify(),"(1,2)"); // 1 south (normal)

    // clears the board.
    b.clearBoard();
}

// Tests the the function possibleMoves(), for all possible moves while pawn is near border of board.
TEST(PawnTest, pawnMovesByBoardBorder) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();

    // Places a black pawn on the board.
    Pawn p1 (BLACK, Coord(0,1));
    b.placePiece(&p1, p1.getLocation());

    // Places one enemy pawns on the board.
    Pawn badPawn1 (WHITE, Coord(1, 2));
    b.placePiece(&badPawn1, badPawn1.getLocation());

    // Gets possible moves of p1.
    std::vector<Coord> pawn1Moves = p1.possibleMoves();

    // Goes through the possible moves, ensuring each one is correct.
    EXPECT_EQ(pawn1Moves.size(),3);
    EXPECT_EQ(pawn1Moves[0].stringify(),"(0,3)"); // 2 spaces south (first turn)
    EXPECT_EQ(pawn1Moves[1].stringify(),"(1,2)"); // 1 south, 1 east (enemy piece on diagonal)
    EXPECT_EQ(pawn1Moves[2].stringify(),"(0,2)"); // 1 south (normal)

    // clears the board.
    b.clearBoard();
}

// Tests the the function possibleMoves(), for all possible moves while pawn is near a friendly piece.
TEST(PawnTest, pawnMovesByFriendly) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();

    // Places a black pawn on the board.
    Pawn p1 (BLACK, Coord(1,1));
    b.placePiece(&p1, p1.getLocation());

    // Places one enemy pawns on the board.
    Pawn badPawn1 (WHITE, Coord(2, 2));
    b.placePiece(&badPawn1, badPawn1.getLocation());

    // Places a two friendly pawns on the board.
    Pawn badPawn2 (BLACK, Coord(1, 2));
    b.placePiece(&badPawn2, badPawn2.getLocation());
    Pawn badPawn3 (BLACK, Coord(1, 3));
    b.placePiece(&badPawn3, badPawn3.getLocation());

    // Gets possible moves of p1.
    std::vector<Coord> pawn1Moves = p1.possibleMoves();

    // Goes through the possible moves, ensuring each one is correct.
    EXPECT_EQ(pawn1Moves.size(),1);
    EXPECT_EQ(pawn1Moves[0].stringify(),"(2,2)"); // 1 south, 1 east (enemy piece on diagonal)

    // clears the board.
    b.clearBoard();
}

// Tests the the function possibleMoves(), for no possible moves.
TEST(PawnTest, pawnMovesNoMoves) { // NOLINT(cert-err58-cpp)
    // init board.
    Board &b = Board::get();

    // Places a black pawn on the board.
    Pawn p1 (BLACK, Coord(1,1));
    b.placePiece(&p1, p1.getLocation());

    // Places a two friendly pawns on the board.
    Pawn badPawn2 (BLACK, Coord(1, 2));
    b.placePiece(&badPawn2, badPawn2.getLocation());
    Pawn badPawn3 (BLACK, Coord(1, 3));
    b.placePiece(&badPawn3, badPawn3.getLocation());

    // Gets possible moves of p1.
    std::vector<Coord> pawn1Moves = p1.possibleMoves();

    // Goes through the possible moves, ensuring each one is correct.
    EXPECT_EQ(pawn1Moves.size(),0);

    // clears the board.
    b.clearBoard();
}

#endif //FINALPROJECT_PAWNTESTS_HPP

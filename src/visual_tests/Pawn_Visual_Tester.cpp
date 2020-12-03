#include <curses.h>
#include <iostream>
#include "../../header/Board.hpp"
#include "../../header/Pawn.hpp"
#include "../../header/King.hpp"
#include "../../header/Knight.hpp"

// Pause Function (n to continue)
inline void wait_key_press() {
    while (getch() != 'n');
    while (getch() == 'n');
}

// Cursor Move Function (arrow keys to move, x to exit)
inline void move_cursor(Board &b) {
    bool online_loop = true;
    // Loops cursor input unless x is pressed.
    while (online_loop) {
        switch (getch()) {
            case KEY_UP:
                b.moveCursor(UP);
                b.drawTick();
                continue;
            case KEY_LEFT:
                b.moveCursor(LEFT);
                b.drawTick();
                continue;
            case KEY_DOWN:
                b.moveCursor(DOWN);
                b.drawTick();
                continue;
            case KEY_RIGHT:
                b.moveCursor(RIGHT);
                b.drawTick();
                continue;
            case 'x':
                online_loop = false;
                b.drawTick();
                break;
            default:
                // Nothing happens if no arrow keys are pressed.
                continue;
        }
        // End while loop.
    }
    // End move_cursor method
}

// Main Method
int main() {

    // Init and build chess board.
    Board &b = Board::get();
    b.initNCurses();

    // Places a black pawn on the board.
    Pawn *p1 = new Pawn(BLACK, Coord(1,1));
    b.placePiece(p1, p1->getLocation());

    // Places a white pawn on the board.
    Pawn *p2 = new Pawn(WHITE, Coord(1,6));
    b.placePiece(p2, p2->getLocation());

    // Places enemy pawns on board to check possible diagonal moves.
    Pawn *badPawn1 = new Pawn(BLACK, Coord(0, 5));
    Pawn *badPawn2 = new Pawn(BLACK, Coord(2, 5));
    Pawn *badPawn3 = new Pawn(WHITE, Coord(0, 2));
    Pawn *badPawn4 = new Pawn(WHITE, Coord(2, 2));
    b.placePiece(badPawn1, badPawn1->getLocation());
    b.placePiece(badPawn2, badPawn2->getLocation());
    b.placePiece(badPawn3, badPawn3->getLocation());
    b.placePiece(badPawn4, badPawn4->getLocation());

    // Places another black pawn on the board.
    Pawn *p3 = new Pawn(BLACK, Coord(5,2));
    b.placePiece(p3, p3->getLocation());

    // Places another black pawn on the board.
    Pawn *p4 = new Pawn(WHITE, Coord(5,5));
    b.placePiece(p4, p4->getLocation());

    // Places enemy pawns on board to check possible diagonal moves.
    Pawn *badPawn5 = new Pawn(WHITE, Coord(6, 3));
    Pawn *badPawn6 = new Pawn(BLACK, Coord(4, 4));
    b.placePiece(badPawn5, badPawn5->getLocation());
    b.placePiece(badPawn6, badPawn6->getLocation());

    // Showcases some invalid moves (being at the end of the board for example, or blocked by friendly piece.)
    Pawn *p5 = new Pawn(WHITE, Coord(6,0));
    b.placePiece(p5, p5->getLocation());
    Pawn *p6 = new Pawn(WHITE, Coord(6,1));
    b.placePiece(p6, p6->getLocation());

    // Highlights possible moves of both pawns. (merges both possibleMoves into one vector)
    std::vector<Coord> possibleMoves;
    std::vector<Coord> pawn1Moves = p1->possibleMoves();
    std::vector<Coord> pawn2Moves = p2->possibleMoves();
    std::vector<Coord> pawn3Moves = p3->possibleMoves();
    std::vector<Coord> pawn4Moves = p4->possibleMoves();
    std::vector<Coord> pawn5Moves = p5->possibleMoves();
    std::vector<Coord> pawn6Moves = p6->possibleMoves();

    possibleMoves.reserve(pawn1Moves.size() + pawn2Moves.size() + pawn3Moves.size() + pawn4Moves.size()
    + pawn5Moves.size() + pawn6Moves.size());
    possibleMoves.insert(possibleMoves.end(), pawn1Moves.begin(), pawn1Moves.end());
    possibleMoves.insert(possibleMoves.end(), pawn2Moves.begin(), pawn2Moves.end());
    possibleMoves.insert(possibleMoves.end(), pawn3Moves.begin(), pawn3Moves.end());
    possibleMoves.insert(possibleMoves.end(), pawn4Moves.begin(), pawn4Moves.end());
    possibleMoves.insert(possibleMoves.end(), pawn5Moves.begin(), pawn5Moves.end());
    possibleMoves.insert(possibleMoves.end(), pawn6Moves.begin(), pawn6Moves.end());
    b.highlightedSquares(possibleMoves);

    // Updates and draws board.
    b.drawTick();

    // Lets user move cursor on the board.
    move_cursor(b);

    // clears the board & highlighted squares. (example of what clearing the board completely)
    b.clearBoard();
    b.highlightedSquares({});

    // Adds a knight & king to the board w/ display of possibleMoves.
    auto knight1 = new Knight(WHITE, Coord(3,3));
    auto king1 = new King(WHITE, Coord(6,6));
    b.placePiece(knight1, knight1->getLocation());
    b.placePiece(king1, king1->getLocation());
    possibleMoves.clear();
    std::vector<Coord> knight1Moves = knight1->possibleMoves();
    std::vector<Coord> king1Moves = king1->possibleMoves();
    possibleMoves.reserve(knight1Moves.size() + king1Moves.size());
    possibleMoves.insert(possibleMoves.end(), knight1Moves.begin(), knight1Moves.end());
    possibleMoves.insert(possibleMoves.end(), king1Moves.begin(), king1Moves.end());
    b.highlightedSquares(possibleMoves);

    // updates the board
    b.drawTick();

    // Lets user move cursor on the board.
    move_cursor(b);

    // clears the board & highlighted squares. (example of what clearing the board completely)
    b.clearBoard();
    b.highlightedSquares({});

    // updates the board
    b.drawTick();
    
    // Lets user move cursor on the board.
    move_cursor(b);

    // Cleanup and exit.
    b.reset();
    return 0;
}

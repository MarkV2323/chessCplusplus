#include "../header/Human.hpp"
#include "../header/Board.hpp"
#include "../header/Game.hpp"

#include <algorithm>
#include <curses.h>
#include <iostream>
#include <cstdlib>

// Global for object.
bool markedPiece = false;
Coord markedLocation(-1,-1); // null value for markedLocation is (-1,-1)
vector<Coord> markedPositions;

// Highlight PossibleMove at current piece Function
inline void highlight_current_piece(Board &b) {
    // gets current coords, checks if a piece is at these coords.
    if (b.piece(b.cursor()) != nullptr && !markedPiece) {
        if (b.piece(b.cursor())->possibleMoves().empty()) {
            b.highlightedSquares({});
        } else {
            b.highlightedSquares(b.piece(b.cursor())->possibleMoves());
        }
    } else {
        if (markedPiece) {
            // does nothing
        } else {
            // clears highlighting
            b.highlightedSquares({});
        }
    }
}

// Cursor Move Function (arrow keys to move, x to exit)
inline void move_cursor(Board &b, Game &g, enum Team team) {

    switch (getch()) {
        case 'x':
            // a marked piece exists
            if (markedPiece) {
                // checks if the cursor is currently at a valid move.
                if (std::find(markedPositions.begin(), markedPositions.end(), b.cursor()) != markedPositions.end()) {
                    // performs move
                    g.move(Command(markedLocation, b.cursor()));
                    // resets marking variables
                    markedPiece = false;
                    highlight_current_piece(b);
                    drawTick();
                } else {
                    // not at a valid position, will reset the marking variables.
                    markedPiece = false;
                    highlight_current_piece(b);
                    drawTick();
                }
            }
            // a marked piece does not exist.
            else {
                // checks if the user is allowed to select this piece.
                if (b.piece(b.cursor()) != nullptr) {
                    if (b.piece(b.cursor())->getTeam() == team && !b.piece(b.cursor())->possibleMoves().empty()) {
                        // the user is allowed to select this piece
                        // does the marking procedure.
                        markedPiece = true;
                        markedLocation = b.cursor();
                        markedPositions = b.piece(b.cursor())->possibleMoves();
                    }
                }
            }
            // END OF SELECTED PIECE CASE
            break;
        case KEY_UP:
            b.moveCursor(UP);
            highlight_current_piece(b);
            drawTick();
            break;
        case KEY_LEFT:
            b.moveCursor(LEFT);
            highlight_current_piece(b);
            drawTick();
            break;
        case KEY_DOWN:
            b.moveCursor(DOWN);
            highlight_current_piece(b);
            drawTick();
            break;
        case KEY_RIGHT:
            b.moveCursor(RIGHT);
            highlight_current_piece(b);
            drawTick();
            break;
        case 's':
            drawTick();
            highlight_current_piece(b);
            break;
        default:
            // Nothing happens if no arrow keys are pressed.
            break;
    }

    // End move_cursor method
}

/*
 * Need to implement the human function to work as follows:
 *  they should have a tick function that checks for user input but does not wait for user input,
 *  that way if there is none the game loop can proceed to count down the timer and draw it on the screen.
 *  the tick function can call moveCursor and possibleMoves to select a move,
 *  and it should perform the move by calling Game::move with a command object
 */
void Human::tick(Game &g) {
    // gets the board
    Board &b = Board::get();
    // allows player to move cursor
    move_cursor(b, g, this->getTeam());
}

#include "../header/Human.hpp"
#include "../header/Board.hpp"
#include "../header/Game.hpp"

#include <curses.h>
#include <iostream>
#include <cstdlib>

// Highlight PossibleMove at current piece Function
inline void highlight_current_piece(Board &b) {
    // gets current coords, checks if a piece is at these coords.
    if (b.piece(b.cursor()) != nullptr) {
        b.highlightedSquares(b.piece(b.cursor())->possibleMoves());
    } else {
        b.highlightedSquares({});
    }
}

// Cursor Move Function (arrow keys to move, x to exit)
inline void move_cursor(Board &b) {

    switch (getch()) {
        case KEY_ENTER:
            // player has selected a piece to move, will require another
            // keystroke (enter again) in order to finalize the requested move.
            // the cursor must be placed at a valid possibleMove highlighted square else it exits.
            
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
        case 'x':
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
    move_cursor(b);

}

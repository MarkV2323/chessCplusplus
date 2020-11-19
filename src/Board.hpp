#ifndef __BOARD_H__
#define __BOARD_H__

#include "Command.hpp"
#include "Coord.hpp"
#include "Piece.hpp"

#include <vector>

enum Direction {UP, DOWN, LEFT, RIGHT};

class Board {
private:
    // These are private so that Board can properly update graphics when they change
    Coord cursor_ = Coord(0,0);
    std::vector<Coord> highlightedSquares_;

    void drawCursor();
    void eraseCursor();

public:
    Piece *board[8][8] = {nullptr};

    // Returns the singleton instance
    static Board& get();

    void initNCurses();
    void cleanupNCurses();

    // Moves the cursor one square, wrapping around the board if the edge is reached
    void moveCursor(enum Direction);
    // Returns the current cursor position
    Coord cursor();

    void highlightedSquares(std::vector<Coord>);
    const std::vector<Coord>& highlightedSquares();

    void drawTick();
};

#endif //__BOARD_H__

#include "../header/global.h"
#include "../header/Board.hpp"
#include "../header/Draw.hpp"
#include "../header/Game.hpp"

#include <assert.h>
#include <curses.h>

static bool isBlackSquare(const Coord &c) {
    return ((c.y + c.x) % 2) == 0;
}

#define NUM_SQUARES 8
#define SQUAREW 5
#define SQUAREH 3

#ifndef NO_GRAPHICS

static WINDOW *wsquares[NUM_SQUARES * NUM_SQUARES] = {nullptr};
// window where timers and current player's turn are drawn
static WINDOW* gameinfo = nullptr;

// some parts of the info window never need to be redraw, so draw them
// here once
static void initializeGameInfo() {
    gameinfo = newwin(6, 18, 0, NUM_SQUARES*SQUAREW);
    // this text never needs to be redraw, so draw it once in initialization
    mvwaddstr(gameinfo, 0, 0, "White timer:\n\nBlack timer:\n\nIt is      's turn\n");
}

static void drawGameInfo(float whitePlayerTimer, float blackPlayerTimer, enum Team currentTurn) {
    mvwprintw(gameinfo, 1, 0, "%5i", (int) whitePlayerTimer);
    mvwprintw(gameinfo, 3, 0, "%5i", (int) blackPlayerTimer);
    mvwprintw(gameinfo, 4, 6, "%s", (currentTurn == WHITE) ? "White" : "Black");
}

static WINDOW* getSquare(int i, int j) {
    return wsquares[i*NUM_SQUARES + j];
}

static WINDOW* getSquare(const Coord &c) {
    return getSquare(c.y, c.x);
}

static void refreshAllSquares() {
    for (auto square: wsquares) {
        wnoutrefresh(square);
        wrefresh(square);
    }
    doupdate();
}

#endif // NO_GRAPHICS

void eraseBorder(const Coord &c) {
#ifndef NO_GRAPHICS
    wborder(getSquare(c), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
#endif
}

#ifndef NO_GRAPHICS
// Don't call this function directly, call drawSquare to ensure that
// that the Piece's color at this location is not messed up
static void drawBorder(const Coord &c, bool isCursor) {
    if (isCursor) {
        WINDOW* w = getSquare(c);
        if (isBlackSquare(c))
            wbkgd(w, COLOR_PAIR(1));
        else
            wbkgd(w, COLOR_PAIR(2));
        box(w, '|', '-');
    } else {
        WINDOW* w = getSquare(c);
        if (isBlackSquare(c))
            wbkgd(w, COLOR_PAIR(3));
        else
            wbkgd(w, COLOR_PAIR(4));
        box(w, '|', '-');
    }
}
#endif // NO_GRAPHICS

void drawPiece(Piece *p, Coord loc) {
#ifndef NO_GRAPHICS
    WINDOW* w = getSquare(loc);
    // erase current printed symbol
    wmove(w, SQUAREH/2, 1);
    for (int i = 0; i < SQUAREW-2; ++i)
        waddch(w, ' ');
    // insert new symbol
    if (p) {
        if (p->getTeam() == WHITE) {
            if (isBlackSquare(loc)) wattron(w, COLOR_PAIR(1));
            else wattron(w, COLOR_PAIR(2));
        }
        else {
            if (isBlackSquare(loc)) wattron(w, COLOR_PAIR(3));
            else wattron(w, COLOR_PAIR(4));
        }
        mvwaddnstr(w,
                   SQUAREH/2,
                   (SQUAREW-p->getSymbol().size())/2,
                   p->getSymbol().c_str(),
                   p->getSymbol().size());
    }
#endif
}

void drawSquare(Piece *p, const Coord &c, enum BorderType border) {
#ifndef NO_GRAPHICS
    if (border != NONE) drawBorder(c, border==CURSOR);
    //else eraseBorder(c);
    if (p) drawPiece(p, c);
#endif
}

void initNCurses() {
#ifndef NO_GRAPHICS
    initscr();
    //cbreak(); // disable line buffering
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();

    assert(has_colors() == TRUE);
    assert(init_pair(1, COLOR_RED, COLOR_BLACK) != ERR); // white on black square
    assert(init_pair(2, COLOR_RED, COLOR_WHITE) != ERR); // white on white square
    assert(init_pair(3, COLOR_GREEN, COLOR_BLACK) != ERR); // black on black square
    assert(init_pair(4, COLOR_GREEN, COLOR_WHITE) != ERR); // black on white square

    refresh();
    for (int i = 0; i < sizeof(wsquares)/sizeof(wsquares[0]); ++i) {
        wsquares[i] =
            newwin(SQUAREH, SQUAREW, i/NUM_SQUARES*SQUAREH, i%NUM_SQUARES*SQUAREW);
        wbkgd(wsquares[i], COLOR_PAIR((i+i/NUM_SQUARES)%2 + 1));
    }
    // cursor needs to be drawn in its initial position
    drawSquare(nullptr, Board::get().cursor(), CURSOR);
    refreshAllSquares();

    initializeGameInfo();
#endif
}

void cleanupNCurses() {
#ifndef NO_GRAPHICS
    for (auto square: wsquares)
        delwin(square);
    endwin();
#endif
}

void drawGameInfoTick(Game &g) {
#ifndef NO_GRAPHICS
    int t1 = g.getTimer(0).getTime();
    int t2 = g.getTimer(1).getTime();
    if (g.getPlayer(0).getTeam() == BLACK) std::swap(t1, t2);
    ::drawGameInfo(t1, t2, g.getCurrentTurn());
#endif
}

// really just refreshes the screen, drawGameInfoTick needs to be
// called separately
void drawTick() {
#ifndef NO_GRAPHICS
    refreshAllSquares();
    wrefresh(gameinfo);
#endif
}

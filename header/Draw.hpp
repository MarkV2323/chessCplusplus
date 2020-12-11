#ifndef __DRAW_H__
#define __DRAW_H__

#include "Coord.hpp"
#include "Game.hpp"
#include "Piece.hpp"
#include <string>

enum BorderType { NONE, CURSOR, HIGHLIGHTED };

extern void drawMessage(string);

extern void eraseBorder(const Coord &c);
extern void drawSquare(Piece *p, const Coord &c, enum BorderType border);
extern void drawPiece(Piece *p, Coord loc);

extern void initNCurses();
extern void cleanupNCurses();
extern void drawGameInfoTick(Game&);
extern void drawTick();

#endif //__DRAW_H__

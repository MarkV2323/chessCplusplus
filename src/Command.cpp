#include "../header/Coord.hpp"
#include "../header/command.hpp"
#include "../header/Board.hpp"
#include "../header/Piece.hpp"

bool Command::execute() {
    Board &b = Board::get();
    Coord s = source;
    Coord d = destination;
    Piece *p = b.piece(s);
    b.maybeRemovePiece(p->captureCoord(d)); // remove appropriate enemy pieces from the board
    b.placePiece(nullptr, s); // now move p
    b.placePiece(p, d);
    return true;
}

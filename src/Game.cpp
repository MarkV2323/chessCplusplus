#include "../header/Board.hpp"
#include "../header/command.hpp"
#include "../header/Draw.hpp"
#include "../header/Game.hpp"

Game::Game(Player &p1, Player &p2, int timerStart)
    : player1(p1), player2(p2), timer1(timerStart), timer2(timerStart), shouldEndGame(false) {
    currentPlayer = (player1.getTeam() == WHITE) ? 0 : 1;
};

Player& Game::getPlayer(int number) {
    return (number == 0) ? player1 : player2;
}

Timer& Game::getTimer(int number) {
    return (number == 0) ? timer1 : timer2;
}

Player& Game::getCurrentPlayer() {
    return (currentPlayer == 0) ? player1 : player2;
}

Timer& Game::getCurrentTimer() {
    return (currentPlayer == 0) ? timer1 : timer2;
}

enum Team Game::getCurrentTurn() {
    return getCurrentPlayer().getTeam();
}

void Game::advanceTurn() {
    currentPlayer = (currentPlayer + 1) % 2;
}

void Game::move(Command c) {
    // TODO: check command type (forfeit vs actual move vs pawn upgrade)
    // - if forfeit, end game
    // - if pawn upgrade, do pawn upgrade but 
    // - else swap turns, check if player can make move, if not
    //   advance turn again or declare checkmate

    // if forfeit, end game here and return

    // if (command is pawn upgrade)
    //     swap out pawn, (ask user which piece they want to swap in?)
    // else {
    // capture and move pieces
    Board &b = Board::get();
    Coord s = c.getSource();
    Coord d = c.getDestination();
    Piece *p = b.piece(s);
    b.maybeRemovePiece(p->captureCoord(d)); // remove appropriate enemy pieces from the board
    b.placePiece(nullptr, s); // now move p
    b.placePiece(p, d);
    // }

    advanceTurn();
    if (!b.canMakeMove(getCurrentTurn())) {
        if (b.isInCheck(getCurrentTurn()))
            // Checkmate!
            shouldEndGame = true;
        else
            // give control back to other player
            advanceTurn();
    }
    // regardless of whos turn it now is, make sure to prepare the
    // timer
    getCurrentTimer().startTimer();
}

void Game::runGame() {
    getCurrentTimer().startTimer();

    while (!shouldEndGame) {
        // TODO: check for user input asking to save and quit
        tick();
    }
}

void Game::tick() {
    getCurrentPlayer().tick();
    getCurrentTimer().tick();
    if (getCurrentTimer().getTime() <= 0.0)
        shouldEndGame = true;
    drawGameInfoTick(*this);
    drawTick();
}

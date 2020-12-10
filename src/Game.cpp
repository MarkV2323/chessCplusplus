#include "../header/Board.hpp"
#include "../header/command.hpp"
#include "../header/Draw.hpp"
#include "../header/Game.hpp"

#include <vector>

Game::Game(Player &p1, Player &p2, int timerStart)
    : player1(p1), player2(p2), timer1(timerStart), timer2(timerStart), shouldEndGame(false) {
    currentPlayer = (player1.getTeam() == WHITE) ? 0 : 1;
}

Game::Game(Player &p1, Player &p2, int timerStart, SaveStrategy *s)
    : Game(p1, p2, timerStart) {
    save_strat = s  ;
}

Game::~Game() {
    //delete save_strat;
}

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
    history.push_back(c);

    // TODO: check command type (forfeit vs actual move vs pawn upgrade)
    // - if forfeit, end game
    // - if pawn upgrade, do pawn upgrade but 
    // - else swap turns, check if player can make move, if not
    //   advance turn again or declare checkmate

    // if forfeit {
    // exitReason = (getCurrentTurn() == WHITE) ? BlackVictory : WhiteVictory;
    // shouldEndGame = true;
    // return;
    // }

    // if (command is pawn upgrade)
    //     swap out pawn
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
        if (b.isInCheck(getCurrentTurn())) {
            // Checkmate!
            exitReason = (getCurrentTurn() == WHITE) ? BlackVictory : WhiteVictory;
            shouldEndGame = true;
        }
        else
            // give control back to other player
            advanceTurn();
    }
    // regardless of whos turn it now is, make sure to prepare the
    // timer
    getCurrentTimer().startTimer();
}

void Game::move(vector<Command> cs) {
    for (auto c: cs) move(c);
}

void Game::save() {
    // if (save_strat != nullptr) {
    //     save_strat->moves = history;
    //     save_strat->write();
    // }
}

void Game::setShouldEndGame() {
    exitReason = UserQuit;
    shouldEndGame = true;
}

enum ExitReason Game::runGame() {
    getCurrentTimer().startTimer();
    while (!shouldEndGame) tick();
    return exitReason;
}

void Game::tick() {
    getCurrentPlayer().tick(*this);
    getCurrentTimer().tick();
    if (getCurrentTimer().getTime() <= 0.0) {
        exitReason = (getCurrentTurn() == WHITE) ? BlackVictory : WhiteVictory;
        shouldEndGame = true;
    }
    drawGameInfoTick(*this);
    drawTick();
}

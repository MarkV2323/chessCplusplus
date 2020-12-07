#include "../header/Knight.hpp"
#include "../header/Board.hpp"
#include <vector>

// returns a vector of the possible moves.
std::vector<Coord> Knight::possibleMoves() {
    // vector to return.
    std::vector<Coord> possibleMoves;
    Board &board = Board::get();
    Team team = getTeam();
    Coord currentLocation = this->getLocation();
    Coord testLocation = currentLocation;

    // Check Northern Locations (Does 2W,1N -> 1W,2N -> 1E,2N -> 2E,1N)
    testLocation.add(Coord(-2, -1));
    if (moveIsValid(testLocation)) {
        possibleMoves.push_back(testLocation);
    }
    testLocation = currentLocation;
    testLocation.add(Coord(-1, -2));
    if (moveIsValid(testLocation)) {
        possibleMoves.push_back(testLocation);
    }
    testLocation = currentLocation;
    testLocation.add(Coord(1, -2));
    if (moveIsValid(testLocation)) {
        possibleMoves.push_back(testLocation);
    }
    testLocation = currentLocation;
    testLocation.add(Coord(2, -1));
    if (moveIsValid(testLocation)) {
        possibleMoves.push_back(testLocation);
    }
    testLocation = currentLocation;

    // Check Southern Locations (Does 2W,1S -> 1W,2S -> 1E,2S -> 2E,1S)
    testLocation.add(Coord(-2, 1));
    if (moveIsValid(testLocation)) {
        possibleMoves.push_back(testLocation);
    }
    testLocation = currentLocation;
    testLocation.add(Coord(-1, 2));
    if (moveIsValid(testLocation)) {
        possibleMoves.push_back(testLocation);
    }
    testLocation = currentLocation;
    testLocation.add(Coord(1, 2));
    if (moveIsValid(testLocation)) {
        possibleMoves.push_back(testLocation);
    }
    testLocation = currentLocation;
    testLocation.add(Coord(2, 1));
    if (moveIsValid(testLocation)) {
        possibleMoves.push_back(testLocation);
    }
    testLocation = currentLocation;

    // returns an empty vector if no possible moves exist.
    if (possibleMoves.empty()) {
        return {};
    }

    // returns the possibleMoves vector.
    return possibleMoves;

}

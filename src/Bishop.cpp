#include "../header/Bishop.hpp"
#include "../header/Board.hpp"
#include <vector>
#include <iostream>

// in-line function for checking bounds on testLocations.
inline bool inBounds(Coord testCoord) {
    // Checks X
    if (testCoord.x < 0 || testCoord.x > 7) {
        return false;
    }
    // Checks Y
    if (testCoord.y < 0 || testCoord.y > 7) {
        return false;
    }
    // testCoord is within the bounds.
    return true;
}

// in-line function for checking basic principals of available moves
// (null ptr, friendly piece, out of bounds)
inline bool basicCheck(Coord testCoord, Board &board, Team team) {
    if (inBounds(testCoord)) {
        Piece *p = board.piece(testCoord);
        return (p == nullptr) || (p->getTeam() != team);
    }
    return false;
}

// returns a vector of the possible moves.
std::vector<Coord> Bishop::possibleMoves() {
    // vector to return.
    std::vector<Coord> possibleMoves;
    Board &board = Board::get();
    Team team = getTeam();
    Coord currentLocation = this->getLocation();
    Coord testLocation = currentLocation;

    // Checks NorthEAST (negative y direction)
    for (int i = 0; i < currentLocation.y; i++) {
        testLocation.add(Coord(1,-1));
        // Checks if in bounds.
        if (inBounds(testLocation)) {
            // checks if piece is in the way (if it is, must stop here.)
            if (board.piece(testLocation) != nullptr) {
                if (board.piece(testLocation)->getTeam() == team) {
                    // friendly piece, will stop here and not add testLocation to possibleMoves.
                    break;
                } else {
                    // enemy piece, will stop here and add testLocation to possibleMoves.
                    possibleMoves.push_back(testLocation);
                    break;
                }
            } else {
                // location is a nullptr, a valid spot to move to.
                possibleMoves.push_back(testLocation);
            }
        } else {
            // test location is out of bounds, will stop here and not add testLocation to possibleMoves.
            break;
        }
        //std::cout << "N location: " << testLocation.stringify() << "\n";
    }
    testLocation = currentLocation; // reset location

    // Checks SOUTHEast (positive x direction)
    for (int i = 0; i < 7 - currentLocation.x; i++) {
        testLocation.add(Coord(1,1));
        // Checks if in bounds.
        if (inBounds(testLocation)) {
            // checks if piece is in the way (if it is, must stop here.)
            if (board.piece(testLocation) != nullptr) {
                if (board.piece(testLocation)->getTeam() == team) {
                    // friendly piece, will stop here and not add testLocation to possibleMoves.
                    break;
                } else {
                    // enemy piece, will stop here and add testLocation to possibleMoves.
                    possibleMoves.push_back(testLocation);
                    break;
                }
            } else {
                // location is a nullptr, a valid spot to move to.
                possibleMoves.push_back(testLocation);
            }
        } else {
            // test location is out of bounds, will stop here and not add testLocation to possibleMoves.
            break;
        }
        //std::cout << "E location: " << testLocation.stringify() << "\n";
    }
    testLocation = currentLocation; // reset location

    // Checks SouthWEST (positive y direction)
    for (int i = 0; i < 7 - currentLocation.y; i++) {
        testLocation.add(Coord(-1,1));
        // Checks if in bounds.
        if (inBounds(testLocation)) {
            // checks if piece is in the way (if it is, must stop here.)
            if (board.piece(testLocation) != nullptr) {
                if (board.piece(testLocation)->getTeam() == team) {
                    // friendly piece, will stop here and not add testLocation to possibleMoves.
                    break;
                } else {
                    // enemy piece, will stop here and add testLocation to possibleMoves.
                    possibleMoves.push_back(testLocation);
                    break;
                }
            } else {
                // location is a nullptr, a valid spot to move to.
                possibleMoves.push_back(testLocation);
            }
        } else {
            // test location is out of bounds, will stop here and not add testLocation to possibleMoves.
            break;
        }
        //std::cout << "S location: " << testLocation.stringify() << "\n";
    }
    testLocation = currentLocation; // reset location

    // Checks WestNOTH (negative x direction)
    for (int i = 0; i < currentLocation.x; i++) {
        testLocation.add(Coord(-1,-1));
        // Checks if in bounds.
        if (inBounds(testLocation)) {
            // checks if piece is in the way (if it is, must stop here.)
            if (board.piece(testLocation) != nullptr) {
                if (board.piece(testLocation)->getTeam() == team) {
                    // friendly piece, will stop here and not add testLocation to possibleMoves.
                    break;
                } else {
                    // enemy piece, will stop here and add testLocation to possibleMoves.
                    possibleMoves.push_back(testLocation);
                    break;
                }
            } else {
                // location is a nullptr, a valid spot to move to.
                possibleMoves.push_back(testLocation);
            }
        } else {
            // test location is out of bounds, will stop here and not add testLocation to possibleMoves.
            break;
        }
        //std::cout << "W location: " << testLocation.stringify() << "\n";
    }
    testLocation = currentLocation; // reset location

    // returns an empty vector if no possible moves exist.
    if (possibleMoves.empty()) {
        return {};
    }

    // returns the possibleMoves vector.
    return possibleMoves;

}

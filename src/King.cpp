#include "../header/King.hpp"
#include <vector>
#include <iostream>

std::vector<Coord> King::possibleMoves() {
    // vector to return.
    std::vector<Coord> possibleMoves;
    Coord currentLocation = this->getLocation();
    Coord testLocation = currentLocation;

    // checks north.
    for (int i = -1; i < 2; i++) {
        testLocation.add(Coord(i, -1));
        if (moveIsValid(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = currentLocation;
    }

    // checks center.
    for (int i = -1; i < 2; i+=2) {
        testLocation.add(Coord(i, 0));
        if (moveIsValid(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = currentLocation;
    }

    // checks south.
    for (int i = -1; i < 2; i++) {
        testLocation.add(Coord(i, 1));
        if (moveIsValid(testLocation)) {
            possibleMoves.push_back(testLocation);
        }
        testLocation = currentLocation;
    }

    return possibleMoves;

}


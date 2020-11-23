#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "Coord.hpp"
#include <iostream>

using namespace std;

enum enumPiece {};

class Command {
    private:
        Coord source;
        Coord destination;
        enum enumPiece nameOfPiece;

    public:
        string stringify(){
            string output;

            output += source.x;
            output += ",";
            output += source.y;
            output += ",";
            output += destination.x;
            output += ",";
            output += destination.y;
            output += ",";
            output += nameOfPiece;

            return output;
        }
};

#endif


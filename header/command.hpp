#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "Coord.hpp"
#include <iostream>

using namespace std;

class Command {
    private:
        Coord source;
        Coord destination;

    public:
    Command(Coord s, Coord d): source(s), destination(d) {};

        string stringify(){
            char num = '0';
            char sourcexchar = 'a';
            char destxchar = 'a';
            string output;

            for(int i = 0; i < source.x; i++){
                sourcexchar++;
            }

            for(int i = 0; i < destination.x; i++) {
                destxchar++;
            }

            output.push_back(sourcexchar);
            output.push_back(num + source.y);
            output.push_back(destxchar);
            output.push_back(num + destination.y);

            return output;
        }

    Coord getSource() { return source; };
    Coord getDestination() { return destination; };
};

#endif


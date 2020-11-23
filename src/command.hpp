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
        string stringify(){
            char sourcexchar = 'a';
            char destxchar = 'a';
            string output;

            for(int i = 0; i < source.x; i++){
                sourcexchar++;
            }

            for(int i = 0; i < destination.x; i++) {
                destxchar++;
            }

            output = sourcexchar + static_cast<char>(source.y) + destxchar + static_cast<char>(destination.y);

            return output;
        }
};

#endif


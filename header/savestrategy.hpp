#ifndef __SAVESTRATEGY_HPP__
#define __SAVESTRATEGY_HPP__

#include "command.hpp"
#include <iostream>
#include <vector>

using namespace std;

class SaveStrategy {
    public:
        vector<Command> moves;
        SaveStrategy() {};
        
        virtual void read() = 0;
        virtual void write() = 0;
};

#endif

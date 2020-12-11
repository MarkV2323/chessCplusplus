#ifndef __SAVESTRATEGY_HPP__
#define __SAVESTRATEGY_HPP__

#include "command.hpp"
#include <iostream>
#include <vector>

using namespace std;

class SaveStrategy {
    public:
        SaveStrategy() {};
        
        virtual void read(vector<Command> &moves) = 0;
        virtual void write(vector<Command> &moves) = 0;
};

#endif

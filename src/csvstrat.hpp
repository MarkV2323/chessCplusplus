#ifndef __CSVSTRAT_HPP__
#define __CSVSTRAT_HPP__

#include "savestrategy.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class CSVstrat : public SaveStrategy {
    public:
        void write(vector<Command> moves) {
            ofstream file;
            file.open("moves.csv");
            for(int i = 0; i < moves.size(); i++) {
                if (i == moves.size() - 1){
                    file << moves[i].stringify() << endl;
                }
                else{
                    file << moves[i].stringify()<< ", " << endl;
                }
            }
            file.close();
        }
};

#endif

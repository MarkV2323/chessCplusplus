#ifndef __JSONSTRAT_HPP__
#define __JSONSTRAT_HPP__

#include "savestrategy.hpp"
#include <iostream>
#include <fstream>
#include <vector>

class JSONstrat : public SaveStrategy {
    public:
        void write(vector<Command> moves) {
            ofstream file;
            file.open("moves.json");
            for(int i = 0; i < moves.size(); i++) {
                if(i == 0){
                    file << "{\n";
                    file << "\t\"Moves\": [\n";
                }
                if(i == moves.size() - 1){
                    file << "\t {\n\t\t\"move\": \"" << moves[i].stringify() << "\"\n }\n";
                }
                else{
                    file << "\t {\n\t\t\"move\": \"" << moves[i].stringify() << "\"\n },\n";
                }
            }
            file << "\t]\n}";
            file.close();
        }
};

#define

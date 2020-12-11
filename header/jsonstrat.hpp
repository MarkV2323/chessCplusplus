#ifndef __JSONSTRAT_HPP__
#define __JSONSTRAT_HPP__

#include "savestrategy.hpp"
#include <iostream>
#include <fstream>
#include <vector>

class JSONstrat : public SaveStrategy {
    public:
        void read(vector<Command> &moves){
            ifstream file;
            string filename = "moves.json";
            file.open(filename.c_str());
            
        
        }

        void write(vector<Command> &moves) {
            ofstream file;
            string filename = "moves.json";
            file.open(filename.c_str(), fstream::out | fstream::trunc);
            for(int i = 0; i < moves.size(); i++) {
                if(i == 0){
                    file << "{\n";
                    file << "\t\"Moves\": [\n";
                }
                if(i == moves.size() - 1){
                    file << "\t\t{\n\t\t\t\"move\": \"" << moves[i].stringify() << "\"\n\t\t}\n";
                }
                else{
                    file << "\t\t{\n\t\t\t\"move\": \"" << moves[i].stringify() << "\"\n\t\t},\n";
                }
            }
            file << "\t]\n}";
            file.close();
        }
};

#endif

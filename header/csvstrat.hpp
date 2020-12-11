#ifndef __CSVSTRAT_HPP__
#define __CSVSTRAT_HPP__

#include "savestrategy.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class CSVstrat : public SaveStrategy {
    public:
        void read(vector<Command> &moves){
            string input;
            ifstream infile;
            moves.clear();
            infile.open("moves.csv");

            while(!infile.eof()){
                getline(infile, input);
                char sourcex;
                char destx;
                int filesourcex = 0;
                int filesourcey = atoi(&input[1]);
                int filedestx = 0;
                int filedesty = atoi(&input[3]);
                sourcex = input[0];
                destx = input[2];
                
                for(int i = sourcex; i > 'a'; i--){
                    filesourcex++;
                }
                for(int i = destx; i > 'a'; i--){
                    filedestx++;
                }
                
                Coord sourcecoord(filesourcex, filesourcey);
                Coord destcoord(filedestx, filedesty);
                Command infromfile(sourcecoord, destcoord);
                moves.push_back(infromfile);
            }
            moves.pop_back();

            infile.close();
        }

        void write(vector<Command> &moves) {
            fstream file;
            string filename = "moves.csv";
            file.open(filename.c_str(), fstream::out | fstream::trunc);
            for(int i = 0; i < moves.size(); i++) {
                if (i == moves.size() - 1){
                    file << moves[i].stringify() << endl;
                }
                else{
                    file << moves[i].stringify() << ", " << endl;
                }
            }
            file.close();
        }
};

#endif

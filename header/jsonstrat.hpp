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
            string input;
            string filename = "moves.json";
            file.open(filename.c_str());
            moves.clear();
            getline(file, input);
            while(!file.eof()){
                getline(file, input);
                char sourcex;
                char destx;
                int filesourcex = 0;
                int filesourcey = atoi(&input[2]);
                int filedestx = 0;
                int filedesty = atoi(&input[4]);
                sourcex = input[1];
                destx = input[3];
                
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
            file.close();
        }

        void write(vector<Command> &moves) {
            ofstream file;
            string filename = "moves.json";
            file.open(filename.c_str(), fstream::out | fstream::trunc);
            for(int i = 0; i < moves.size(); i++) {
                if(i == 0){
                    file << "[\n";
                }
                if(i == moves.size() - 1){
                    file <<"\"" << moves[i].stringify() << "\"\n";
                }
                else{
                    file << "\"" << moves[i].stringify() << "\",\n";
                }
            }
            file << "]";
            file.close();
        }
};

#endif

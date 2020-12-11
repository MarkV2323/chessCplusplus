#include "gtest/gtest.h"

#include "../header/Coord.hpp"
#include "../header/command.hpp"
#include "../header/savestrategy.hpp"
#include "../header/csvstrat.hpp"
#include "../header/jsonstrat.hpp"
#include <fstream>

TEST(SaveReadStratTestSet, CSV_SaveTest){
    
    SaveStrategy* csv_file = new CSVstrat();
    vector<Command> moves; 
    moves.push_back(Command(Coord(2,3), Coord(5,6)));
    moves.push_back(Command(Coord(3,5), Coord(6,7)));
    moves.push_back(Command(Coord(0,0), Coord(1,2)));
    csv_file->write(moves);
    csv_file->read(moves);
    EXPECT_EQ(moves[0].getSource(), Coord(2,3));
    EXPECT_EQ(moves[0].getDestination(), Coord(5,6));
    EXPECT_EQ(moves[1].getSource(), Coord(3,5));
    EXPECT_EQ(moves[1].getDestination(), Coord(6,7));
    EXPECT_EQ(moves[2].getSource(), Coord(0,0));
    EXPECT_EQ(moves[2].getDestination(), Coord(1,2));
    //EXPECT_EQ(moves[3].getSource(), Coord(0,0));
    //EXPECT_EQ(moves[3].getDestination(), Coord(1,2));
    EXPECT_EQ(moves.size(), 3);
}

TEST(SaveReadStratTestSet, CSV_ReadTest){
    SaveStrategy* csv_file = new CSVstrat(); 
    vector<Command> moves;
    moves.push_back(Command(Coord(2,4), Coord(3,2)));
    moves.push_back(Command(Coord(3,6), Coord(5,1)));
    moves.push_back(Command(Coord(2,7), Coord(1,5)));
    
    csv_file->write(moves);
    
    vector<Command> copymoveset = moves;

    //copymoveset.push_back(csv_file->moves[0]);
    //copymoveset.push_back(csv_file->moves[1]);
    //copymoveset.push_back(csv_file->moves[2]);
    
    csv_file->read(moves);
    
    EXPECT_EQ(copymoveset[0].getSource(), moves[0].getSource());
    EXPECT_EQ(copymoveset[0].getDestination(), moves[0].getDestination());
    EXPECT_EQ(copymoveset[1].getSource(), moves[1].getSource());
    EXPECT_EQ(copymoveset[1].getDestination(), moves[1].getDestination());
    EXPECT_EQ(copymoveset[2].getSource(), moves[2].getSource());
    EXPECT_EQ(copymoveset[2].getDestination(), moves[2].getDestination());
    EXPECT_EQ(copymoveset.size(), moves.size());
}

TEST(SaveReadStratTestSet, JSON_SaveTest){
    SaveStrategy* json_file = new JSONstrat();
    
}

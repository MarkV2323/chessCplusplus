#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <string>

enum Team {WHITE, BLACK};

class Piece {
public:
    std::string symbol;
    enum Team team;
};

#endif //__PIECE_HPP__

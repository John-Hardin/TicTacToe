#pragma once
#include "player.hpp"
#include <array>


class Board {
public:
    Player *playerObj;
    Board();
    Board(Player &&player);
    ~Board();
    enum bEnum {THREE = 3, FIVE = 5, SEVEN = 7};
    void initBoard(enum bEnum B);


 
private:
/*  Player *player;//todo likely not what I want */
    enum RowsAndCols {Rows3 = 3, Cols3 = 3, Rows5 = 5, Cols5 = 5};
    std::array< std::array<char, Rows3 >, Cols3>  _board3;
    std::array< std::array<char, Rows5 >, Cols5>  _board5;

};
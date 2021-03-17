#pragma once
#include "player.hpp"
#include <array>


class Board {
public:
    Player *playerObj;
    Board();
    Board(Player *players);
    ~Board();
    enum bEnum {THREE = 3, FIVE = 5, SEVEN = 7};
    void initBoard(enum Player::swap B);


 
private:
/*  Player *player;//todo likely not what I want */
    enum RowsAndCols {Rows3 = 3, Cols3 = 3, Rows5 = 5, Cols5 = 5, Rows7 = 7, Cols7 = 7};
    std::array< std::array<char, Rows3 >, Cols3>  _board3;
    std::array< std::array<char, Rows5 >, Cols5>  _board5;
    std::array< std::array<char, Rows7 >, Cols7>  _board7;

};
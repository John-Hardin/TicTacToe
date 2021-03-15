#pragma once
#include <array>


class Board {
public:
    Board();
    ~Board();
    void initBoard();


 
private:
    enum RowsAndCols {Rows3 = 3, Cols3 = 3, Rows5 = 5, Cols5 = 5};
    std::array< std::array<char, Rows3 >, Cols3>  _board3;
    std::array< std::array<char, Rows5 >, Cols5>  _board5;
};
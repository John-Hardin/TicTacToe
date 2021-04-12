#pragma once
#include <array>


struct Board {
//constructors, copys, moves, destructors
    Board();  /* todo-- See if init in c-tor here and for player.hpp is correct, or if init should */ 
    ~Board(); /*        be done in a Game function.  Probably remove enums, idk yet. */

//accessors

//mutators

//member variables
private:
    enum bEnum {THREE = 3, FIVE = 5, SEVEN = 7};  
    enum RowsAndCols {Rows3 = 3, Cols3 = 3, Rows5 = 5, Cols5 = 5, Rows7 = 7, Cols7 = 7};
    std::array< std::array<char, Rows3 >, Cols3>  _board3;
    std::array< std::array<char, Rows5 >, Cols5>  _board5;
    std::array< std::array<char, Rows7 >, Cols7>  _board7; 
    /* TODO - April 12, 2021; 7:25am: Likely get rid of this enum stuff until I 
    figure out what a "progamming language" is for and how it works, 
    maybe keep the arrays, because I like arrays, they seem to be easier to work with/make more sense. */

};
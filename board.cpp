#include "board.hpp"
//#include "player.hpp"

#include <iostream>
#include <array>

    Board::Board(){
        
    }
    Board::Board(Player &&player) : playerObj(player&player){  //todo, not using player from board.hpp this way, change this.
        // todo Call initBoard when function is completely writtened'd.
/*         bEnum b;
        initBoard(b); */
    }
    Board::~Board(){

    }
    void Board::initBoard( bEnum B){ //todo create a player array
        //check if 3x3 or 5x5 game

    }

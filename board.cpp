#include "board.hpp"
#include "player.hpp"

#include <iostream>
#include <array>


    Board::Board(Player*){
        // todo Call initBoard when function is completely writtened'd.
        initBoard(Player);
    }
    Board::~Board(){

    }
    void Board::initBoard(Player &PlayerAmount){ //todo create a player array
        //check if 3x3 or 5x5 game
        
        switch (Player::getPlayerAmount())
    }

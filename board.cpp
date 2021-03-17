#include "board.hpp"
#include "player.hpp"

#include <iostream>
#include <array>

    Board::Board(){
        
    }
    Board::Board(Player *players) {  //todo, not using player from board.hpp this way, change this.
        // todo Call initBoard when function is completely writtened'd.
/*         bEnum b;
        initBoard(b); */

        players = playerObj;
        initBoard(players->s);

    }
    Board::~Board(){

    }
    void Board::initBoard( enum Player::swap B){ //todo create a player array
        //check if 3x3 or 5x5 game
        switch (playerObj->getPlayerAmount()){
            case 1:
                std::cout << "TEST : case 1, initBoard"  << std::endl;
                break;
            case 2:
                std::cout << "TEST : case 2, initBoard"  << std::endl;
                break;
            case 3:
                std::cout << "TEST : case 3, initBoard"  << std::endl;
                break;
            case 4:
                std::cout << "TEST : case 4, initBoard"  << std::endl;
                break;
            default:
                std::cout << "TEST : made it to *default case* in initBoard" << std::endl;
                break;
        }
    }

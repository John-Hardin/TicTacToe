#include "game.hpp"
//#include <iostream>


int main(){
    Game game; // TODO - April 10, 2021; 8:02am, use Game c-tor to initialize player_ vector.
    game.run(game.getGameOver() ,game.getPlayerAmountStringForRegex(), game.getPlayerAmount());

    return 0;
}
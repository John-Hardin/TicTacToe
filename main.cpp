#include "game.hpp"
//#include <iostream>


int main(){
    Game game;
    //std::shared_ptr<Game> game = std::make_shared<Player>(&inputone);
    game.run(game.getGameOver(),game.getPlayerAmountStringForRegex(), game.getPlayerAmount(), game.getPlayers());
    //while (!game.getGameOver()){
     //   game.run(game.getGameOver());
    //}

    // std::cout << game.use_count() << std::endl;
    // std::cout << game << std::endl;


    return 0;
}
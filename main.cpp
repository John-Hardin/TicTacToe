#include "game.hpp"
#include <iostream>


int main(){
    Game game;
    while (!game.getGameOver()){
        game.run(game.getGameOver());
    }
    return 0;
}
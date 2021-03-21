
#include "game.hpp"
//#include "board.hpp"
//#include "player.hpp"

#include <iostream>
//#include <array>
//#include <string>



 




int main(){
    Game game;
    while (!game.getGameOver()){
        game.run(game.getGameOver());
    }
    return 0;
}
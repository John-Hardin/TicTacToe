#include "game.hpp"
#include <iostream>
#include <array>
#include <regex>
//#include <string>


Game::Game()
{

}
Game::~Game()
{

}

void Game::run(bool& gO){
    Player player;
    Board board(Player);
    updateGame(gO, Game::board, player);
}
void Game::updateGame(bool& gO, Board &Board, Player &Player){
/*     int i = 0;   //todo delete this test code
    while (i < 3){
        std::string inputString;
        std::getline(std::cin, inputString);
        i++;
    }
    gO = true; */
}

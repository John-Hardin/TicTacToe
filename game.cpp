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
    Player players;
    Board board;
    updateGame(gO, &board, &players);
}
void Game::updateGame(bool& gO, Board *Board, Player *Players){
/*     int i = 0;   //todo delete this test code
    while (i < 3){
        std::string inputString;
        std::getline(std::cin, inputString);
        i++;
    }
    gO = true; */
}

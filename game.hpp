#pragma once
#include <array>
#include "player.hpp"
#include "board.hpp"



class Game { 
public:
    Game();
    ~Game();
    void run(bool& gO);
    void updateGame(bool& gO, Board& Board, Player& Player);
    Player *players;
    Board board;
    int getPlayerAmount(){return playerAmount;}

    std::array<std::string, 4> playerNames {playerOneName, playerTwoName, playerThreeName, playerFourName};
private:
    int playerAmount;
    std::string playerOneName;
    std::string playerTwoName;
    std::string playerThreeName;
    std::string playerFourName;
 
};
#pragma once
#include <vector>
#include "player.hpp"
#include "board.hpp"



class Game { 

    int playerAmount_;
    std::vector<std::string> playerNames_;  //changed to vector 3/21/2021
    std::string playerAmountStringForRegex;
    bool gameOver_;



public:
    Game();
    ~Game();
    void initGame();
    void run(bool gO);
    void updateGame(bool& gO);


    //getter
    int getPlayerAmount(){return playerAmount_;}
    bool getGameOver(){return gameOver_;}

    void setPlayerAmount(std::string playerAmountString);
    void setPlayerNames(std::vector<std::string> &playerNames); //3/20/2021
    std::regex getRegex(unsigned int max_players, std::string numbers_text);
    std::map<int, std::regex> get_regex_map(unsigned int max_players, std::string* numbers_text);




 
};
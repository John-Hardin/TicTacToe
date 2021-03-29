#pragma once
#include <vector>
#include <map>
#include <memory>
#include "board.hpp"
#include "player.hpp"


class Game { 
    int playerAmount_;
    std::vector<std::string> playerNames_;  //changed to vector 3/21/2021
    std::vector<std::shared_ptr<Game>> players_;
    std::string playerAmountStringForRegex_;
    bool gameOver_;
    void updateBoard();
    void printBoard();
    
    std::regex getRegex(unsigned int max_players, std::string *numbers_text);
    std::map<int, std::regex> get_regex_map(unsigned int max_players, std::string* numbers_text);
    void setPlayerAmount(std::string &playerAmountString);
    void setPlayerNames(std::vector<std::string> &playerNames, int& l_playerAmount); //3/20/2021
    

public:
    Game();
    ~Game();
    void initGame();
    void run(bool gO);
    void updateGame(bool& gO);

    void initPlayerObjects(int numPlayers, std::vector<std::shared_ptr<Game>> Players);

    
    int getPlayerAmount(){return playerAmount_;}
    bool getGameOver(){return gameOver_;}


};
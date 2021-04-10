#pragma once
#include <vector>
#include <map>
#include <regex>
#include <memory>
#include "board.hpp"
#include "player.hpp"


class Game { 
    int playerAmount_;
    bool gameOver_ = false;
    std::string playerAmountStringForRegex_;
    //std::unique_ptr<Player> p1, p2, p3, p4;
    void updateBoard();
    void printBoard();
    
    

public:
    Game();
    ~Game();
    void initGame(std::string playerAmountStringForRegex_, int &playerAmount_, std::vector<std::unique_ptr<Player>> players_);
    void run(bool gO,std::string playerAmountStringForRegex_, int &playerAmount_, std::vector<std::unique_ptr<Player>> players_);
    void updateGame(bool& gO);

    void initPlayerObjects(std::string &playerAmountString, int &playerAmount_, std::vector<std::unique_ptr<Player>> players_);

    
    void setPlayerAmount(std::string &playerAmountString);
    
    std::regex getRegex(unsigned int max_players, std::string *numbers_text);
    std::map<int, std::regex> get_regex_map(unsigned int max_players, std::string* numbers_text);
    int& getPlayerAmount(){return playerAmount_;}
    bool getGameOver(){return gameOver_;}
    std::string getPlayerAmountStringForRegex(){return playerAmountStringForRegex_;}
    std::vector<std::unique_ptr<Player>> players_;

};
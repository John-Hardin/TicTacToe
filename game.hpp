#pragma once
#include <vector>
#include <map>
#include <regex>
#include <memory>
#include "board.hpp"
#include "player.hpp"


class Game { 
    int playerAmount_;
    bool gameOver_;
    std::string playerAmountStringForRegex_;
    void updateBoard(std::string &b3);
    void updatePlayers();
    void printBoard(std::string &b3);
    
    

public:
    Game();
    ~Game();
    void run();
    void updateGame(std::string &INPut);
    std::string initBoard();
    void initPlayerObjects();

    
    void setPlayerAmount(std::string &playerAmountString);
    
    std::regex getRegex(unsigned int max_players, std::string *numbers_text);
    std::map<int, std::regex> get_regex_map(unsigned int max_players, std::string* numbers_text);
    int& getPlayerAmount(){return playerAmount_;}
    bool getGameOver(){return gameOver_;}
    std::string getPlayerAmountStringForRegex(){return playerAmountStringForRegex_;}
 
    std::vector<std::unique_ptr<Player>> players_;

};
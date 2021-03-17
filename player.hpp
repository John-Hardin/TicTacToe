#pragma once
#include <string>
#include <regex>
//#include <array>
//#include "board.hpp"


class Player /* : public Board */{
public:
    Player();
    ~Player();
    //getters

    std::regex getRegex(unsigned int max_players, std::string* numbers_text);
    std::map<int, std::regex> get_regex_map(unsigned int max_players, std::string* numbers_text);
    int getPlayerAmount(){return playerAmount;}

    //setters

    //main functions

    int setPlayerAmount(std::string playerAmountString);
    void setPlayerNames(std::vector<std::string> player, Player &player_);



private: 
    Player *player;
    std::string playerAmountString;
    int playerAmount;
    char playerOneSymbol;
    char playerTwoSymbol;
    char playerThreeSymbol;
    char playerFourSymbol;

    std::vector<std::string> playerNames[4];
    std::string playerOneName;
    std::string playerTwoName;
    std::string playerThreeName;
    std::string playerFourName;
    
};
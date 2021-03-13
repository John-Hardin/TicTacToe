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

    //setters

    //main functions
    //void initPlayers();
    int setPlayerAmount(std::string playerAmountString);
    void setPlayerNames();



private:
    int playerAmount;
    char playerOneSymbol;
    char playerTwoSymbol;
    std::string playerAmountString;
    std::regex regex;

    std::string playerOneName;
    std::string playerTwoName;
    
    
};
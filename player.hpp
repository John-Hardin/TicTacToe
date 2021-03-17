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
    enum swap {ZERO, ONE, TWO, THREE, FOUR};// enum for switch statement in setPlayerNames();.
    swap s;
    int setPlayerAmount(std::string playerAmountString);
    void setPlayerNames(enum swap S);



private: 
    std::string playerAmountString;
    int playerAmount;
    char playerOneSymbol;
    char playerTwoSymbol;
    char playerThreeSymbol;
    char playerFourSymbol;

    std::string playerOneName;
    std::string playerTwoName;
    std::string playerThreeName;
    std::string playerFourName;
    
};
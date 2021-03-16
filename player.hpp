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
    void setPlayerNames();



private: 
    enum swap {ZERO, ONE, TWO, THREE, FOUR} s;// enum for switch statement in setPlayerNames();.
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
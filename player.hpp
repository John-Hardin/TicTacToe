#pragma once
#include <string>
#include <regex>
#include <array>
//#include "board.hpp"
#include "game.hpp"

class Player /* : public Board */{
public:
    Player();
    ~Player();
    //getters

    std::regex getRegex(unsigned int max_players, std::string* numbers_text);
    std::map<int, std::regex> get_regex_map(unsigned int max_players, std::string* numbers_text);


    //setters

    //main functions

    //TODO- move this function to Game class.
    int setPlayerAmount(std::string playerAmountString);
    void setPlayerNames(std::array<std::string, 4> player, Game &game);



private:
    std::string playerAmountString;

    char playerOneSymbol;
    char playerTwoSymbol;
    char playerThreeSymbol;
    char playerFourSymbol;



    
};
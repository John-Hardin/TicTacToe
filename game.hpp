#pragma once
#include <array>
#include "player.hpp"
#include "board.hpp"



class Game { 

    int *playerAmount;
    std::array<std::string, 4> *playerNames;
    std::string playerAmountStringForRegex;



public:
    Game();
    ~Game();
    void initGame();
    void run(bool& gO);
    void updateGame(bool& gO);


    //getter
    int getPlayerAmount(){return *playerAmount;}

    int setPlayerAmount(std::string playerAmountString);
    void setPlayerNames(std::array<std::string, 4> playerNames, Game &game); //3/20/2021
    std::regex getRegex(unsigned int max_players, std::string numbers_text);
    std::map<int, std::regex> get_regex_map(unsigned int max_players, std::string* numbers_text);




 
};
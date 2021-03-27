#pragma once
#include <string>
#include <regex>
#include <array>
//#include "board.hpp"
//#include "game.hpp"

class Player /* : public Board */{
    
    std::string name_; //3/20/2021
    char symbol_;
    int playerNumber_;

public:
    Player();
    ~Player();

    
    //getters-start
    std::string getName(){return name_;}
    char getSymbol(){return symbol_;}
    int getNumber(){return playerNumber_;}
    //getters-end


    //setters-start
    void setSymbol(Player &p){symbol_ = p.symbol_;}
    void setNumber(Player &p){playerNumber_ = p.playerNumber_;}
    //setters-end


    //main functions

};
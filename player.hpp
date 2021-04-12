#pragma once
#include <string>
#include <iostream>



struct Player
{   
//constructors, copys, moves, destructors
    Player();
    Player( std::string _N, char _S){ std::cout << "Player is created : " << _N << " with symbol " << _S << std::endl; name_ = _N; symbol_ = _S; }
    Player(Player&&) = default;
    ~Player(){ std::cout << "Player " << name_ << " is destroyed." << std::endl; }
//accessors
    std::string getName(){return name_;}
    char getSymbol(){return symbol_;}
//mutators
    void setName(std::string _N){name_ = _N;}
    void setSymbol(char _S){symbol_ = _S;}
//member variables
private:
    std::string name_;
    char symbol_;
};

#pragma once
#include <string>
#include <iostream>



struct Player
{
    Player( std::string _N, char _S){ std::cout << "Player is created : " << _N << " with symbol " << _S << std::endl; name_ = _N; symbol_ = _S; }
    //Player(){ std::cout << "Nameless player created." << std::endl; name_ = "nameless"; symbol_ = '?'; }
    ~Player(){ std::cout << "Player " << name_ << " is destroyed." << std::endl; }
    void sayName() { std::cout << "Player " << name_ << " rules!" << std::endl; }
    std::string getName(){return name_;}
//private:
    std::string name_;
    char symbol_;
};

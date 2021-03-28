#pragma once
#include <string>

struct Player{
    Player(std::string _n, char _s) : name (_n), symbol (_s){}
    ~Player();
    std::string name;
    char symbol;
};

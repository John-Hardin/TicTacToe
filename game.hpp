#pragma once
#include <array>
#include "player.hpp"
#include "board.hpp"



class Game { 
public:
    Game();
    ~Game();
    void run(bool& gO);
    void updateGame(bool& gO, Board& Board, Player& Player);
    Player player;
    Board board;

 
};
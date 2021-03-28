#pragma once
#include <memory>
#include "board.hpp"
#include "player.hpp"


class Game { 
    int playerAmount_;
    std::vector<std::string> playerNames_;  //changed to vector 3/21/2021
    std::vector<std::shared_ptr<Game>> players_;
    std::string playerAmountStringForRegex_;
    bool gameOver_;
    void updateBoard();
    //Player playerObj;
    
    
//std::vector<std::shared_ptr<Game>> players, Player& playerObj

public:
    Game();
    /* Game(std::vector<std::shared_ptr<Game>> vecOfPlayerPtrs, Game pObj); */ //commented out 3/27/2021.
    ~Game();
    void initGame();
    void run(bool gO);
    void updateGame(bool& gO);

    void initPlayerObjects(int numPlayers, std::vector<std::shared_ptr<Game>> Players);

    //getter
    int getPlayerAmount(){return playerAmount_;}
    bool getGameOver(){return gameOver_;}

    void setPlayerAmount(std::string &playerAmountString);
    void setPlayerNames(std::vector<std::string> &playerNames, int& l_playerAmount); //3/20/2021
    std::regex getRegex(unsigned int max_players, std::string *numbers_text);
    std::map<int, std::regex> get_regex_map(unsigned int max_players, std::string* numbers_text);

};
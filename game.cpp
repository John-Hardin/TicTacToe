#include "game.hpp"
#include <iostream>
#include <vector>
#include <regex>
//#include <string>




Game::Game(std::vector<std::shared_ptr<Game>> vecOfPlayerPtrs, Player& pObj) : players (vecOfPlayerPtrs), playerObj (pObj)
{    
    gameOver_ = false;

}
Game::~Game()
{

}
void Game::initGame(){
    initPlayerObjects(playerAmount_, players);
    setPlayerAmount(playerAmountStringForRegex);
    std::cout << "TEST IN INITGAME(){} 1 : playerAmountStringForRegex is : " << playerAmountStringForRegex << std::endl;
    setPlayerNames(playerNames_, playerAmount_);
}

void Game::run(bool gO){
    // change to init game function Player player; //test 12:24pm
    
    initGame();
    updateGame(gameOver_); //TODO -- may need to pass bool by reference here, somehow, & didn't work.
}

void Game::updateGame(bool& gO){
    //TODO -- need to add game loop here/game logic/while loop;3/21/2021 time stamp.

    while(gO){
        updateBoard();
    }
}
void Game::updateBoard(){}
void Game::setPlayerAmount(std::string &playerAmountString){ 
    const unsigned int max_players = 4;
    std::string numbers_text[] = {"one", "two", "three", "four"};
    std::map<int, std::regex> conversion_table = get_regex_map(max_players, numbers_text); 
    std::regex regex = getRegex(max_players, numbers_text);
    std::cout << "Enter (1) Player or (2) Players?" << std::endl;
    
    std::cin >> playerAmountString;
    
// validate input and set number of players in a variable.
    while (!std::cin.fail()){ 

        if (!std::regex_match(playerAmountString, regex)){
            std::cout << "Input not recognized." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            setPlayerAmount(playerAmountStringForRegex);
        }
        else {
            for(auto &el: conversion_table){ 
                    if(std::regex_match(playerAmountString, el.second)){
                        std::cout << "Number of players selected is : " << el.first << std::endl;
                        playerAmount_ = el.first;
                        std::cout << "TEST 1 : playerAmount_ is : " << playerAmount_ << std::endl;
                    }

                } return; // todo figure out a better way to write this; maybe without cin.fail(), and the return. 
        }

    }


}   

void Game::setPlayerNames(std::vector<std::string> &playerNames, int& l_playerAmount){ //todo -- Look into "std::unique_ptr<T[]>" instead of vector.
    /* int l_playerAmount; */
    l_playerAmount = getPlayerAmount();
    std::cout << "TEST 1 : getPlayerAmount() is : " << getPlayerAmount() << std::endl;
    std::cout << "TEST 2 : l_playerAmount = " << l_playerAmount << std::endl;
    std::string pName;

    for (int i = 1; i <= l_playerAmount; i++){  //TODO -- Look into "std::unique_ptr<T[]>" instead of vector.
        std::cout << "Enter player " << i << "'s name : " << std::endl;
        std::cin >> pName;
        playerNames.emplace_back(pName);
        std::cout << "TEST 3 : vector playerNames.back() is : " << playerNames.back() << std::endl;
        std::cout << "TEST 4 : pName is : " << pName << std::endl;
    }


}

void Game::initPlayerObjects(int numPlayers, std::vector<std::shared_ptr<Game>> vecOfPlayerPtrs){
    // init player objects
        for(int i = 0; i <= numPlayers; i++){
            std::shared_ptr<Game> sPtrGame = std::make_shared<Game>();
            vecOfPlayerPtrs.emplace_back(sPtrGame);
            std::cout << "TEST : sPtrGame is : " << sPtrGame << std::endl;
        }
        for (auto el: vecOfPlayerPtrs){
            std::cout << "TEST 2 : el: vecOfPlayers is : " << el << std::endl;
        }      
        std::cout << "TEST 3 : returning from Game::initPlayerObjects(int numPlayers, std::vector<std::shared_ptr<Game>> Players){ }" << std::endl;  
        return;
/*     for (int i=0; i <= playerAmount_; i++){
        std::unique_ptr<Player> Players;
        player.emplace_back(Players.get());
        std::cout << "TEST: &player[i] is : " << &Players << std::endl;

    } */
}

std::regex Game::getRegex(unsigned int max_players, std::string *numbers_text){
    std::stringstream ss;
    ss << "[1-";
    ss << max_players;
    std::cout << "TEST : max_players is " << max_players << std::endl;
    ss << "]";

    for (unsigned int i = 0; i < max_players; i++){
        ss << "|";
        ss << numbers_text[i];
    }
    std::string s = "";
    ss >> s;
    std::cout << "TEST 2 : s is : " << s << std::endl;
    std::regex regex(s, std::regex::icase);
    return regex;
}

std::map<int, std::regex> Game::get_regex_map(unsigned int max_players, std::string* numbers_text){
    std::map<int, std::regex> convert_table;
    for(unsigned int i = 0; i < max_players; i++){
        std::string s = numbers_text[i] + "|" + std::to_string(i+1);
        std::cout << "TEST 3 : std::string s = numbers_text[i] + \"|\" + std::to_string(i+1); is : " << s << std::endl;
        std::regex r(s, std::regex::icase);
        convert_table[i+1] = r;
    }
    return convert_table;
}
#include "game.hpp"
#include <iostream>
#include <vector>
#include <regex>
//#include <string>


Game::Game()
{
    gameOver_ = false;
    initGame();

}
Game::~Game()
{

}
void Game::initGame(){
    setPlayerAmount(playerAmountStringForRegex);
    std::cout << "TEST IN INITGAME(){} 1 : playerAmountStringForRegex is : " << playerAmountStringForRegex << std::endl;
    setPlayerNames(playerNames_);
}

void Game::run(bool gO){

    updateGame(gameOver_); //TODO -- may need to pass bool by reference here, somehow, & didn't work.
}

void Game::updateGame(bool& gO){
    //TODO -- need to add game loop here/game logic/while loop;3/21/2021 time stamp.
    int i=0;
    do {
    std::cout << i++ << std::endl;    
    } while (i < 10);
    std::cout << "error : made it to end of game.update()" << std::endl;
    exit(1);
}

void Game::setPlayerAmount(std::string &playerAmountString){ 
    const unsigned int max_players = 4;
    std::string numbers_text[] = {"one", "two", "three", "four"};
    std::map<int, std::regex> conversion_table = get_regex_map(max_players, numbers_text); 
    std::cout << "Enter (1) Player or (2) Players?" << std::endl;
    std::cin >> playerAmountString;

        while(!std::cin.fail() && std::regex_match(playerAmountString, getRegex(max_players, *numbers_text))){ 

                for(auto &el: conversion_table){  
                    if (std::regex_match(playerAmountString, el.second)){
                        std::cout << "Number of players selected is : " << el.first << std::endl;
                        playerAmount_ = el.first;
                        std::cout << "TEST 1 : playerAmount_ is : " << playerAmount_ << std::endl;

                    } 
                }
                std::cout << "TEST 2 : playerAmount_ is : " << playerAmount_ << std::endl;
                return;
        }

}

void Game::setPlayerNames(std::vector<std::string> &playerNames){ //todo -- Look into "std::unique_ptr<T[]>" instead of vector.
    int l_playerAmount;
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

std::regex Game::getRegex(unsigned int max_players, std::string numbers_text){
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
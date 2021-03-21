#include "game.hpp"
#include <iostream>
#include <array>
#include <regex>
//#include <string>


Game::Game()
{
    gameOver_ = false;

}
Game::~Game()
{

}
void Game::initGame(){
    setPlayerAmount(playerAmountStringForRegex);
}

void Game::run(bool gO){

    updateGame(gameOver_); //TODO -- may need to pass bool by reference here, somehow, & didn't work.
}
void Game::updateGame(bool& gO){
     
    setPlayerAmount(playerAmountStringForRegex);
    setPlayerNames(playerNames);
    //TODO -- need to add game loop here/game logic/while loop;3/21/2021 time stamp.
    int i=0;
    do {
    std::cout << i++ << std::endl;    
    } while (i < 10);
    std::cout << "error : made it to end of game.update()" << std::endl;
    exit(1);
}
    void Game::setPlayerNames(std::array<std::string, 4> playerNames){ 
        int l_playerAmount;
        l_playerAmount = getPlayerAmount();
        std::cout << "TEST : setPlayerNames(), set l_playerAmount = game.getPlayerAmount()." << std::endl;
        std::cout << "TEST : l_playerAmount = " << l_playerAmount << std::endl;
        std::string pName;

        for (auto &el: playerNames){  //TODO -- Broken here somewhere, cout << el doesn't work, may need l_playername...
            std::cout << "Enter player " << playerNames.end() << "'s name : " << std::endl;
            std::cin >> pName;
            playerNames.back() = pName;
            std::cout << "pName is : " << pName << std::endl;
        }
        //todo waiting on array of player names.

    }
        int Game::setPlayerAmount(std::string playerAmountString){ 
        const unsigned int max_players = 4;
        std::string numbers_text[] = {"one", "two", "three", "four"};
        std::map<int, std::regex> conversion_table = get_regex_map(max_players, numbers_text); 
        std::cout << "Enter (1) Player or (2) Players?" << std::endl;
        std::cin >> playerAmountString;

        while(!std::cin.fail()){ 

                for(auto &el: conversion_table){  
                    if (std::regex_match(playerAmountString, el.second)){
                        std::cout << "Number of players selected is : " << el.first << std::endl;
                        return *playerAmount = el.first;
                    } 
                }
                return 1;
        }
        return 1;
    }
        std::regex Game::getRegex(unsigned int max_players, std::string numbers_text){
        
        std::stringstream ss;
        ss << "[1-";
        ss << max_players;
        ss << "]";
        for (unsigned int i = 0; i < max_players; i++){
            ss << "|";
            ss << numbers_text[i];
        }
        std::string s = "";
        ss >> s;
        std::regex regex(s, std::regex::icase);
        return regex;
    }
    std::map<int, std::regex> Game::get_regex_map(unsigned int max_players, std::string* numbers_text){
        std::map<int, std::regex> convert_table;
        for(unsigned int i = 0; i < max_players; i++){
            std::string s = numbers_text[i] + "|" + std::to_string(i+1);
            std::regex r(s, std::regex::icase);
            convert_table[i+1] = r;
        }
        return convert_table;
    }
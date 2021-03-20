#include "game.hpp"
#include <iostream>
#include <array>
#include <regex>
//#include <string>


Game::Game()
{

}
Game::~Game()
{

}
void Game::initGame(){
    setPlayerAmount(playerAmountStringForRegex);
}

void Game::run(bool& gO){

    updateGame(gO);
}
void Game::updateGame(bool& gO){
/*     int i = 0;   //todo delete this test code
    while (i < 3){
        std::string inputString;
        std::getline(std::cin, inputString);
        i++;
    }
    gO = true; */

    std::cout << "error : made it to end of game.update()" << std::endl;
}
    void Game::setPlayerNames(std::array<std::string, 4> playerNames, Game &game){ 
        int l_playerAmount;
        l_playerAmount = game.getPlayerAmount();
        std::cout << "TEST : setPlayerNames(), set l_playerAmount = game.getPlayerAmount()." << std::endl;
        std::cout << "TEST : l_playerAmount = " << l_playerAmount << std::endl;
        std::string pName;

        for (auto &el: playerNames){
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
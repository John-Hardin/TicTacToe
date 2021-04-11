#pragma once
#include "game.hpp"
#include <limits>
//#include "player.hpp"
//#include <iostream>
//#include <regex>


Game::Game()
{


}
Game::~Game()
{

}
/*----------------------------------------Game Stuff-------------------------------*/
/*---------------------------------------------------------------------------------*/

void Game::run(bool gO, std::string playerAmountStringForRegex_, int &playerAmount_, std::vector<std::unique_ptr<Player>> &players_){
    // std::unique_ptr<Player> p1;
    // std::unique_ptr<Player> p2;
    // std::unique_ptr<Player> p3;
    // std::unique_ptr<Player> p4;
    // players_.emplace_back(p1);
    // players_.emplace_back(p2);
    // players_.emplace_back(p3);
    // players_.emplace_back(p4);
    initGame(playerAmountStringForRegex_, playerAmount_);
    initPlayerObjects(playerAmountStringForRegex_, playerAmount_);
    updateGame(gO); 
}
void Game::initGame(std::string playerAmountStringForRegex_, int &playerAmount_){ 
    std::cout << "T : players_[2]->name_ ------>" << players_[2]->name_ << std::endl;
    std::cout << "T : players_[2]->getName() ------>" << players_[2]->getName() << std::endl;
    std::cout << "T : players_[2].get() ------>" << players_[2].get() << std::endl;
      
}
void Game::updateGame(bool& gO){
    //TODO -- need to add game loop here/game logic/while loop;3/21/2021 time stamp.

    while(gO){
        updateBoard();
        gO = true;  // TODO - toggle to end game gracefully vs leaving it open loop ended.
    }
}
/*------------------------------------------Player Stuff-----------------------------*/
/*-----------------------------------------------------------------------------------*/

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
            setPlayerAmount(playerAmountStringForRegex_);
        }
        else {
            for(auto &el: conversion_table){ 
                    if(std::regex_match(playerAmountString, el.second)){
                        std::cout << "Number of players selected is : " << el.first << std::endl;
                        playerAmount_ = el.first;
                        std::cout << "playerAmount_ is : " << playerAmount_ << std::endl;
                    }

                } return; // todo figure out a better way to write this; maybe without cin.fail(), and the return. 
        }
    }
}   

void Game::initPlayerObjects(std::string &playerAmountString, int &numPlayers){
    //set number of players
    setPlayerAmount(playerAmountStringForRegex_);
    std::cout << "playerAmountStringForRegex is : " << playerAmountStringForRegex_ << std::endl;
    std::cout << "numPlayers is : " << numPlayers << std::endl;

    // init player objects
    std::string inputone;
    char inputtwo;
    std::cout << "T : players_.size() is : " << players_.size() << std::endl;
    int i =1;
    for(i; numPlayers >= i; i++){
            std::cout << "Enter player "<< i+1 << "'s name : ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> inputone; // string name _N
            std::cout << "Enter player " << i+1  << "'s symbol : ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> inputtwo; // char symbol _S
            players_[i]->name_ = inputone; players_[i]->symbol_ = inputtwo;  //TODO -- LEFT OFF HERE--- April 6, 2021; 12:12pm.
            std::cout << "inputone inputtwo are : " << inputone << " " << inputtwo << std::endl;
            //std::cin.clear();
            std::cout << "numPlayers is : " << numPlayers << std::endl;
            std::cout << "players_.size() is : " << players_.size() << std::endl;
             //TODO - April 7, 2021; 11:51pm, ***smashing stack***, something is overrunning a buffer, likely the if statement and/or for loop are out of order or something.
            std::cout << "players_[i-1]->name_ INside for loop is : " << players_[i-1]->name_ << std::endl;
            std::cout << "i is " << i << std::endl;
    }   
                std::cout << "players_[i-1]->name_ OUTside for loop is : " << players_[i-1]->name_ << std::endl;
}                                                                                                               // TODO - April 8, 2021; 10:37pm, seg fault, debug needed....  still need to try unique_ptr.

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
    std::cout << "s is : " << s << std::endl;
    std::regex regex(s, std::regex::icase);
    return regex;
}

std::map<int, std::regex> Game::get_regex_map(unsigned int max_players, std::string* numbers_text){
    std::map<int, std::regex> convert_table;
    for(unsigned int i = 0; i < max_players; i++){
        std::string s = numbers_text[i] + "|" + std::to_string(i+1);
        std::cout << "std::string s = numbers_text[i] + \"|\" + std::to_string(i+1); is : " << s << std::endl;
        std::regex r(s, std::regex::icase);
        convert_table[i+1] = r;
    }
    return convert_table;
}
/*-------------------------------------------Board Stuff------------------------------*/
/*------------------------------------------------------------------------------------*/
void Game::updateBoard(){

}
void Game::printBoard(){

}
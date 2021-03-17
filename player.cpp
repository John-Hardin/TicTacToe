
#include <iostream>
#include <limits>
#include <regex>
#include <array>
#include <string>
#include <sstream>
#include <map>
#include "player.hpp"
//#include "board.hpp"

//c-tor, d-tor.
    Player::Player() {setPlayerAmount(playerAmountString); setPlayerNames(playerNames[4], Player::&player);}
    Player::~Player() {}
//getters
    std::regex Player::getRegex(unsigned int max_players, std::string* numbers_text){
        
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
    std::map<int, std::regex> Player::get_regex_map(unsigned int max_players, std::string* numbers_text){
        std::map<int, std::regex> convert_table;
        for(unsigned int i = 0; i < max_players; i++){
            std::string s = numbers_text[i] + "|" + std::to_string(i+1);
            std::regex r(s, std::regex::icase);
            convert_table[i+1] = r;  //todo Get this line explained like I'm 5 years old.
        }
        return convert_table;
    }
    
//setters



//main functions
    
    int Player::setPlayerAmount(std::string playerAmountString){
        const unsigned int max_players = 4;
        std::string numbers_text[] = {"one", "two", "three", "four"};
        std::map<int, std::regex> conversion_table = get_regex_map(max_players, numbers_text); 
        std::cout << "Enter (1) Player or (2) Players?" << std::endl;
        std::cin >> playerAmountString;

        while(!std::cin.fail()){ 

                for(auto &el: conversion_table){  
                    if (std::regex_match(playerAmountString, el.second)){
                        std::cout << "Number of players selected is : " << el.first << std::endl;
                        return this->playerAmount = el.first;
                    } 
                }
                return 1;
        }
        return 1;
    }

    void Player::setPlayerNames(std::vector<std::string> player, Player &player_){
        player_.playerAmount = getPlayerAmount();
        std::cout << "TEST : setPlayerNames(), set player.playerAmount." << std::endl;
        std::string pName;
        for (auto &it: playerNames){
            if (this->playerAmount <= playerAmount){
                std::cin >> pName;
                playerNames->emplace_back(pName);
                std::cout << "pName is : " << pName << std::endl;

            }
        }  //todo waiting on array of player names.

    }


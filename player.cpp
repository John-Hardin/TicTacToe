
#include <iostream>
#include <limits>
#include <regex>
#include <array>
#include <string>
#include <sstream>
#include <map>
#include "player.hpp"
//#include "board.hpp"

    Player::Player() 
    {

        setPlayerAmount(playerAmountString);
        setPlayerNames(s);
        /* enum swap { ZERO, ONE, TWO, THREE, FOUR }; // enum for switch statement in setPlayerNames();. */
        
    }
    Player::~Player()
    {

    }
    //getters
    //int Player::getPlayerAmount(){return playerAmount;}
    
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
        std::map<int, std::regex> conversion_table = get_regex_map(max_players, numbers_text); //todo conversion_table second el is....  what?
                                                                                                // and for what first el is it paired with?
        std::cout << "Enter (1) Player or (2) Players?" << std::endl;
        std::cin >> playerAmountString;
        //template <class CharT, class Traits = std::regex_traits<CharT> > class basic_regex;

        while(!std::cin.fail()){ 
            // Validate input; copy paste from player.hpp comment-->
            // Use <regex> to validate input of string to check for 1 or 2, then convert to the integer playerAmount.

                for(auto &el: conversion_table){  // TODO run debugger in this loop and see why it outputs "Input not recognized" multiple times.
                    if (std::regex_match(playerAmountString, el.second)){
                        std::cout << "Number of players selected is : " << el.first << std::endl;
                        return this->playerAmount = el.first;
                    } 
                }
                return 1;
        }
        return 1;
    }
    void Player::setPlayerNames(enum swap S){  //todo error here, figure out why.

            switch(S){
                case ONE:
                    std::cout << "What is player's Name : ";
                    std::cin >> this->playerOneName;
                    break;
                case TWO:
                    std::cout << "What is player's Name : ";
                    std::cin >> this->playerOneName;
                    std::cout << "What is player " << std::to_string(2) << "'s Name : ";
                    std::cin >> this->playerTwoName;
                    break;
                case THREE:
                    std::cout << "What is player's Name : ";
                    std::cin >> this->playerOneName;
                    std::cout << "What is player " << std::to_string(2) << "'s Name : ";
                    std::cin >> this->playerTwoName;
                    std::cout << "What is player " << std::to_string(3) << "'s Name : ";
                    std::cin >> this->playerThreeName;
                    break;
                case FOUR:
                    std::cout << "What is player's Name : ";
                    std::cin >> this->playerOneName;
                    std::cout << "What is player " << std::to_string(2) << "'s Name : ";
                    std::cin >> this->playerTwoName;
                    std::cout << "What is player " << std::to_string(3) << "'s Name : ";
                    std::cin >> this->playerThreeName;
                    std::cout << "What is player " << std::to_string(4) << "'s Name : ";
                    std::cin >> this->playerFourName;
                    break;
                default:
                    std::cout << "ERROR in setPlayerAmount" << std::endl;
                    break;
            }
            
    }


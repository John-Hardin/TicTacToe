
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
        setPlayerNames();
    }
    Player::~Player()
    {

    }
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
        const unsigned int max_players = 2;
        std::string numbers_text[] = {"one", "two", "three", "four"};
        std::map<int, std::regex> conversion_table = get_regex_map(max_players, numbers_text);
        std::cout << "Enter (1) Player or (2) Players?" << std::endl;
        std::cin >> playerAmountString;
        //template <class CharT, class Traits = std::regex_traits<CharT> > class basic_regex;

        while(!std::cin.fail()){ 
            // Validate input; copy paste from player.hpp comment-->
            // Use <regex> to validate input of string to check for 1 or 2, then convert to the integer playerAmount.
            if (!std::regex_match(playerAmountString, regex)){  //todo fix this while loop and if statement, it's acting weird.
            std::cout << "Input not recognized." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
        } else {
/*                 std::cout << "TEST LINE: hello from inside setPlayerAmount(), inside else statement (cin.fail())" << std::endl;
                std::cout << "TEST LINE: std::regex_replace(playerAmountString, regex) is : " << std::regex_match(playerAmountString, regex) << std::endl; //todo delete this testing line
 */

                for(auto &el: conversion_table){
                    if (std::regex_match(playerAmountString, el.second)){
                        std::cout << "Number of players selected is : " << el.first << std::endl;
                        return this->playerAmount = el.first;
                    }
                }
            }
        return 55;
        // End While Loop; playerAmount should be validated first as string input, using <regex>,
        // then converted to integer playerAmount and returned.
        }
        return 0;
    }
    void Player::setPlayerNames(){
        if (this->playerAmount == 1){
            // one player game
            std::cout << "What is player's Name : ";
            std::cin >> this->playerOneName;
        } else if (this->playerAmount == 2){
            // two player game
            std::cout << "What is player one's Name : ";
            std::cin >> this->playerOneName;
            std::cout << "What is player two's Name : ";
            std::cin >> this->playerTwoName;
        } else {
            // error
            std::cout << "TEST LINE : setPlayerNames() error; made it to else statement." << std::endl;
        }
    }


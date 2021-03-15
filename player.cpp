
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
        const unsigned int max_players = 4;
        std::string numbers_text[] = {"one", "two", "three", "four"};
        std::map<int, std::regex> conversion_table = get_regex_map(max_players, numbers_text);
        std::cout << "Enter (1) Player or (2) Players?" << std::endl;
        std::cin >> playerAmountString;
        //template <class CharT, class Traits = std::regex_traits<CharT> > class basic_regex;

        while(!std::cin.fail()){ 
            // Validate input; copy paste from player.hpp comment-->
            // Use <regex> to validate input of string to check for 1 or 2, then convert to the integer playerAmount.
            
/*             if (std::regex_search(playerAmountString,matchResult, conversion_table)){  //todo fix this while loop and if statement, it's acting weird.
            std::cout << "Input not recognized." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
        } else {
/*                 std::cout << "TEST LINE: hello from inside setPlayerAmount(), inside else statement (cin.fail())" << std::endl;
                std::cout << "TEST LINE: std::regex_replace(playerAmountString, regex) is : " << std::regex_match(playerAmountString, regex) << std::endl; //todo delete this testing line
 */ 

                // TODO  check if the above if else statements are actually needed, seems to work without them;
                // also check what the if statement below does exactly the "el.second" specifically.



                for(auto &el: conversion_table){  // TODO run debugger in this loop and see why it outputs "Input not recognized" multiple times.
                    if (std::regex_match(playerAmountString, el.second)){
                        std::cout << "Number of players selected is : " << el.first << std::endl;
                        return this->playerAmount = el.first;
                    } else {  
                        std::cout << "Input not recognized." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
                    }
                }
        /* } */
                return 55;
        // End While Loop; playerAmount should be validated first as string input, using <regex>,
        // then converted to integer playerAmount and returned.
        }
        return 0;
    }
    void Player::setPlayerNames(){
            switch(this->playerAmount){
                case 1:
                    std::cout << "What is player's Name : ";
                    std::cin >> this->playerOneName;
                    break;
                case 2:
                    std::cout << "What is player's Name : ";
                    std::cin >> this->playerOneName;
                    std::cout << "What is player " << std::to_string(2) << "'s Name : ";
                    std::cin >> this->playerOneName;
                    break;
                case 3:
                    std::cout << "What is player's Name : ";
                    std::cin >> this->playerOneName;
                    std::cout << "What is player " << std::to_string(2) << "'s Name : ";
                    std::cin >> this->playerOneName;
                    std::cout << "What is player " << std::to_string(3) << "'s Name : ";
                    std::cin >> this->playerOneName;
                    break;
                case 4:
                    std::cout << "What is player's Name : ";
                    std::cin >> this->playerOneName;
                    std::cout << "What is player " << std::to_string(2) << "'s Name : ";
                    std::cin >> this->playerOneName;
                    std::cout << "What is player " << std::to_string(3) << "'s Name : ";
                    std::cin >> this->playerOneName;
                    std::cout << "What is player " << std::to_string(4) << "'s Name : ";
                    std::cin >> this->playerOneName;
                    break;
                default:
                    std::cout << "ERROR in setPlayerAmount" << std::endl;
                    break;  // todo switch statement should execute all previous cases, eg.: if case
                            // is 4, it should ask for player 1, 2, 3, and *then* 4's name, currently
                            // it just goes straight to asking for "player4 Name : "
            }


/*         if (this->playerAmount == 1){
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
        } */
    }


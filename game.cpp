#pragma once
#include "game.hpp"
#include <limits>
#include <fstream>
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

void Game::run(){
    std::unique_ptr<Player> p1 = std::make_unique<Player>(Player());
    std::unique_ptr<Player> p2 = std::make_unique<Player>(Player());
    std::unique_ptr<Player> p3 = std::make_unique<Player>(Player());
    std::unique_ptr<Player> p4 = std::make_unique<Player>(Player());
    players_.emplace_back(std::move(p1));
    players_.emplace_back(std::move(p2));
    players_.emplace_back(std::move(p3));
    players_.emplace_back(std::move(p4));
    gameOver_ = false;
    initPlayerObjects();
    std::string INPUT = initBoard();
    updateGame(INPUT); 
}
void Game::updateGame(std::string &INPut){
    //TODO -- need to add game loop here/game logic/while loop;3/21/2021 time stamp.
    gameOver_ = false;
    while(gameOver_){
        updatePlayers();
        updateBoard(INPut);
        gameOver_ = true;  //--toggle to end game gracefully vs leaving it open loop ended.
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

                }   return; //TODO April 15, 2021; 10:00pm, change this while loop, to maybe an if statement, and also the while loop in initboard() function below.
        }
    }
}   

void Game::initPlayerObjects(){
    //set number of players
    setPlayerAmount(playerAmountStringForRegex_);
    std::cout << "playerAmountStringForRegex is : " << playerAmountStringForRegex_ << std::endl;
    std::cout << "playerAmount_ is : " << playerAmount_ << std::endl;

    // init player objects
    std::cout << "T : players_.size() is : " << players_.size() << std::endl;  //TODO - April 11, 2021; 5:52pm -- players_.size is 0, needs to be something else I think, dynamic maybe?

    for(int i = 0; playerAmount_ > i; i++){
            std::cout << "Pre: i is " << i << std::endl;
            std::cout << "players_[i].get() :" << players_[i].get() << std::endl;
            std::string tmp_nameString;
            char tmp_symbolChar;
        //sets name of playerObject pointed-to by std::unique_ptr object
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            std::cout << "Enter player "<< (i+1) << "'s name : ";
            std::cin >> tmp_nameString; // string name _N
            players_[i]->setName(tmp_nameString);

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            std::cout << "Enter player " << i+1  << "'s symbol : ";
            std::cin >> tmp_symbolChar; // string name _N
            players_[i]->setSymbol(tmp_symbolChar);
            std::cout << "playerAmount_ is : " << playerAmount_ << std::endl;
            std::cout << "players_.size() is : " << players_.size() << std::endl;
            std::cout << "players_[i]->getName() INside for loop is : " << players_[i]->getName() << std::endl;
            std::cout << "players_[i]->name_ INside for loop is : " << players_[i]->getName() << std::endl;
            std::cout << "Post: i is " << i << std::endl;

    }   
}          
void Game::updatePlayers(){
    
}
std::regex Game::getRegex(unsigned int max_players, std::string *numbers_text){
    std::stringstream ss;
    ss << "[1-";
    ss << max_players;
    //std::cout << "TEST : max_players is " << max_players << std::endl;
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
std::string Game::initBoard(){
    // hardcoded regex = 1|3|5|one|three|five|star|random|3x3|5x5|s|r
    //std::string b_number_string;
    //int board_number; ////// -- April 15 2021, 4:09am, these 3 lines are for later should I decide to make the regex validation not use a hardcoded expression.
    std::string regex_board_string = "1|3|5|s|r|one|three|five|star|random|3x3|5x5|3by3|5by5|3 x 3|5 x 5|3 by 3|5 by 5";
    std::regex board_reg_exp(regex_board_string, std::regex::icase);
    std::string b3 = "boards/board3by3.txt", b5 = "boards/board5by5.txt", bS = "boards/boardStar.txt", bR = "boards/boardRandom.txt";
    std::string input;


    std::cout << "What board would you like to play on?" << std::endl;
    std::cout << "Your choices are : 3 by 3 board, 5 by 5 board, star shaped board, random shape." << std::endl;
    std::cout << "Enter choice : ";
    std::cin >> input;
        if (!std::regex_match(input, board_reg_exp)){
            std::cout << "Input not recognized, try again." << std::endl;
            initBoard();
        } else {

            std::ifstream instream(b3,std::ios::in);
            if(!instream.is_open()){
                std::cout << "failed to open text file for board..." << std::endl;
                initBoard();
            } else {
                    std::cout << "Board choice input good" << std::endl;
                    char str[5000];
                    instream.read(str, sizeof(str));
                    return input;
                    //std::cout << str;
                    //return;  //TODO April 15, 2021; 10:00pm, initBoard should not print, just store the board data, and store it so it's manipulatable.
            }
        }
}
void Game::updateBoard(std::string &INput){
    printBoard(INput);
}
void Game::printBoard(std::string Input){
    std::ifstream instream(Input,std::ios::in);
    char In [5000];
    instream.read(In, sizeof(Input));
    std::cout << In;
}

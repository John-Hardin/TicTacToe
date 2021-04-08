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
/*---------------------------------------------------------------------------------*/
/*----------------------------------------Game Stuff-------------------------------*/
void Game::initGame(std::string playerAmountStringForRegex_, int playerAmount_, std::vector<std::shared_ptr<Player>> &players_){  //TODO - April 7, 2021; 8:45pm, added the arguments here, but they are probably wrong.
/*     setPlayerAmount(playerAmountStringForRegex_);
    std::cout << "TEST IN INITGAME(){} 1 : playerAmountStringForRegex is : " << playerAmountStringForRegex_ << std::endl; */
    
    //setPlayerNames(playerNames_, playerAmount_);
    initPlayerObjects(playerAmountStringForRegex_, playerAmount_, players_);  //TODO -- April 6, 2021; move setPlayerAmount() and setPlayerNames() into this initPlayerObject() function.
}

void Game::run(bool gO){
    // change to init game function Player player; //test 12:24pm
    
    initGame(playerAmountStringForRegex_, playerAmount_, players_);
    updateGame(gameOver_); //TODO -- may need to pass bool by reference here, somehow, & didn't work.
}

void Game::updateGame(bool& gO){
    //TODO -- need to add game loop here/game logic/while loop;3/21/2021 time stamp.

    while(gO){
        updateBoard();  // TODO LEFT OFF HERE, open loop, or just stalls : 3/27/2021 10:48pm
    }
}
/*-----------------------------------------------------------------------------------*/
/*------------------------------------------Player Stuff-----------------------------*/
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
                        std::cout << "TEST 1 : playerAmount_ is : " << playerAmount_ << std::endl;
                    }

                } return; // todo figure out a better way to write this; maybe without cin.fail(), and the return. 
        }
    }
}   

/*void Game::setPlayerNames(std::vector<std::string> &playerNames, int& l_playerAmount){ //todo -- Look into "std::unique_ptr<T[]>" instead of vector.
    /* int l_playerAmount;
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


} */

void Game::initPlayerObjects(std::string &playerAmountString, int &numPlayers, std::vector<std::shared_ptr<Player>> &players_){
    //set number of players
    setPlayerAmount(playerAmountStringForRegex_);
    std::cout << "TEST IN INITGAME(){} 1 : playerAmountStringForRegex is : " << playerAmountStringForRegex_ << std::endl;
    std::cout << "TEST: numPlayers is : " << numPlayers << std::endl;

    // init player objects
    std::string inputone;
    char inputtwo;
    std::shared_ptr<Player> p1, p2, p3, p4;
    std::array<std::shared_ptr<Player>, 4> arrayHoldingSmartPointers{p1, p2, p3, p4};
    std::cout << "TEST: arrayHoldingSmartPointers.size() is : " << arrayHoldingSmartPointers.size() << std::endl;
    std::cout << "TEST: players_.size() is : " << players_.size() << std::endl;
    int count = 1;
    for(auto &el: arrayHoldingSmartPointers){
        if(numPlayers >= count){
            std::cout << "Enter player "<< count << "'s name : ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> inputone; // string name _N
            std::cout << "Enter player " << count  << "'s symbol : ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> inputtwo; // char symbol _S
            players_.emplace_back(arrayHoldingSmartPointers[players_.size()] = std::make_shared<Player>(inputone, inputtwo));  //TODO -- LEFT OFF HERE--- April 6, 2021; 12:12pm.
            std::cout << "TEST: inputone inputtwo are : " << inputone << " " << inputtwo << std::endl;
            //std::cin.clear();
            std::cout << "TEST: numPlayers is : " << numPlayers << std::endl;
            std::cout << "TEST: players_.size() is : " << players_.size() << std::endl;
            std::cout << &el << std::endl;
            ++count;
            std::cout << count << std::endl;

        }
        
    }   
    std::cout << "T : p1->name is : " << p1->getName() << std::endl;
    std::cout << "T : p2->name is : " << p2->getName() << std::endl;
    std::cout << "T : p3->name is : " << p3->getName() << std::endl;
    std::cout << "T : p4->name is : " << p4->getName() << std::endl;
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
/*------------------------------------------------------------------------------------*/
/*-------------------------------------------Board Stuff------------------------------*/
void Game::updateBoard(){

}
void Game::printBoard(){

}
//
//  main.cpp
//  Harvest Game
//
//  Created by Brandon Seals on 10/22/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

const int seasonLength{0};
const int gameLength{seasonLength * 0};
const int startingGold{100};

int main()
{
    int numPlayers{0};
    int age{0};
    std::vector<int> playerAges;
    std::string name{""};
    std::vector<std::string> playerNames;
    bool gameStatus{false};
    int currentPlayer{0};
    int currentPhase{0};
    
    do {
        std::cout << "\nHow many players are there? [1-4]: ";
        std::cin >> numPlayers;
        std::cin.clear();
        std::cin.ignore();
    } while ((numPlayers < 1) || (numPlayers > 4));
    
    // TODO: add validation for name
    for (size_t i{1}; i <= numPlayers; ++i) {
        std::cout << "\nWhat is player " << i << "'s name?: ";
        std::cin >> name;
        do {
            std::cout << "\nWhat is player " << i << "'s age?: ";
            std::cin >> age;
            std::cin.clear();
            std::cin.ignore();
        } while ((numPlayers < 1) || (numPlayers > 150));
        playerAges.push_back(age);
        playerNames.push_back(name);
    }
    
    // TODO: add bubble sort from lab assignment to do full sorting
    // TODO: when ages match, sort alphabetically
    for (size_t i{1}; i < playerAges.size(); ++i) {
        if (playerAges[i] < playerAges[i - 1]) {
            std::swap(playerAges[i], playerAges[i - 1]);
            std::swap(playerNames[i], playerNames[i - 1]);
        }
    }
    
    /* Create players sorted by age */
    Player Player1(1, playerNames[0], playerAges[0], startingGold);
    if (numPlayers > 1) {
        Player Player2(2, playerNames[1], playerAges[1], startingGold);
    }
    if (numPlayers > 2) {
        Player Player3(3, playerNames[2], playerAges[2], startingGold);
    }
    if (numPlayers > 3) {
        Player Player4(4, playerNames[3], playerAges[3], startingGold);
    }
    
    // TODO: conditionals in loop using currentPhase and currentPlayer
    // TODO: allow quitting at certain point in loop
    while (gameStatus) {
        
        // if currentPhase == season
        // if currentPhase == market
        // if currentPhase == farm
        
    } // end game loop
    
    return 0;
}

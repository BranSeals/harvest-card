/*  
 * Author: Brandon Seals
 * Last revised: 2016-11-25
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Market.hpp"

/* Game rules */
const int seasonLength{0};
const int gameLength{seasonLength * 4};
const int startingGold{100};

int main()
{
    /* Player initialization */
    int numPlayers{0};
    int age{0};
    std::vector<int> playerAges;
    std::string name{""};
    std::vector<std::string> playerNames;
    bool gameStatus{false};
	Player Player1, Player2, Player3, Player4;
    
    /* Get number of players */
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
	Player1.setPlayerNumber(1);
	Player1.setPlayerName(playerNames[0]);
	Player1.setPlayerAge(playerAges[0]);
	Player1.setPlayerGold(startingGold);

    if (numPlayers > 1) {
		Player2.setPlayerNumber(2);
		Player2.setPlayerName(playerNames[1]);
		Player2.setPlayerAge(playerAges[1]);
		Player2.setPlayerGold(startingGold);
    }
    if (numPlayers > 2) {
		Player3.setPlayerNumber(3);
		Player3.setPlayerName(playerNames[2]);
		Player3.setPlayerAge(playerAges[2]);
		Player3.setPlayerGold(startingGold);
    }
    if (numPlayers > 3) {
		Player4.setPlayerNumber(4);
		Player4.setPlayerName(playerNames[3]);
		Player4.setPlayerAge(playerAges[3]);
		Player4.setPlayerGold(startingGold);
    }
    
	/* Print player information */
    Player1.printPlayer();
	if (numPlayers > 1) {
		Player2.printPlayer();
	}
	if (numPlayers > 2) {
		Player3.printPlayer();
	}
	if (numPlayers > 3) {
		Player4.printPlayer();
	}
    
    /* Game initialization */
    int currentPlayer{0};
    int currentPhase{0};
    Deck allCards;
    
    /* Season initialization */
    Deck springDeck;
    Deck summerDeck;
    Deck autumnDeck;
    Deck winterDeck;
    
    /* Market initialization */
    Deck seedDeck;
    Deck toolDeck;
    Deck livestockDeck;
    

    
    /* Game loop */
    // TODO: conditionals in loop using currentPhase and currentPlayer
    // TODO: allow quitting at certain point in loop
    while (gameStatus) {
        
        // if currentPhase == season
        // if currentPhase == market
        // if currentPhase == farm
        
    } // end game loop
    
    return 0;
}

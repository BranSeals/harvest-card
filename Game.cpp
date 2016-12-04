//
//  Game.cpp
//  Contains game rules
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include "Game.hpp"
#include "Farm.hpp"
#include <iostream>

Game::Game()
{
}

Game::Game(std::string title, std::string description, int seasonLen, int years, int gold)
    : gameTitle{title}, gameDescription{description}, seasonLength{seasonLen},
    gameLength{years}, startingGold{gold}
{
}

Game::~Game()
{
}

//* Getters / Setters *//

/* Number of players */
int Game::getNumPlayers(void)
{
    return numPlayers;
}

void Game::setNumPlayers(int players)
{
    if ((players > 0) && (players < 5)) {
        numPlayers = players;
    }
}

/* Age of player; needs element number */
int Game::getPlayerAge(int index)
{
    return playerAges[index];
}

void Game::setPlayerAge(int index, int age)
{
    playerAges[index] = age;
}

/* Name of player, needs element number */
std::string Game::getPlayerName(int index)
{
    return playerNames[index];
}

void Game::setPlayerName(int index, std::string name)
{
    playerNames[index] = name;
}


/* Number of seasons played */
int Game::getGameLength(void)
{
    return gameLength;
}

void Game::setGameLength(int length)
{
    gameLength = length;
}

/* Number of cards in season deck */
int Game::getSeasonLength(void)
{
    return seasonLength;
}

void Game::setSeasonLength(int length)
{
    seasonLength = length;
}

/* Get status of game */
bool Game::getGameStatus(void)
{
    return gameStatus;
}

void Game::setGameStatus(bool tf)
{
    gameStatus = tf;
}

//* Methods *//

void Game::beginGame(void)
{
    getPlayers();
    setGameStatus(true); // check with player before or after above getting players
    fillDecks();
    gameTime.fillSeasons(&gameDeck);
    gameMarket.fillStalls(&gameDeck);
    gameLoop();
    printPlayers();
}

void Game::addPlayer(std::string name, int age)
{
    playerNames.push_back(name);
    playerAges.push_back(age);
}

void Game::quitGame(void)
{
    // TO DO: Replace below with confirmYN function from main
    if (confirmYN("\Quit game? [y/n]: ")) {
        std::cout << "\n> Quitting game...\n";
        gameStatus = false;
    } else {
        gameStatus = true;
    }
}

void Game::getPlayers() {
    std::string name;
    int age;
    std::vector<int>* playerAgesPtr{nullptr};
    std::vector<std::string>* playerNamesPtr{nullptr};

    /* Get number of players */
    do {
        std::cout << "\nHow many players are there? [1-4]: ";
        std::cin >> numPlayers;
        std::cin.clear();
        std::cin.ignore();
    } while ((numPlayers < 1) || (numPlayers > 4));

    for (size_t i{1}; i <= numPlayers; ++i) {
        std::cout << "\nWhat is player " << i << "'s name?: ";
        std::cin >> name;
        do {
            std::cout << "What is player " << i << "'s age?: ";
            std::cin >> age;
            std::cin.clear();
            std::cin.ignore();
        } while ((numPlayers < 1) || (numPlayers > 150));
        // playerAges.push_back(age);
        // playerNames.push_back(name);
        addPlayer(name, age);
    }

    /* Sort players by age and name (youngest first, then alphabetically) */
    if (numPlayers > 1) {
        playerAgesPtr = &playerAges;
        playerNamesPtr = &playerNames;
        sortPlayers(playerAgesPtr, playerNamesPtr);
    }

    Player Player1, Player2, Player3, Player4;

    /* Create players sorted by age */
    Player1.setPlayerNumber(1);
    Player1.setPlayerName(playerNames[0]);
    Player1.setPlayerAge(playerAges[0]);
    Player1.setPlayerGold(startingGold);
    player.push_back(Player1);

    if (numPlayers > 1) {
        Player2.setPlayerNumber(2);
        Player2.setPlayerName(playerNames[1]);
        Player2.setPlayerAge(playerAges[1]);
        Player2.setPlayerGold(startingGold);
        player.push_back(Player2);
    }
    if (numPlayers > 2) {
        Player3.setPlayerNumber(3);
        Player3.setPlayerName(playerNames[2]);
        Player3.setPlayerAge(playerAges[2]);
        Player3.setPlayerGold(startingGold);
        player.push_back(Player3);
    }
    if (numPlayers > 3) {
        Player4.setPlayerNumber(4);
        Player4.setPlayerName(playerNames[3]);
        Player4.setPlayerAge(playerAges[3]);
        Player4.setPlayerGold(startingGold);
        player.push_back(Player4);
    }
}

void Game::sortPlayers(std::vector<int>* agesPtr, std::vector<std::string>* namesPtr)
{
    bool sortedAge{false};
    bool sortedName{false};

    while (!sortedAge || !sortedName) {

        /* Sort by age value first */
        for (size_t i{1}; i < (*agesPtr).size(); ++i) {

            if ((*agesPtr)[i] < (*agesPtr)[i - 1]) {
                std::swap((*agesPtr)[i], (*agesPtr)[i - 1]);
                std::swap((*namesPtr)[i], (*namesPtr)[i - 1]);
            }
        }
        /* Then sort by name */
        for (size_t i{1}; i < (*agesPtr).size(); ++i) {
            if (((*agesPtr)[i] == (*agesPtr)[i - 1])
                && ((*namesPtr)[i] < (*namesPtr)[i - 1])) {
                std::swap((*agesPtr)[i], (*agesPtr)[i - 1]);
                std::swap((*namesPtr)[i], (*namesPtr)[i - 1]);
            }
        }

        /* Verify age and name values are sorted; if not, re-loop */
        for (size_t j{1}; j < (*agesPtr).size(); ++j) {
            if ((*agesPtr)[j] < (*agesPtr)[j - 1]) {
                sortedAge = false;
                break;
            }
            if (((*agesPtr)[j] == (*agesPtr)[j - 1])
                && ((*namesPtr)[j] < (*namesPtr)[j - 1])) {
                sortedName = false;
                break;
            }
            sortedAge = true;
            sortedName = true;
        }
    }
}

void Game::printPlayers(void)
{
    /* Print player information */
    std::cout << "\n-- Player list --\n";
    for (size_t i{0}; i < player.size(); ++i) {
        player[i].print();
    }
}

bool Game::confirmYN(std::string message)
{
    char ynAnswer{};
    while ((tolower(ynAnswer) != 'n') || (tolower(ynAnswer)) != 'y') {
        std::cout << message;
        std::cin >> ynAnswer;
        std::cin.clear();
        std::cin.ignore();
        if (tolower(ynAnswer) == 'y') {
            return true;
        } else if (tolower(ynAnswer) == 'n') {
            return false;
        } else {
            std::cout << "\n*** Answer must be 'y' or 'n' ***\n";
        }
    }
    return false;
}

void Game::gameLoop(void)
{
  currentPlayer = 0;  // these are probably not necessary because they are default values

  while (gameStatus) {

    /* If player number is 0 or over 4, is player 1's turn */
    if (currentPlayer == 0 || currentPlayer > 4) {
      currentPlayer = 1;
    }
    if (player[currentPlayer].getCurrentPhase() == 0 || player[currentPlayer].getCurrentPhase() > 4) {
      player[currentPlayer].setCurrentPhase(1);
    }
    if (gameTime.getCurrentSeason() == 0 || gameTime.getCurrentSeason() > 4) {
      gameTime.setCurrentSeason(1);
    }

    // if game phase = 1; season phase
    if (player[currentPlayer].getCurrentPhase() == 1) {
      gameTime.printSeason();
      gameTime.resolveSeason();
      player[currentPlayer].setCurrentPhase(2);
    }

    // if game phase = 2; market phase
    if (player[currentPlayer].getCurrentPhase() == 2) {
        while (player[currentPlayer].getPlayerPhase() == 2) {
    			player[currentPlayer].printMarket();
          std::cout << "\nGold: " << player[currentPlayer].getPlayerGold() << std::endl;
    			player[currentPlayer].buy(&gameMarket);
    		}
        gameMarket.fillStalls(&gameDeck);
        player[currentPlayer].getCurrentPhase(3)
    }

    // if game phase = 3; work phase
    if (player[currentPlayer].getCurrentPhase() == 3) {
      while (player[currentPlayer].getPlayerPhase() == 3) {
          player[currentPlayer].work();
      }
      player[currentPlayer].getCurrentPhase(4)
    }

    // if game phase = 4; sell phase
    if (player[currentPlayer].getCurrentPhase() == 4) {
      while (player[currentPlayer].getPlayerPhase() == 4) {
          player[currentPlayer].sell(gameTime.getDaysLeft()); // make sure phase increments inside sell()
      }
      player[currentPlayer].setCurrentPhase(5)
    }

    /* Change to include this in a menu instead of explicitly asking */
		if (gameStatus) {
			if (confirmYN("Quit game? [y/n]: ")) {
				std::cout << "\n> Quitting game...\n";
				gameStatus = false;
			} else {
				std::cout << "\n> Continuing game...\n";
				gameStatus = true;
			}
		}

        /* if end of season, harvest */
        if (!gameTime.getDaysLeft()) {
          for (size_t i{0}; i < player.size(); ++i) {
              player[i].sell(gameTime.getDaysLeft());
          }

          /* Increment season */
          gameTime.setCurrentSeason(gameTime.getCurrentSeason() + 1);
	} // end game loop
    ++currentPlayer;
}
}

void Game::fillDecks(void)
{
    gameDeck.addCard(5101);
    gameDeck.addCard(5303);
    gameDeck.addCard(5301);
    gameDeck.addCard(6003);
    gameDeck.addCard(6005);
    gameDeck.addCard(6001);
    gameDeck.addCard(7001);
    gameDeck.addCard(7002);
    gameDeck.addCard(7004);

    gameDeck.addCard(5101);
    gameDeck.addCard(5303);
    gameDeck.addCard(5301);
    gameDeck.addCard(6003);
    gameDeck.addCard(6005);
    gameDeck.addCard(6001);
    gameDeck.addCard(7001);
    gameDeck.addCard(7002);
    gameDeck.addCard(7004);

    gameDeck.addCard(5101);
    gameDeck.addCard(5303);
    gameDeck.addCard(5301);
    gameDeck.addCard(6003);
    gameDeck.addCard(6005);
    gameDeck.addCard(6001);
    gameDeck.addCard(7001);
    gameDeck.addCard(7002);
    gameDeck.addCard(7004);

    gameDeck.addCard(5101);
    gameDeck.addCard(5303);
    gameDeck.addCard(5301);
    gameDeck.addCard(6003);
    gameDeck.addCard(6005);
    gameDeck.addCard(6001);
    gameDeck.addCard(7001);
    gameDeck.addCard(7002);
    gameDeck.addCard(7004);
}

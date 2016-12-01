//                          DEPRECATED
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
    gameLength{years * seasonLen}, startingGold{gold}
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
    setGameStatus(true);
    getPlayers();
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
        playerAges.push_back(age);
        playerNames.push_back(name);
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

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
    char yn;
    do {
        std::cout << "\nQuit game? [y/n]: ";
        std::cin >> yn;
    } while ((yn != 'y') && (yn != 'n'));

    if (yn == 'y') {
        setGameStatus(false);
    }
    else if (yn == 'n') {
        setGameStatus(true);
    }
    else {
        std::cout << "\n*** Error in quitGame() ***\n";
    }
}

void Game::getPlayers(void)
{
    int players{0};
    std::string name;
    int age;
    
    do {
        std::cout << "\nHow many players are there? [1-4]: ";
        std::cin >> players;
        std::cin.clear();
        std::cin.ignore();
    } while ((players < 1) || (players > 4));
    
    setNumPlayers(players);
    
    for (size_t i{1}; i <= getNumPlayers(); ++i) {
        std::cout << "\nWhat is player " << i << "'s name?: ";
        std::cin >> name;
        std::cout << "\nWhat is player " << i << "'s age?: ";
        std::cin >> age;
        addPlayer(name, age);
    }
    
    if (numPlayers == 1) {
        Farm p1Farm;
    }
}

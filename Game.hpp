// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23
// Updated: 2017-05-26

#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include "Player.hpp"
#include "Market.hpp"
#include "Deck.hpp"
#include "Season.hpp"

class Game
{
public:
    Game(std::string, std::string, int, int, int);
    ~Game();

    //* Getters / Setters *//

    /* Number of players */
    int getNumPlayers(void);
    void setNumPlayers(int);

    /* Age of player; needs element number */
    int getPlayerAge(int);
    void setPlayerAge(int, int);

    /* Name of player, needs element number */
    std::string getPlayerName(int);
    void setPlayerName(int, std::string);

    /* Number of seasons played */
    int getGameLength(void);
    void setGameLength(int);

    /* Number of cards in season deck */
    int getSeasonLength(void);
    void setSeasonLength(int);

    /* Get status of game */
    bool getGameStatus(void);
    void setGameStatus(bool);

    //* Methods *//

    /* Add player name and age to vectors */
    void addPlayer(std::string, int);
    void sortPlayers(std::vector<int>*, std::vector<std::string>*);

    /* Start and stop game loop */
    void beginGame(void);
    void quitGame(void);
    void getPlayers(void);
    bool confirmYN(std::string);
    void printPlayers(void);
    void gameLoop(void);

    void populateDeck(void);

	void gameOver(void);
	void rankPlayers(void);
	bool continueGame();

private:
  
	/* Filled in from game rule constants when Game object constructed */
	std::string gameTitle;
	std::string gameDescription;
    int startingGold;
	int gameLength{0};
	int seasonLength{0};

	/* Used to find and assign order of players */
	int numPlayers{1};
    std::vector<int> playerAges;
    std::vector<std::string> playerNames;

	/* Used together in game loop to iterate through each player */
    std::vector<Player> player;
	int currentPlayer{0};

    bool gameStatus{false}; // used to exit game loop

	/* Game objects */
    Market gameMarket;
    Deck gameDeck;
	Season gameSeason;
    
};
#endif /* Game_hpp */

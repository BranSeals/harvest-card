// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23

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

    int getNumPlayers(void);
    void setNumPlayers(int);

    int getPlayerAge(int);
    void setPlayerAge(int, int);

    std::string getPlayerName(int);
    void setPlayerName(int, std::string);

    int getGameLength(void);
    void setGameLength(int);

    int getSeasonLength(void);
    void setSeasonLength(int);

    bool getGameStatus(void);
    void setGameStatus(bool);

    void addPlayer(std::string, int);
    void sortPlayers(std::vector<int>*, std::vector<std::string>*);

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
    std::string gameTitle;
    std::string gameDescription;
    int startingGold;
    int gameLength{0};
    int seasonLength{0};
    int numPlayers{1};
    int currentPlayer{0};
    bool gameStatus{false};

    std::vector<int> playerAges;
    std::vector<std::string> playerNames;
    std::vector<Player> player;

    Market gameMarket;
    Deck gameDeck;
    Season gameSeason;
};
#endif
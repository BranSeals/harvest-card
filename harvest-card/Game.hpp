//
//  Game.hpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <vector>

class Game
{
public:
    Game();
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
    void sortPlayers(std::vector<int>, std::vector<std::string>);
    
    /* Start and stop game loop */
    void beginGame(void);
    void quitGame(void);
    void getPlayers(void);
    
private:
    int numPlayers{1};
    std::vector<int> playerAges;
    std::vector<std::string> playerNames;
    int gameLength{0};
    int seasonLength{0};
    bool gameStatus{false};
};
#endif /* Game_hpp */
//
//  Player.hpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <string>
#include "Farm.hpp"
#include "Market.hpp"

class Player : public Farm
{
public:
    Player();
    Player(int, std::string, int, int);
    ~Player();
    
    //* Getters / Setters *//
    
    int getPlayerNumber(void);
    void setPlayerNumber(int);
    
    /* Player name */
    std::string getPlayerName(void);
    void setPlayerName(std::string);
    
    /* Player age */
    int getPlayerAge(void);
    void setPlayerAge(int);
    
    /* Player gold */
    int getPlayerGold(void);
    void setPlayerGold(int);
    
    //* Methods *//
    
    void addGold(int);
    void removeGold(int);
    virtual void print(void);
    void printFarm(void);

    void buy(Market*, int);
    void sell(int);
    void useTool(int);
    
    
    
private:
    int playerNumber{0};
    std::string playerName{""};
    int playerAge{0};
    int playerGold{0};
    Card boughtCard;
    Farm playerFarm;
};

#endif /* Player_hpp */

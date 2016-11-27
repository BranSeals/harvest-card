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
    
    
private:
    int playerNumber{0};
    std::string playerName{""};
    int playerAge{0};
    int playerGold{0};
    Farm playerFarm;
};

#endif /* Player_hpp */

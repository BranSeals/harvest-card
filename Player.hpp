// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23
// Updated: 2017-05-26

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

    int getPlayerNumber(void);
    void setPlayerNumber(int);

    std::string getPlayerName(void);
    void setPlayerName(std::string);

    int getPlayerAge(void);
    void setPlayerAge(int);

    int getPlayerGold(void);
    void setPlayerGold(int);

    void addGold(int);
    void removeGold(int);
    virtual void print(void);
    void printFarm(void);

    void buy(Market*);
    void sellProduct();
	void work(void);
	int select(std::string, int, int);

	int advancePhase(void);
	int getPlayerPhase(void);
	void setPlayerPhase(int);
	virtual void refreshTools(void);
	void harvestCrops(int);
    
private:
    int playerNumber{0};
	int playerPhase{0};
    std::string playerName{""};
    int playerAge{0};
    int playerGold{0};
    Card boughtCard;
    Farm playerFarm;
};

#endif

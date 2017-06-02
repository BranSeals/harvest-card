// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-11-08

#ifndef Farm_hpp
#define Farm_hpp

#include <iostream>
#include <vector>
#include "Card.hpp"

class Farm
{
public:
    Farm();
    ~Farm();

    void addCard(Card);
    void removeCard(Card);
    virtual void print(void);
    std::vector<Card>* pointTo(std::string);
    void print(std::string);
    void printFarm(void);
    int sellProduct();
    void workFarm(int, int);
    int sizeOf(std::string);
    bool canSelectTool(int);
    virtual void refreshTools(void);
    virtual int harvest(int);

private:
    std::vector<Card> playerSeed;
    std::vector<Card> playerTool;
    std::vector<Card> playerLivestock;
    std::vector<Card> playerCrop;
    int seasonBonus{1};
};

#endif

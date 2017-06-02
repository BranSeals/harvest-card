// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23

#ifndef Season_hpp
#define Season_hpp

#include <vector>
#include "Deck.hpp"
#include "Card.hpp"

class Season : public Deck
{
public:
    Season();
    Season(size_t length);
    ~Season();

    std::vector<Card>* pointTo(int); // uses season int as input, so increment can happen in game loop

    int getDaysLeft(void);
    void setDaysLeft(int);

    int getCurrentSeason(void);
    void setCurrentSeason(int);

    int getSeasonLength(void);
    void setSeasonLength(int);

    void print(int);
    std::string printString(int);
    void printSeason(void);
    void resolveSeason(void);
    void fillSeasons(Deck*);
    int sizeOf(int);

private:
    std::vector<Card> springTime;
    std::vector<Card> summerTime;
    std::vector<Card> autumnTime;
    std::vector<Card> winterTime;
    int daysLeft{0};
    int currentSeason{0};
    size_t seasonLength{0};
};
#endif
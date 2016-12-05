//
//  Deck.hpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include "Card.hpp"
#include <vector>

class Deck : public Card
{
public:
    Deck();
    ~Deck();

    //* Getters / Setters *//

    unsigned long getDeckSize(void);

    //* Methods *//

    virtual void print(void);
    void print(std::string);
    void shuffleDecks(void);
    int dealCard(std::string);
    std::vector<int>* pointTo(std::string);
    void addCard(int);
    Card dealCardObject(std::string);
    void fillDecks(void);

private:
    std::vector<int> deck;
    std::vector<int> springDeck;
    std::vector<int> summerDeck;
    std::vector<int> autumnDeck;
    std::vector<int> winterDeck;
    std::vector<int> seedDeck;
    std::vector<int> toolDeck;
    std::vector<int> livestockDeck;
};

#endif /* Deck_hpp */

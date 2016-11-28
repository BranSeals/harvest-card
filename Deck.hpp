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
    void shuffleDeck(void);
    int dealCard(/*void*/std::vector<int>*);
	void addCard(int);
    Card dealCardObject(/*void*/std::vector<int>*);

	/* Experiment */
	int dealSeasonCard(void);
	int dealSeedCard(void);
	int dealToolCard(void);
	int dealLivestockCard(void);
	void fillDecks(void);
	void printSeedDeck(void);
    
private:
    std::vector<int> deck;

	/* Experiment */
	std::vector<int> seasonDeck;
	std::vector<int> seedDeck;
	std::vector<int> toolDeck;
	std::vector<int> livestockDeck;
};

#endif /* Deck_hpp */

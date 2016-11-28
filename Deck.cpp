//
//  Deck.cpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include "Deck.hpp"
#include "Card.hpp"
#include <iostream>

Deck::Deck()
{
}

Deck::~Deck()
{
}

unsigned long Deck::getDeckSize(void)
{
	return deck.size();
}

void Deck::addCard(int cardID)
{
    deck.push_back(cardID);
}

void Deck::print()
{
	std::cout << "\nDeck contents:\n";
    for (size_t i{0}; i < deck.size(); ++i) {
        std::cout << deck[i] << "\n";
    }
}

void Deck::shuffleDeck(void)
{
	// random shuffle
}

// Requires check when calling function to ensure cards exist in deck
int Deck::dealCard(void)
{
	int dealtCard{deck[deck.size() - 1]};
	deck.pop_back();
	return dealtCard;
}

Card Deck::dealCardObject(void)
{
	int dealtCard = dealCard();
	return Card(dealtCard);
}

/* Experiment - may be replaced by pointer-based dealing from market if it works */
int Deck::dealSeasonCard(void)
{
	int dealtCard{seasonDeck[seasonDeck.size() - 1]};
	seasonDeck.pop_back();
	return dealtCard;
}

int Deck::dealSeedCard(void)
{
	int dealtCard{seedDeck[seedDeck.size() - 1]};
	seedDeck.pop_back();
	return dealtCard;
}

int Deck::dealToolCard(void)
{
	int dealtCard{toolDeck[toolDeck.size() - 1]};
	toolDeck.pop_back();
	return dealtCard;
}

int Deck::dealLivestockCard(void)
{
	int dealtCard{livestockDeck[livestockDeck.size() - 1]};
	livestockDeck.pop_back();
	return dealtCard;
}

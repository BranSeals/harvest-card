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

int Deck::dealCard(void)
{
	if (deck.size() > 0) {
		int dealtCard{deck[deck.size() - 1]};
		deck.pop_back();
		return dealtCard;
	}
    std::cout << "\n*** Error: No cards in deck ***\n";
    return 0;
}

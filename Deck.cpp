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
int Deck::dealCard(std::vector<int>* deck)
{
	int dealtCard{(*deck)[(*deck).size() - 1]};
	(*deck).pop_back();
	return dealtCard;
}

Card Deck::dealCardObject(std::vector<int>* deck)
{
	int dealtCard = dealCard(deck);
	return Card(dealtCard);
}

/* Experiment - may be replaced by pointer-based dealing from market if it works */
int Deck::dealSeasonCard(void)
{
	return dealCard(&seasonDeck);
}

int Deck::dealSeedCard(void)
{
	return dealCard(&seedDeck);
}

int Deck::dealToolCard(void)
{
	return dealCard(&toolDeck);
}

int Deck::dealLivestockCard(void)
{
	return dealCard(&livestockDeck);
}

void Deck::fillDecks(void)
{
	int tempCard{0};
	while (deck.size() > 0) {
		tempCard = dealCard(&deck);
		if (tempCard < 5000) {
			seasonDeck.push_back(tempCard);
		} else if (tempCard < 6000) {
			seedDeck.push_back(tempCard);
		} else if (tempCard < 7000) {
			toolDeck.push_back(tempCard);
		} else if (tempCard < 8000) {
			livestockDeck.push_back(tempCard);
		} else {
			std::cout << "\n*** Error filling decks ***\n";
		}
	}
}
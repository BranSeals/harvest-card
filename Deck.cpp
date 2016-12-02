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
    std::cout << "\n-- Decks --";
    print("Main");
    print("Season");
    print("Seed");
    print("Tool");
    print("Livestock");
}

void Deck::print(std::string deckName)
{
    std::vector<int>* deckPtr{pointTo(deckName)};
    std::cout << "\n" << deckName << " Deck:\n";
    for (size_t i{0}; i < (*deckPtr).size(); ++i) {
        std::cout << (*deckPtr)[i] << "\n";
    }
}

void Deck::shuffleDecks(void)
{
    
}

// Reminder: check when calling function to ensure cards exist in deck
int Deck::dealCard(std::string deckName)
{
    std::vector<int>* deckPtr{pointTo(deckName)};

	if ((*deckPtr).size() == 0) {
		return 0;
	}

    int dealtCard{(*deckPtr)[(*deckPtr).size() - 1]};
    (*deckPtr).pop_back();
    return dealtCard;
}

std::vector<int>* Deck::pointTo(std::string deckName)
{
    if (deckName == "Main") {
        return &deck;
    } else if (deckName == "Season") {
        return &seasonDeck;
    } else if (deckName == "Seed") {
        return &seedDeck;
    } else if (deckName == "Tool") {
        return &toolDeck;
    } else if (deckName == "Livestock") {
        return &livestockDeck;
    } else {
        std::cout << "\n*** Error in Deck::pointTo() ***\n";
    }
}

Card Deck::dealCardObject(std::string deckName)
{
    int dealtCard = dealCard(deckName);
	if (dealtCard == 0) {
		std::cout << "\n*** No more cards in " << deckName << std::endl;
		return Card();
	}
    return Card(dealtCard);
}

void Deck::fillDecks(void)
{
    int tempCard{0};
    while (deck.size() > 0) {
        tempCard = dealCard("Main");
        if (tempCard < 5000) {
            seasonDeck.push_back(tempCard);
        } else if (tempCard < 6000) {
            seedDeck.push_back(tempCard);
        } else if (tempCard < 7000) {
            toolDeck.push_back(tempCard);
        } else if (tempCard < 8000) {
            livestockDeck.push_back(tempCard);
        } else {
            std::cout << "\n*** Error in fillDecks() ***\n";
        }
    }
}
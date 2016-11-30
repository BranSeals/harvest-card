//
//  Card.hpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <string>

class Card
{
public:
    Card();
	Card(int);
    ~Card();
    
    //* Getters / Setters *//

	/* ID of card */
	int getCardID(void);
	void setCardID(int);
    
    /* Name of card */
    std::string getCardName(void);
    void setCardName(std::string);
    
    bool isCardFaceUp(void);
    void setCardFaceUp(bool);
    
    /* Effect on card, referring to list of effects */
    int getCardEffect(void);
    void setCardEffect(int);

	/* Effect's target */
	int getCardTarget(void);
	void setCardTarget(int);

    /* Cost of card in Market */
    int getCardCost(void);
    void setCardCost(int);
    
    /* Value of card when sold */
    int getCardValue(void);
    void setCardValue(int);
    
    /* Description of card */
    std::string getCardDescription(void);
    void setCardDescription(std::string);

	/* Season of card */
	int getCardSeason(void);
	void setCardSeason(int);
    
    //* Methods *//
    
	void createByID(int);
    void flipCard(void);
	virtual void print(void);
	void resetCard(void);
    
private:
	int cardID{0};
    std::string cardName{""};
    bool cardFaceUp{false};
    int cardEffect{0};
	int cardTarget{0};
    int cardCost{0};
    int cardValue{0};
	int cardSeason{0};
    std::string cardDescription{""};
};

#endif /* Card_hpp */

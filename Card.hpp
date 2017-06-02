// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23

#ifndef Card_hpp
#define Card_hpp

#include <string>
#include <vector>
#include <sstream>
#include <istream>

class Card
{
public:
    Card();
    Card(int);
    ~Card();
    
    int getCardID(void) const;
    void setCardID(int);
    
    std::string getCardName(void);
    void setCardName(std::string);
    
    bool isCardFaceUp(void);
    void setCardFaceUp(bool);

    int getCardEffect(void);
    void setCardEffect(int);

    int getCardTarget(void);
    void setCardTarget(int);

    int getCardCost(void);
    void setCardCost(int);
    
    int getCardValue(void);
    void setCardValue(int);
    
    std::string getCardDescription(void);
    void setCardDescription(std::string);

    int getCardSeason(void);
    void setCardSeason(int);
    
    void createByID(int);
    void flipCard(void);
    virtual void print(void);
    void resetCard(void);
    std::vector<std::string> split(std::string);

    bool operator==(const Card& otherCard) const;
    bool operator!=(const Card& otherCard) const;
    
private:
    int cardID{0};
    std::string cardName{"Empty Card"};
    bool cardFaceUp{false};
    int cardEffect{0};
    int cardTarget{0};
    int cardCost{0};
    int cardValue{0};
    int cardSeason{0};
    std::string cardDescription{"If this card appears, a deck ran out of cards."};
};

#endif

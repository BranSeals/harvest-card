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
    ~Card();
    
    //* Getters / Setters *//
    
    /* Name of card */
    std::string getCardName(void);
    void setCardName(std::string);
    
    /* Effect on card, referring to list of effects */
    int getCardEffect(void);
    void setCardEffect(int);
    
    /* Cost of card in Market */
    int getCardCost(void);
    void setCardCost(int);
    
    /* Value of card when sold */
    int getCardValue(void);
    void setCardValue(int);
    
    /* Description of card */
    std::string getCardDescription(void);
    void setCardDescription(std::string);
    
    //* Methods *//
    
    
    
private:
    std::string cardName{""};
    int cardEffect{0};
    int cardCost{0};
    int cardValue{0};
    std::string cardDescription{""};
};

#endif /* Card_hpp */

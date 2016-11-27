//
//  Farm.hpp
//  harvest-card
//
//  Created by Brandon Seals on 11/8/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#ifndef Farm_hpp
#define Farm_hpp

#include <stdio.h>
#include "Deck.hpp"

class Farm : public Deck
{
public:
    Farm();
    ~Farm();

	virtual void print(void);

private:
	std::vector<int> deck;
};

#endif /* Farm_hpp */

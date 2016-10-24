//
//  Player.hpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <string>

class Player
{
public:
    Player();
    ~Player();
    
    //* Getters / Setters *//
    
    /* Player name */
    std::string getPlayerName(void);
    void setPlayerName(std::string);
    
    /* Player age */
    int getPlayerAge(void);
    void setPlayerAge(int);
    
    /* Player gold */
    int getPlayerGold(void);
    void setPlayerGold(int);
    
    //* Methods *//
    
    void addGold(int);
    void removeGold(int);
    
    
private:
    std::string playerName{""};
    int playerAge{0};
    int playerGold{0};
};

#endif /* Player_hpp */

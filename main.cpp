//
//  main.cpp
//  Harvest Game
//
//  Created by Brandon Seals on 10/22/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include <iostream>
#include <string>
#include "Game.hpp"

int main()
{
    Game HarvestGame;
    
    HarvestGame.beginGame();
    
    std::cout << "Hello, " << HarvestGame.getNumPlayers() << " player(s)!\n";
    
    while(HarvestGame.getGameStatus()) {
        std::cout << "\nSuccessful game start!\n";
        
        std::cout << HarvestGame.getPlayerName(0) << " " << HarvestGame.getPlayerAge(0) << std::endl;
        
        std::cout << "\nSuccessful game end!\n";
        HarvestGame.quitGame();
    } // end of game loop
    
    return 0;
}

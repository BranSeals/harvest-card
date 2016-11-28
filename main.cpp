/* Project name: Harvest Card Game
 * Author: Brandon Seals
 * Last revised: 2016-11-25
 * Description: CLI version of farming card game
 */

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Market.hpp"
//#include <direct.h>

/* Functions */
void sortPlayers(std::vector<int>*, std::vector<std::string>*);
bool confirmYN(std::string);
std::string current_working_directory(void);

/* Constants */
const std::string gameTitle{"Harvest Card Game"};
const std::string gameDescription{"A terminal-based farming card game for 1 - 4 players.\n"};
const int seasonLength{0};
const int gameLength{seasonLength * 4};
const int startingGold{100};

int main()
{
    /* Player variables */
    int numPlayers{0};
    int age{0};
    std::vector<int> playerAges;
    std::string name{""};
    std::vector<std::string> playerNames;
	Player Player1, Player2, Player3, Player4;
	std::vector<int>* playerAgesPtr{nullptr};
	std::vector<std::string>* playerNamesPtr{nullptr};

	/* Game variables */
	bool gameStatus{false};
	//char ynAnswer{'n'};
	int currentPlayer{0};
	int currentPhase{0};
	Deck allCards;

	/* Season decks */
	Deck springDeck;
	Deck summerDeck;
	Deck autumnDeck;
	Deck winterDeck;

	/* Market decks */
	Deck seedDeck;
	Deck toolDeck;
	Deck livestockDeck;

	/* Testing */
	/*Player testPlayer;
	testPlayer.takeCard(5101);
    std::cout << "\ntestPlayer Farm:" << std::endl;
	testPlayer.printFarm();*/
	//printf(" %s", _fullpath(NULL, "cards.txt", 40));
	//std::cout << current_working_directory();

	/*Deck testDeck;
	testDeck.addCard(5101);
	testDeck.addCard(5100);
	testDeck.print();*/
	/*std::cout << std::endl;
	int card = testDeck.dealCard();
	testDeck.print();
	std::cout << std::endl;
	int card2 = testDeck.dealCard();
	testDeck.print();*/
	//std::cout << std::endl;

	/*Farm testFarm;
	testFarm.addCard(5101);
	testFarm.addCard(5101);
	testFarm.addCard(5101);
	testFarm.print();*/
	
	/*std::cout << testFarm.getDeckSize();*/

	/*Card testCard(5101);
	std::cout << "\n" << testCard.getCardID() << std::endl;
	std::cout << testCard.getCardSeason() << std::endl;
	std::cout << testCard.getCardName() << std::endl;
	std::cout << testCard.getCardDescription() << std::endl;
	std::cout << testCard.getCardEffect() << std::endl;
	std::cout << testCard.getCardValue() << std::endl;
	std::cout << testCard.getCardCost() << std::endl;
	testCard.print();*/

	/* Opening dialogue */
	std::cout << "\n-- " << gameTitle << " --\n";
	std::cout << gameDescription;

    /* Get number of players */
    do {
        std::cout << "\nHow many players are there? [1-4]: ";
        std::cin >> numPlayers;
        std::cin.clear();
        std::cin.ignore();
    } while ((numPlayers < 1) || (numPlayers > 4));
    
    for (size_t i{1}; i <= numPlayers; ++i) {
        std::cout << "\nWhat is player " << i << "'s name?: ";
        std::cin >> name;
        do {
            std::cout << "What is player " << i << "'s age?: ";
            std::cin >> age;
            std::cin.clear();
            std::cin.ignore();
        } while ((numPlayers < 1) || (numPlayers > 150));
        playerAges.push_back(age);
        playerNames.push_back(name);
    }

	/* Sort players by age and name (youngest first, then alphabetically) */
	if (numPlayers > 1) {
		playerAgesPtr = &playerAges;
		playerNamesPtr = &playerNames;
		sortPlayers(playerAgesPtr, playerNamesPtr);
	}
    
    /* Create players sorted by age */
	Player1.setPlayerNumber(1);
	Player1.setPlayerName(playerNames[0]);
	Player1.setPlayerAge(playerAges[0]);
	Player1.setPlayerGold(startingGold);

    if (numPlayers > 1) {
		Player2.setPlayerNumber(2);
		Player2.setPlayerName(playerNames[1]);
		Player2.setPlayerAge(playerAges[1]);
		Player2.setPlayerGold(startingGold);
    }
    if (numPlayers > 2) {
		Player3.setPlayerNumber(3);
		Player3.setPlayerName(playerNames[2]);
		Player3.setPlayerAge(playerAges[2]);
		Player3.setPlayerGold(startingGold);
    }
    if (numPlayers > 3) {
		Player4.setPlayerNumber(4);
		Player4.setPlayerName(playerNames[3]);
		Player4.setPlayerAge(playerAges[3]);
		Player4.setPlayerGold(startingGold);
    }
    
	/* Print player information */
	std::cout << "\n-- Player list --\n";
	std::cout << "Younger players will go first.\n";
    Player1.print();
	if (numPlayers > 1) {
		Player2.print();
	}
	if (numPlayers > 2) {
		Player3.print();
	}
	if (numPlayers > 3) {
		Player4.print();
	}
    
	/* Fill decks */
	std::cout << "\n> Filling decks...\n";

	/* Shuffle decks */
	std::cout << "\n> Shuffling decks...\n";

	/* Verify game start */
	if (confirmYN("\nBegin game? [y/n]: ")) {
		std::cout << "\n> Beginning game...\n";
		gameStatus = true;
	} else {
		std::cout << "\n> Quitting game...\n";
		gameStatus = false;
		return 0;
	}
    
    /* Game loop */
    // TODO: conditionals in loop using currentPhase and currentPlayer
    // TODO: allow quitting at certain point in loop
    while (gameStatus) {
		std::cout << "\n> Game loop success!\n";
		Player1.print();
        // if currentPhase == season
        // if currentPhase == market
        // if currentPhase == farm
		gameStatus = false;
    } // end game loop
    
    return 0;
}

/* Function definitions */
void sortPlayers(std::vector<int>* agesPtr, std::vector<std::string>* namesPtr)
{
	bool sortedAge{false};
	bool sortedName{false};

	while (!sortedAge || !sortedName) {

		/* Sort by age value first */
		for (size_t i{1}; i < (*agesPtr).size(); ++i) {

			if ((*agesPtr)[i] < (*agesPtr)[i - 1]) {
				std::swap((*agesPtr)[i], (*agesPtr)[i - 1]);
				std::swap((*namesPtr)[i], (*namesPtr)[i - 1]);
			}
		}
		/* Then sort by name */
		for (size_t i{1}; i < (*agesPtr).size(); ++i) {
			if (((*agesPtr)[i] == (*agesPtr)[i - 1])
				&& ((*namesPtr)[i] < (*namesPtr)[i - 1])) {
				std::swap((*agesPtr)[i], (*agesPtr)[i - 1]);
				std::swap((*namesPtr)[i], (*namesPtr)[i - 1]);
			}
		}

		/* Verify age and name values are sorted; if not, re-loop */
		for (size_t j{1}; j < (*agesPtr).size(); ++j) {
			if ((*agesPtr)[j] < (*agesPtr)[j - 1]) {
				sortedAge = false;
				break;
			}
			if (((*agesPtr)[j] == (*agesPtr)[j - 1])
				&& ((*namesPtr)[j] < (*namesPtr)[j - 1])) {
				sortedName = false;
				break;
			}
			sortedAge = true;
			sortedName = true;
		}
	}
}

bool confirmYN(std::string message)
{
	char ynAnswer{};
	while ((tolower(ynAnswer) != 'n') || (tolower(ynAnswer)) != 'y') {
		std::cout << message;
		std::cin >> ynAnswer;
		std::cin.clear();
		std::cin.ignore();
		if (tolower(ynAnswer) == 'y') {
			return true;
		} else if (tolower(ynAnswer) == 'n') {
			return false;
		} else {
			std::cout << "\n*** Answer must be 'y' or 'n' ***\n";
		}
	}
    return false;
}

//std::string current_working_directory()
//{
//	char* cwd = _getcwd(0, 0); // **** microsoft specific ****
//	std::string working_directory(cwd);
//	std::free(cwd);
//	return working_directory;
//}

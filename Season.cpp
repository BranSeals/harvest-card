// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23

/* TO DO : make sure that season and market are pulling from the same deck
   that will be supplied by the game object / or main function */

#include "Season.hpp"
#include "Card.hpp"
#include <iostream>
#include <iomanip>

Season::Season()
{
}

Season::Season(size_t length) : seasonLength{length}
{
}

Season::~Season()
{
}

std::vector<Card>* Season::pointTo(int season)
{
    if (season == 1) {
        return &springTime;
    } else if (season == 2) {
        return &summerTime;
    } else if (season == 3) {
        return &autumnTime;
    } else if (season == 4) {
        return &winterTime;
    } else {
        std::cout << "\n*** Error in Season::pointTo() ***\n";
        return nullptr;
    }
}

int Season::getDaysLeft(void)
{

    return daysLeft;
}

void Season::setDaysLeft(int days)
{
    daysLeft = days;
}

int Season::getCurrentSeason(void)
{
    return currentSeason;
}

void Season::setCurrentSeason(int season)
{
    currentSeason = season;
}

int Season::getSeasonLength(void)
{
	return seasonLength;
}

void Season::setSeasonLength(int length)
{
	seasonLength = length;
}

void Season::print(int season)
{
	std::vector<Card>* seasonPtr{pointTo(season)};
	std::string seasonName;
	switch (season) {
	case (1):
		seasonName = "Spring";
		break;
	case (2):
		seasonName = "Summer";
		break;
	case (3):
		seasonName = "Autumn";
		break;
	case (4):
		seasonName = "Winter";
		break;
	}
}

std::string Season::printString(int season)
{
	std::vector<Card>* seasonPtr{pointTo(season)};
	switch (season) {
	case (1):
		return "Spring";
		break;
	case (2):
		return "Summer";
		break;
	case (3):
		return "Autumn";
		break;
	case (4):
		return "Winter";
		break;
	}
}

void Season::printSeason(void)
{
    std::vector<Card>* seasonPtr{pointTo(currentSeason)};

    /* Top bar */
    std::cout << std::left;
    std::cout << std::endl;
    std::cout.fill('-');
    std::cout << std::setw(50) << "-- Season ";
    std::cout.fill(' ');
	std::cout << std::endl;

	std::cout << printString(currentSeason) << " - Day "
		<< seasonLength - daysLeft << " of " << seasonLength << std::endl;
    std::cout << (*seasonPtr)[(*seasonPtr).size() - 1].getCardName()
		<< "\n" << (*seasonPtr)[(*seasonPtr).size() - 1].getCardDescription() << std::endl;

    /* Bottom bar */
    std::cout.fill('-');
	std::cout << std::setw(50) << "";
	std::cout.fill(' ');
	std::cout << std::endl;
}

void Season::resolveSeason(void)
{
	std::vector<Card>* seasonPtr{pointTo(currentSeason)};
	printSeason();
	(*seasonPtr).pop_back();
}

void Season::fillSeasons(Deck* deck)
{
    while (springTime.size() < seasonLength) {
        springTime.push_back((*deck).dealCardObject("Spring"));
    }
    while (summerTime.size() < seasonLength) {
        summerTime.push_back((*deck).dealCardObject("Summer"));
    }
    while (autumnTime.size() < seasonLength) {
        autumnTime.push_back((*deck).dealCardObject("Autumn"));
    }
    while (winterTime.size() < seasonLength) {
        winterTime.push_back((*deck).dealCardObject("Winter"));
    }
}

int Season::sizeOf(int season)
{
	std::vector<Card>* seasonPtr{pointTo(season)};
	return (*seasonPtr).size();
}
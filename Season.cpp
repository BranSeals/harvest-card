/* TO DO : make sure that season and market are pulling from the same deck
   that will be supplied by the game object / or main function */

#include "Season.hpp"
#include "Card.hpp"
#include <iostream>
#include <iomanip>

Season::Season(int length) : seasonLength{length}
{

}

Season::~Season()
{

}

std::vector<Card>* Season::pointTo(int currentSeason)
{
  if (currentSeason == 1) {
      return &springTime;
  } else if (currentSeason == 2) {
      return &summerTime;
  } else if (currentSeason == 3) {
      return &autumnTime;
  } else if (currentSeason == 4) {
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

  std::cout << (*seasonPtr).getCardName() << " - Day "                          // DAYS LEFT NEEDS TESTING
      << seasonLength - daysLeft + 1 << " of " << seasonLength
      << "\n" << (*seasonPtr).getCardDescription() << std::endl;

  /* Bottom bar */
  std::cout.fill('-');
	std::cout << std::setw(50) << "";
	std::cout.fill(' ');
}

void Season::resolveSeason(void)
{
    std::cout << "\n> Season did a thing.\n";
}

void Season::fillSeasons(void)
{
    while (springTime.size() < seasonLength) {
        springTime.push_back(dealCardObject("Spring"));
    }
    while (summerTime.size() < seasonLength) {
        summerTime.push_back(dealCardObject("Summer"));
    }
    while (autumnTime.size() < seasonLength) {
        autumnTime.push_back(dealCardObject("Autumn"));
    }
    while (winterTime.size() < seasonLength) {
        winterTime.push_back(dealCardObject("Winter"));
    }
}

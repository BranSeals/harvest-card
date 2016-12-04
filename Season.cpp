/* TO DO : make sure that season and market are pulling from the same deck
   that will be supplied by the game object / or main function */

#include "Season.hpp"
#include "Card.hpp"
#include <iostream>

Season(int length) : seasonLength{length}
{

}

~Season()
{

}

std::vector<Card>* pointTo(int season)
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
      std::cout << "\n*** Error in Market::pointTo() ***\n";
      return nullptr;
  }
}

int getDaysLeft(void)
{
  return daysLeft;
}

void setDaysLeft(int days)
{
  daysLeft = days;
}

void printSeason(void)
{

}

void fillSeasons(void)
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

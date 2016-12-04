// needs to be constructed with season length defined

#ifndef Season_hpp
#define Season_hpp

#include "Deck.hpp"
#include "Card.hpp"

class Season : public Deck
{
public:
  Season(int length);
  ~Season();

  std::vector<Card>* pointTo(int); // uses season int as input, so increment can happen in game loop

  int getDaysLeft(void);
  void setDaysLeft(int);

  void printSeason(void);
  void fillSeasons(void);

private:
  std::vector<Card> springTime;
  std::vector<Card> summerTime;
  std::vector<Card> autumnTime;
  std::vector<Card> winterTime;
  int daysLeft{0};
  int currentSeason{0};
  int seasonLength{0};
};

#endif

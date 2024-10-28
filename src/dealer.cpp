#include<iostream>

#include "deck.h"
#include "dealer.h"

using std::string, std::cout, std::to_string;

class Dealer::DealerDeck : Deck
{
  public:
    DealerDeck()
    {
      Deck();
    }
};

Dealer::Dealer()
{
  this->SETButtonPositions(1, 2, 3);
}

string Dealer::GETButtonPositions()
{
  string buttons = to_string(buttonPositions[0]) + to_string(buttonPositions[1]) + to_string(buttonPositions[2]);
  return buttons;
}

void Dealer::SETButtonPositions(int dPos, int lbPos, int bbPos)
{
  this->buttonPositions[0] = dPos;
  this->buttonPositions[1] = lbPos;
  this->buttonPositions[2] = bbPos;
}

void Dealer::preHandCheck()
{
  // TODO: Check if its time to start a new hand and return true or false and pass it to Hand function
  this->Hand(true);
}

int Dealer::Hand(bool isTime)
{
  if(!isTime)
  {
    return 0;
  }


  return 1;
}
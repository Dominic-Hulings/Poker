//#include <iostream>
#include <vector>
//#include <array>

#include "dealer.h"
#include "deck.h"
#include "global.h"

using std::string, std::vector;

typedef CT::Card Card;

Dealer::Dealer()
{
  Deck deck;

  for (int counter = 0; counter < 52; counter++)
  {
    DealerDeck.push(deck.GETTopMainDeck());
  }

  this->SETButtonPositions(2);
}

void Dealer::SETplayersToDeal(int players)
{
  this->playersToDeal = players;
}

int Dealer::GETButtonPositions()
{
  int buttons = buttonPosition;
  return buttons;
}

void Dealer::SETButtonPositions(int buttonPos)
{
  this->buttonPosition = buttonPos;
}

void Dealer::preHandCheck(void* p2pPlayerIDsVec)
{
  // TODO: Check if its time to start a new hand and return true or false and pass it to Hand function
  this->Hand(true, p2pPlayerIDsVec);
}

int Dealer::Hand(bool isTimeToDeal, void* p2pPlayerIDsVec)
{
  if (!isTimeToDeal)
  {
    return 0;
  }

  vector<>
  int counter = 0;

  for(int players = playersToDeal; players; players--)
  {

  }


  

  return 1;
}
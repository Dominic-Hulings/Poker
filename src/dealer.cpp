//#include <iostream>
//#include <vector>
#include <array>

#include "dealer.h"
#include "deck.h"
#include "global.h"

using std::string;

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

void Dealer::preHandCheck()
{
  // TODO: Check if its time to start a new hand and return true or false and pass it to Hand function
  this->Hand(true);
}

int Dealer::Hand(bool isTimeToDeal)
{
  if (!isTimeToDeal)
  {
    return 0;
  }

  int counter = 0;

  for(int players = playersToDeal; players; players--)
  {
    
  }


  

  return 1;
}
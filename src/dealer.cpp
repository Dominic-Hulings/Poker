#include <iostream>

#include "dealer.h"
#include "deck.h"

using std::string, std::to_string, std::cout;

Dealer::Dealer()
{
  Deck deck;

  for (int counter = 0; counter < 52; counter++)
  {
    DealerDeck.push(deck.GETTopMainDeck());
  }

  this->SETButtonPositions(1, 2, 3);
}

void Dealer::SETplayersToDeal(int players)
{
  this->playersToDeal = players;
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

int Dealer::Hand(bool isTimeToDeal)
{
  if (!isTimeToDeal)
  {
    return 0;
  }

  

  return 1;
}
#include <iostream>
#include <vector>
//#include <array>

#include "dealer.h"
#include "deck.h"
#include "player.h"
#include "global.h"

using std::string, std::vector, std::cout;

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

void Dealer::preHandCheck(std::vector<Player*>* p2pPlayerIDsVec)
{
  // TODO: Check if its time to start a new hand and return true or false and pass it to Hand function
  this->Hand(true, p2pPlayerIDsVec);
}

int Dealer::Hand(bool isTimeToDeal, std::vector<Player*>* p2pPlayerIDsVec)
{
  if (!isTimeToDeal)
  {
    return 0;
  }

  vector<Player*> turnOrder;
  int counter = 0;

  for(int players = playersToDeal - 1; players; players--)
  {
    turnOrder.push_back(p2pPlayerIDsVec->at(counter));
    counter++;
  }

  for(Player* player : turnOrder)
  {
    cout << player->GETuserName() << " " << player->GETplayerID() << "\n";
  }
  

  return 1;
}
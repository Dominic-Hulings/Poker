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

  this->SETbuttonPosition(0);
}

int Dealer::CheckIfNeg(int num, int replaceNumIfNeg)
{
  if(num < 0)
  {
    return replaceNumIfNeg;
  }

  else
  {
    return num;
  }
}

int Dealer::GETButtonPosition()
{
  return buttonPosition;
}

void Dealer::SETplayersToDeal(int players)
{
  this->playersToDeal = players;
}

void Dealer::SETbuttonPosition(int inButtonPos)
{
  buttonPosition = CheckIfNeg(inButtonPos, playersToDeal);
}

void Dealer::preHandCheck(std::vector<Player*>* p2pPlayerIDsVec)
{
  // TODO: Check if its time to start a new hand and return true or false and pass it to Hand function
  this->Hand(true, p2pPlayerIDsVec);
}

int Dealer::Hand(bool isTimeToDeal, std::vector<Player*>* p2pPlayerIDsVec)
{
  //* DEAL CARDS TO PLAYERS {
  if (!isTimeToDeal)
  {
    return 0;
  }

  vector<Player*> playersVec;
  int counter = 0;

  for(int players = playersToDeal + 1; players; players--)
  {
    playersVec.push_back(p2pPlayerIDsVec->at(counter));
    counter++;
  }

  int playerBeingDealt, toAct = CheckIfNeg(buttonPosition - 1, playersToDeal);

  do
  {
    playersVec.at(playerBeingDealt)->GIVEplayerCard(DealerDeck.top());
    DealerDeck.pop();
    playerBeingDealt = CheckIfNeg(playerBeingDealt - 1, playersToDeal);
  }
  while(playersVec.at(buttonPosition)->GETplayerHand().second.second == "clear");
  //* DEAL CARDS TO PLAYERS }



  //* PLAY HAND {

  

  //* PLAY HAND }
  

  return 1;
}

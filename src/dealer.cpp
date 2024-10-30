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

  this->SETButtonPosition(0);
}

void Dealer::SETplayersToDeal(int players)
{
  this->playersToDeal = players;
}

int Dealer::GETButtonPosition()
{
  return buttonPosition;
}

void Dealer::SETButtonPosition(int buttonPos)
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

  vector<Player*> playersVec;
  int counter = 0;

  for(int players = playersToDeal - 1; players; players--)
  {
    playersVec.push_back(p2pPlayerIDsVec->at(counter));
    counter++;
  }

  playersVec.at(playerToDeal)->GIVEplayerCard(DealerDeck.top());
  playerToDeal--;
  DealerDeck.pop();
  
  for(int playerToDeal; !(playerToDeal == playerFirstDealt); playerToDeal--)
  {
    if(buttonPosition == -1)
    {
      buttonPosition = playersToDeal - 1;
    }

    playersVec.at(playerToDeal)->GIVEplayerCard(DealerDeck.top());
    playerToDeal--;
    DealerDeck.pop();
  }

  playersVec.at(playerToDeal)->GIVEplayerCard(DealerDeck.top());
  playerToDeal--;
  DealerDeck.pop();
  
  for(int playerToDeal; !(playerToDeal == playerFirstDealt); playerToDeal--)
  {
    if(buttonPosition == -1)
    {
      buttonPosition = playersToDeal - 1;
    }
    
    playersVec.at(playerToDeal)->GIVEplayerCard(DealerDeck.top());
    playerToDeal--;
    DealerDeck.pop();
  }

  for(Player* player : playersVec)
  {
    cout << player->GETuserName() << " " << player->GETplayerID() << "\n";
    cout << player->playerHand.first.first << player->playerHand.first.second << "\n";
    cout << player->playerHand.second.first << player->playerHand.second.second << "\n";
  }
  
  return 1;
}

/*
for(Player* player : turnOrder)
  {
    cout << player->GETuserName() << " " << player->GETplayerID() << "\n";
  }
*/
#include <iostream>
#include <vector>
//#include <array>

#include "dealer.h"
#include "deck.h"
#include "player.h"
#include "global.h"

using std::string, std::vector, std::cout, std::cin;

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

std::pair<int, int> Dealer::GETblinds()
{
  return {this->littleBlind, this->bigBlind};
}

void Dealer::SETplayersToDeal(int players)
{
  this->playersToDeal = players;
}

void Dealer::SETbuttonPosition(int inButtonPos)
{
  buttonPosition = CheckIfNeg(inButtonPos, playersToDeal);
}

void Dealer::SETblinds(std::pair<int, int> blinds)
{
  this->littleBlind = blinds.first;
  this->bigBlind = blinds.second;
}

void Dealer::preHandCheck(std::vector<Player*>* p2pPlayerIDsVec)
{
  // TODO: Check if its time to start a new hand and return true or false and pass it to Hand function
  this->Hand(true, p2pPlayerIDsVec);
}

Player* Dealer::Hand(bool isTimeToDeal, std::vector<Player*>* p2pPlayerIDsVec)
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

  int playerBeingDealt = CheckIfNeg(buttonPosition - 1, playersToDeal);
  int toAct = CheckIfNeg(buttonPosition - 1, playersToDeal);

  do
  {
    playersVec.at(playerBeingDealt)->GIVEplayerCard(DealerDeck.top());
    playersVec.at(playerBeingDealt)->turnOver = false;
    DealerDeck.pop();
    playerBeingDealt = CheckIfNeg(playerBeingDealt - 1, playersToDeal);
  }

  while(playersVec.at(buttonPosition)->GETplayerHand().second.second == "clear");
  //* DEAL CARDS TO PLAYERS }

  //* FORCE BLINDS OUT {

  playersVec.at(toAct)->blindInput(GETblinds().second, 1);
  playersVec.at(CheckIfNeg(toAct - 1, playersToDeal))->blindInput(GETblinds().second, 2);

  //* FORCE BLINDS OUT }

  //* PLAY HAND {

  bool wasBet = false;
  string x;
  int toCall;
  int amt = 0;

  while(true)
  {
    if(playersVec.at(toAct)->turnOver == true)
    {
      break;
    }


    if(!wasBet)
    {
      cout << "It's " << playersVec.at(toAct)->GETuserName() << "'s turn\n";
      cout << "Type check, bet, or fold: ";
      cin >> x;

      if(x == "check")
      {
        cout << "check\n";
        playersVec.at(toAct)->turnOver = true;
      }

      else if(x == "bet")
      {
        cout << "How much: ";
        cin >> amt;
        for(Player* player : playersVec)
        {
          player->turnOver = false;
        }
        playersVec.at(toAct)->turnOver = true;
        toCall = amt;
      }

      else if(x == "fold")
      {
        cout << "fold";
        playersVec.erase(playersVec.begin() + toAct);
        playersToDeal--;
        if(playersToDeal == 0)
        {
          return playersVec.at(toAct);
        }
      }

      else
      {
        cout << "input not recognized\n";
        playersVec.at(toAct)->turnOver = true;
      }
    }

    else
    {
      cout << "It's " << playersVec.at(toAct)->GETuserName() << "'s turn\n";
      cout << "Type call, raise, or fold: ";
      cin >> x;

      if(x == "call")
      {
        cout << "call";
      }

      else if(x == "raise")
      {
        cout << "raise";
      }

      else if(x == "fold")
      {
        cout << "fold";
        playersVec.erase(playersVec.begin() + toAct);
        playersToDeal--;
        if(playersToDeal == 0)
        {
          return playersVec.at(toAct);
        }
      }

      else
      {
        cout << "input not recognized\n";
        playersVec.at(toAct)->turnOver = true;
      }
    }

    toAct = CheckIfNeg(toAct - 1, playersToDeal);
  }



  //* PLAY HAND }
  

  return playersVec.at(toAct);
}

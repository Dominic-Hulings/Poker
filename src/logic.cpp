#include <iostream>
#include <string>
#include <vector>

#include "logic.h"

using std::string, std::cout, std::cin, std::vector;

PokerLog::PokerLog()
{

}

void PokerLog::AllPhases()
{

}

void PokerLog::Action()
{
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
          //return playersVec.at(toAct);
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
          //return playersVec.at(toAct);
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
}

void PokerLog::Flop()
{

}

void PokerLog::Turn()
{

}

void PokerLog::River()
{

}
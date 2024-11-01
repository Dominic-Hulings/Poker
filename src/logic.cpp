#include <iostream>
#include <string>
#include <vector>

#include "logic.h"

using std::string, std::cout, std::cin;

PokerLog::PokerLog()
{

}

void PokerLog::AllPhases()
{
  int pot = littleBlind + bigBlind;
  Action();
  //Flop();
}

bool PokerLog::onePlayerLeft()
{
  return playersToDeal == 0;
}

void PokerLog::Winner(Player* player, int amtWon)
{
  cout << player->GETuserName() << " won " << amtWon << "!\n";
  player->SETplayerStack(pot, false);
}

void PokerLog::Action()
{
  bool wasBet = false;
  string x;
  int toCall = 0;
  int amt = 0;
  int inAmt = 0;

  cout << toAct << "\n";
  cout << wasBet << "\n";
  cout << toCall << "\n";
  cout << amt << "\n";
  cout << inAmt << "\n";
}
/*
  while (true)
  {
    if (playersVec.at(toAct)->turnOver == true)
    {
      break;
    }

    if (!wasBet)
    {
      cout << "It's " << playersVec.at(toAct)->GETuserName() << "'s turn\n";
      cout << "Type check, bet, or fold: ";
      cin >> x;

      if (x == "check")
      {
        cout << "check\n";
        playersVec.at(toAct)->turnOver = true;
      }

      else if (x == "bet")
      {
        cout << "bet\n";
        cout << "How much: ";
        cin >> inAmt;

        if (playersVec.at(toAct)->GETplayerStack() < inAmt)
        {
          cout << "You don't have that much to bet\n";
          continue;
        }

        for (Player *player : playersVec)
        {
          player->turnOver = false;
        }

        amt = inAmt;
        pot += amt;
        playersVec.at(toAct)->SETplayerStack(amt, true);
        playersVec.at(toAct)->turnOver = true;
      }

      else if (x == "fold")
      {
        cout << "fold";
        playersVec.erase(playersVec.begin() + toAct);
        playersToDeal--;
        if(onePlayerLeft())
        {
          Winner(playersVec.at(toAct), pot);
        }
      }

      else
      {
        cout << "input not recognized. Try again\n";
        continue;
      }
    }

    else
    {
      toCall = amt - playersVec.at(toAct)->amtInPot;
      cout << "It's " << playersVec.at(toAct)->GETuserName() << "'s turn\n";
      cout << "It's " << toCall << " to call.";
      cout << "Type call, raise, or fold: ";
      cin >> x;

      if (x == "call")
      {
        cout << "call";
        if (playersVec.at(toAct)->GETplayerStack() < toCall)
        {
          cout << "You don't have enough to call\n";
          continue;
        }

        pot += toCall;
        playersVec.at(toAct)->SETplayerStack(toCall, true);
        playersVec.at(toAct)->turnOver = true;        

      }

      else if (x == "raise")
      {
        cout << "raise\n";
        cout << "How much: ";
        cin >> inAmt;

        if (playersVec.at(toAct)->GETplayerStack() < amt + inAmt)
        {
          cout << "You don't have that much to bet\n";
          continue;
        }

        for (Player *player : playersVec)
        {
          player->turnOver = false;
        }

        amt += inAmt;
        playersVec.at(toAct)->SETplayerStack(amt, true);
        playersVec.at(toAct)->turnOver = true;

      }

      else if (x == "fold")
      {
        cout << "fold";
        playersVec.erase(playersVec.begin() + toAct);
        playersToDeal--;
        if(onePlayerLeft())
        {
          Winner(playersVec.at(toAct), pot);
        }
      }

      else
      {
        cout << "input not recognized. Try again\n";
        continue;
      }
    }

    toAct = CheckIfNeg(toAct - 1, playersToDeal);
  }
}

void PokerLog::Flop()
{
  cout << "Going to flop\n";
}

void PokerLog::Turn()
{
}

void PokerLog::River()
{
} */
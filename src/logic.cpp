#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "logic.h"

using std::string, std::cout, std::cin, std::vector, std::pair;

PokerLog::PokerLog(Dealer* inpDealer, int inToAct, std::vector<Player*>* inpPlayersVec, int inPlayersToDeal, int inLittleBlind, int inBigBlind)
{
  this->toAct = inToAct;
  this->littleBlind = inLittleBlind;
  this->bigBlind = inBigBlind;
  this->playersToDeal = inPlayersToDeal;
  this->playersVec = *inpPlayersVec;
  this->pMyDealer = inpDealer;
}

int PokerLog::CheckIfNeg(int num, int replaceNumIfNeg)
{
  if (num < 0)
  {
    return replaceNumIfNeg;
  }

  else
  {
    return num;
  }
}

vector<int> PokerLog::ConvertValueToNum(vector<string> values)
{
  vector<int> cardValueVec;

  for (int counter = 0; counter < 7; counter++)
  {
    auto cardValue = find(Values, Values + 13, values[counter]);
    int index = cardValue - Values;
    cardValueVec.push_back(index);
  }

  sort(cardValueVec.begin(), cardValueVec.end());
  return cardValueVec;
}

void PokerLog::AllPhases()
{
  int pot = littleBlind + bigBlind;
  Action();
  Flop();
  Action();
  Turn();
  Action();
  River();
  Action();
  WhoWon(playersVec, pMyDealer->GETfield());
}

void PokerLog::PrintField()
{
  cout << "-------------FIELD-------------\n";
  for(int counter = 0; counter < pMyDealer->GETfield().size(); counter++)
  {
    cout << pMyDealer->GETfield().at(counter).first << " of " << pMyDealer->GETfield().at(counter).second << "\n";
  }
  cout << "-------------FIELD-------------\n";
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
  bool canCheck = false;
  string x;
  int toCall = 0;
  int amt = 0;
  int inAmt = 0;

  for (Player *player : playersVec)
  {
    player->turnOver = false;
  }

  while (true)
  {
    if (playersVec.at(toAct)->turnOver == true)
    {
      break;
    }

    cout << "--------------------------------\n";
    cout << "Your stack: " << playersVec.at(toAct)->GETplayerStack() << "\n";
    cout << "Amount you have in the pot: " << playersVec.at(toAct)->amtInPot << "\n\n";

    cout << "Your hand is: " << playersVec.at(toAct)->GETplayerHand().first.first << " of " << playersVec.at(toAct)->GETplayerHand().first.second;
    cout << "\nAnd: " << playersVec.at(toAct)->GETplayerHand().second.first << " of " << playersVec.at(toAct)->GETplayerHand().second.second;
    cout << "\n\n";
    
    if (!wasBet)
    {
      toCall = bigBlind - playersVec.at(toAct)->amtInPot;

      if(toCall == 0)
      {
        canCheck = true;
        cout << "It's " << playersVec.at(toAct)->GETuserName() << "'s turn\n";
        cout << "Type check, bet, field, or fold: ";
      }

      else
      {
        canCheck = false;
        cout << "It's " << playersVec.at(toAct)->GETuserName() << "'s turn\n";
        cout << "It's " << toCall << " to call.\n";
        cout << "Type bet, call, field, or fold: ";
      }

      cin >> x;

      if (x == "check" && canCheck)
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

        amt = inAmt + playersVec.at(toAct)->amtInPot;
        pot += amt;
        playersVec.at(toAct)->SETplayerStack(amt, true);
        playersVec.at(toAct)->turnOver = true;
        playersVec.at(toAct)->amtInPot = amt;
        wasBet = true;
      }

      else if (x == "call" && !canCheck)
      {
        cout << "call\n";
        if (playersVec.at(toAct)->GETplayerStack() < toCall)
        {
          cout << "You don't have enough to call\n";
          continue;
        }

        pot += toCall;
        playersVec.at(toAct)->SETplayerStack(toCall, true);
        playersVec.at(toAct)->turnOver = true;
        playersVec.at(toAct)->amtInPot += toCall;        

      }

      else if (x == "fold")
      {
        cout << "fold\n";
        playersVec.erase(playersVec.begin() + toAct);
        playersToDeal--;
        if(onePlayerLeft())
        {
          Winner(playersVec.at(toAct), pot);
        }
      }

      else if(x == "field")
      {
        PrintField();
        continue;
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
      cout << "It's " << toCall << " to call.\n";
      cout << "Type call, raise, field, or fold: ";
      cin >> x;

      if (x == "call")
      {
        cout << "call\n";

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

      else if(x == "field")
      {
        PrintField();
        continue;
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
  cout << "\nGoing to flop\n\n";
  pMyDealer->PlayCardsToField(3);
  PrintField();
}

void PokerLog::Turn()
{
  cout << "\nGoing to turn\n\n";
  pMyDealer->PlayCardsToField(1);
  PrintField();
}

void PokerLog::River()
{
  cout << "\nGoing to river\n\n";
  pMyDealer->PlayCardsToField(1);
  PrintField();
}

void PokerLog::WhoWon(std::vector<Player*> players, std::vector<Card> field)
{
  pair<Player*, int> currentWinner;
  vector<string> suitVec;
  vector<string> valueVec;
  vector<pair<string, int>> Pairs;
  int tempCounter = 0;
  string mostSuit;
  bool hasFlush = false;
  bool hasPair = false;
  bool hasStraight = false;

  for (Card card : field)
  {
    valueVec.push_back(card.first);
    suitVec.push_back(card.second);
  }

  for (Player* player : players)
  {
    vector<Card> fieldAndHand = field;
    fieldAndHand.push_back(player->GETplayerHand().first);
    fieldAndHand.push_back(player->GETplayerHand().second);

    suitVec.push_back(player->GETplayerHand().first.second);
    suitVec.push_back(player->GETplayerHand().second.second);

    valueVec.push_back(player->GETplayerHand().first.first);
    valueVec.push_back(player->GETplayerHand().second.first);

    for (string suit : Suits)
    {
      if (count(suitVec.begin(), suitVec.end(), suit) > tempCounter)
      {
        tempCounter = count(suitVec.begin(), suitVec.end(), suit);
        mostSuit = suit;
      }
    }

    if (tempCounter >= 5)
    {
      hasFlush = true;
    }

    tempCounter = 1;

    for (string value : Values)
    {
      if (count(valueVec.begin(), valueVec.end(), value) > tempCounter)
      {
        Pairs.push_back({value, count(valueVec.begin(), valueVec.end(), value)});
        hasPair = true;
      } 
    }

    vector<int> valuesIntVec = ConvertValueToNum(valueVec);
    

    
  }
}

/*

value, suit
value, suit
value, suit
value, suit
value, suit
value, suit
value, suit




















































*/
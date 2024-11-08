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

vector<int> PokerLog::ConvertValuesToNum(vector<string> values)
{
  vector<int> cardValueVec;

  for (int counter = 0; counter < 7; counter++)
  {
    auto cardValue = find(Values, Values + 13, values[counter]);
    int index = cardValue - Values;
    cardValueVec.push_back(index);
  }

  if (HasAce(cardValueVec) != 0)
  {
    for (int counter = 0; counter < HasAce(cardValueVec); counter++)
      {
        cardValueVec.push_back(13);
      }
  }

  sort(cardValueVec.begin(), cardValueVec.end());
  return cardValueVec;
}

int PokerLog::ConvertValueToNum(string value)
{
  if (value == "NULL")
  {
    return 0;
  }

  auto cardValue = find(Values, Values + 13, value);
  int index = cardValue - Values;

  if (index == 0)
  {
    return 13;
  }

  else
  {
    return index;
  }
}

string PokerLog::ConvertNumToValue(int value)
{
  vector<string> cardNumVec;

  if (value != 13)
  {
    return Values[value];
  }

  else
  {
    return "Ace";
  }
}

int PokerLog::HasAce(vector<int> values)
{
  int numOfAces;
  for (int value : values)
  {
    if (value == 0)
    {
      numOfAces++;
    }
  }

  return numOfAces;
}

int PokerLog::GreaterNum(int num1, int num2)
{
  if (num1 > num2)
  {
    return num1;
  }

  else
  {
    return num2;
  }
}

int PokerLog::LesserNum(int num1, int num2)
{
  if (num1 < num2)
  {
    return num1;
  }

  else
  {
    return num2;
  }
}

void PokerLog::TestFieldAndWin()
{
  int pot = littleBlind + bigBlind;
  pMyDealer->PlayCardsToField(5);
  PrintField();
  for (Player* player : playersVec)
  {
    cout << player->GETuserName() << "\n";
    pair<Card, Card> pHand = player->GETplayerHand();
    cout << pHand.first.first << " of " << pHand.first.second << "\n";
    cout << pHand.second.first << " of " << pHand.second.second << "\n\n";
  }

  Player* winningPlayer = WhoWon(playersVec, pMyDealer->GETfield());
  Winner(winningPlayer, pot, winningPlayer->handStrength);
}

vector<CT::Card> PokerLog::TopFiveCards(vector<Card> cards, int handStrength,
                                        vector<pair<string, int>> pairs,
                                        int straightHighestCardValue, string suit)
{
  Card cardToRemove1 = {"NULL", "NULL"};
  Card cardToRemove2 = {"NULL", "NULL"};
  vector<int> valuesInStraight;
  vector<Card> allFlushCards;
  switch (handStrength)
  {
    case 1:
      for (Card card : cards)
      {
        if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove1.first))
        {
          cardToRemove1 = card;
        }

        else if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove2.first))
        {
          cardToRemove2 = card;
        }

        else
        {
          continue;
        }
      }
      break;
    case 2:
      for (Card card : cards)
      {
        if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove1.first) && card.first != pairs.at(0).first)
        {
          cardToRemove1 = card;
        }

        else if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove2.first) && card.first != pairs.at(0).first)
        {
          cardToRemove2 = card;
        }

        else
        {
          continue;
        }
      }
      break;
    case 3:
      for (Card card : cards)
      {
        if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove1.first) && card.first != pairs.at(0).first || card.first != pairs.at(1).first)
        {
          cardToRemove1 = card;
        }

        else if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove2.first) && card.first != pairs.at(0).first || card.first != pairs.at(1).first)
        {
          cardToRemove2 = card;
        }

        else
        {
          continue;
        }
      }
      break;
    case 4:
      for (Card card : cards)
      {
        if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove1.first) && card.first != pairs.at(0).first)
        {
          cardToRemove1 = card;
        }

        else if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove2.first) && card.first != pairs.at(0).first)
        {
          cardToRemove2 = card;
        }

        else
        {
          continue;
        }
      }
      break;
    case 5:
      valuesInStraight = {straightHighestCardValue - 4, straightHighestCardValue - 3, straightHighestCardValue - 2, straightHighestCardValue - 1, straightHighestCardValue};
      int valueSeenIndex;

      for (Card card : cards)
      {
        if (!(ConvertValueToNum(card.first) >= straightHighestCardValue - 4 && ConvertValueToNum(card.first) <= straightHighestCardValue))
        {
          Card* whichCard = (cardToRemove1.first == "NULL") ? &cardToRemove1 : &cardToRemove2;
          *whichCard = card;

          if (cardToRemove2.first != "NULL")
          {
            break;
          }
        }

        else if ((valueSeenIndex = find(valuesInStraight.begin(), valuesInStraight.end(), ConvertValueToNum(card.first)) != valuesInStraight.end()))
        {
          valuesInStraight.erase(valuesInStraight.begin() + valueSeenIndex);
        }

        else
        {
          Card* whichCard = (cardToRemove1.first == "NULL") ? &cardToRemove1 : &cardToRemove2;
          *whichCard = card;

          if (cardToRemove2.first != "NULL")
          {
            break;
          }
        }
      }
      break;
    case 6:
      for (Card card : cards)
      {
        if (card.second != suit)
        {
          Card* whichCard = (cardToRemove1.first == "NULL") ? &cardToRemove1 : &cardToRemove2;
          *whichCard = card;

          if (cardToRemove2.first != "NULL")
          {
            break;
          }
        }

        else
        {
          allFlushCards.push_back(card);
        }
      }

      if (allFlushCards.size() == 6)
      {
        sort(allFlushCards.rbegin(), allFlushCards.rend());
        cardToRemove2 = allFlushCards.back();
        allFlushCards.pop_back();
      }

      else if (allFlushCards.size() == 7)
      {
        sort(allFlushCards.rbegin(), allFlushCards.rend());
        cardToRemove1 = allFlushCards.back();
        allFlushCards.pop_back();
        cardToRemove2 = allFlushCards.back();
        allFlushCards.pop_back();
      }
      break;
    case 7:
      if (pairs.size() == 2)
      {
        for (Card card : cards)
        {
          if (card.first != pairs.at(0).first || card.first != pairs.at(1).first && cardToRemove1.first == "NULL")
          {
            cardToRemove1 = card;
          }

          else if (card.first != pairs.at(0).first || card.first != pairs.at(1).first && cardToRemove2.first == "NULL")
          {
            cardToRemove2 = card;
            break;
          }

          else
          {
            continue;
          }
        }
      }

      else
      {
        int temp;
        for (pair<string, int> valAndNum : pairs)
        {
          temp = LesserNum(temp, ConvertValueToNum(valAndNum.first));
        }

        for (Card card : cards)
        {
          if (card.first == ConvertNumToValue(temp) && cardToRemove1.first == "NULL")
          {
            cardToRemove1 = card;
          }

          else if(card.first == ConvertNumToValue(temp) && cardToRemove2.first == "NULL")
          {
            cardToRemove2 = card;
            break;
          }

          else
          {
            continue;
          }
        }
      }
      break;
    case 8:
      for (Card card : cards)
      {
        if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove1.first) && card.first != pairs.at(0).first)
        {
          cardToRemove1 = card;
        }

        else if (ConvertValueToNum(card.first) < ConvertValueToNum(cardToRemove2.first) && card.first != pairs.at(0).first)
        {
          cardToRemove2 = card;
        }

        else
        {
          continue;
        }
      }
      break;
    case 9:
      valuesInStraight = {straightHighestCardValue - 4, straightHighestCardValue - 3, straightHighestCardValue - 2, straightHighestCardValue - 1, straightHighestCardValue};
      valueSeenIndex = 0;

      for (Card card : cards)
      {
        if (!(ConvertValueToNum(card.first) >= straightHighestCardValue - 4 && ConvertValueToNum(card.first) <= straightHighestCardValue))
        {
          Card* whichCard = (cardToRemove1.first == "NULL") ? &cardToRemove1 : &cardToRemove2;
          *whichCard = card;

          if (cardToRemove2.first != "NULL")
          {
            break;
          }
        }

        else if ((valueSeenIndex = find(valuesInStraight.begin(), valuesInStraight.end(), ConvertValueToNum(card.first)) != valuesInStraight.end()))
        {
          valuesInStraight.erase(valuesInStraight.begin() + valueSeenIndex);
        }

        else
        {
          Card* whichCard = (cardToRemove1.first == "NULL") ? &cardToRemove1 : &cardToRemove2;
          *whichCard = card;

          if (cardToRemove2.first != "NULL")
          {
            break;
          }
        }
      }
      break;
    case 10:
      valuesInStraight = {straightHighestCardValue - 4, straightHighestCardValue - 3, straightHighestCardValue - 2, straightHighestCardValue - 1, straightHighestCardValue};
      valueSeenIndex = 0;

      for (Card card : cards)
      {
        if (!(ConvertValueToNum(card.first) >= straightHighestCardValue - 4 && ConvertValueToNum(card.first) <= straightHighestCardValue))
        {
          Card* whichCard = (cardToRemove1.first == "NULL") ? &cardToRemove1 : &cardToRemove2;
          *whichCard = card;

          if (cardToRemove2.first != "NULL")
          {
            break;
          }
        }

        else if ((valueSeenIndex = find(valuesInStraight.begin(), valuesInStraight.end(), ConvertValueToNum(card.first)) != valuesInStraight.end()))
        {
          valuesInStraight.erase(valuesInStraight.begin() + valueSeenIndex);
        }

        else
        {
          Card* whichCard = (cardToRemove1.first == "NULL") ? &cardToRemove1 : &cardToRemove2;
          *whichCard = card;

          if (cardToRemove2.first != "NULL")
          {
            break;
          }
        }
      }
      break;
  }

  cards.erase(find(cards.begin(), cards.end(), cardToRemove1));
  cards.erase(find(cards.begin(), cards.end(), cardToRemove2));

  sort(cards.begin(), cards.end());

  return cards;
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
  Player* winningPlayer = WhoWon(playersVec, pMyDealer->GETfield());
  Winner(winningPlayer, pot, winningPlayer->handStrength);
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

void PokerLog::Winner(Player* player, int amtWon, int handStrength)
{
  string possibleHands[10] = {"High Card", "One Pair", "Two Pair", "Three-of-a-Kind", "Straight", "Flush", "Full House", "Four-of-a-Kind", "Straight Flush", "Royal Flush"};
  cout << player->GETuserName() << " won " << amtWon << " with a " << possibleHands[handStrength - 1] << "\n";
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
          Winner(playersVec.at(toAct), pot, playersVec.at(toAct)->handStrength);
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
          Winner(playersVec.at(toAct), pot, playersVec.at(toAct)->handStrength);
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

Player* PokerLog::WhoWon(std::vector<Player*> players, std::vector<Card> field)
{
  pair<Player*, pair<int, vector<Card>>> currentWinner;
  pair<Player*, pair<int, vector<Card>>> currentPlayerHand;
  vector<string> suitVec;
  vector<string> valueVec;
  int tempCounter = 0;
  string mostSuit;

  for (Card card : field)
  {
    valueVec.push_back(card.first);
    suitVec.push_back(card.second);
  }

  for (Player* player : players)
  {
    bool hasFlush = false;
    bool hasPair = false;
    bool hasStraight = false;
    bool has3OfKind = false;
    bool has4OfKind = false;
    bool checkIfStraightFlush = true;
    int straightHighestCardValue = 0;
    currentPlayerHand.first = player;
    vector<Card> fieldAndHand = field;
    vector<pair<string, int>> Pairs;

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

    for (string value : Values)
    {
      if (count(valueVec.begin(), valueVec.end(), value) >= 2)
      {
        Pairs.push_back({value, count(valueVec.begin(), valueVec.end(), value)});
        hasPair = true;

        if (count(valueVec.begin(), valueVec.end(), value) == 3)
        {
          has3OfKind = true;
        }

        if (count(valueVec.begin(), valueVec.end(), value) == 4)
        {
          has4OfKind = true;
        }
      } 
    }

    vector<int> valuesIntVec = ConvertValuesToNum(valueVec);
    int nextIndex = 1;
    int valuesInRow = 1;
    
    for (int counter = 0; counter < valuesIntVec.size() - 1; counter++)
    {
      if (valuesInRow >= 5)
      {
        hasStraight = true;
        straightHighestCardValue = valuesIntVec.at(nextIndex);
      }

      if (valuesIntVec.at(counter) + 1 == valuesIntVec.at(nextIndex))
      {
        nextIndex++;
        valuesInRow++;
      }

      else
      {
        nextIndex++;
        valuesInRow = 1;
      }
    }

    if (hasPair)
    {
      currentPlayerHand.second.first = GreaterNum(2, currentPlayerHand.second.first);

      if (has4OfKind)
      {
        currentPlayerHand.second.first = GreaterNum(8, currentPlayerHand.second.first);
        //! break
      }

      if (has3OfKind)
      {
        currentPlayerHand.second.first = GreaterNum(4, currentPlayerHand.second.first);
        //! NO break
      }

      if (Pairs.size() >= 2 && has3OfKind)
      {
        currentPlayerHand.second.first = GreaterNum(7, currentPlayerHand.second.first);
        //! break
      }

      else if (Pairs.size() >= 2)
      {
        currentPlayerHand.second.first = GreaterNum(3, currentPlayerHand.second.first);
        //! break
      }
    }
    
    if (hasFlush)
    {
      currentPlayerHand.second.first = GreaterNum(6, currentPlayerHand.second.first);

      if (hasStraight)
      {
        for (int counter = 0; counter < 5; counter--)
        {
          Card cardCheck = {ConvertNumToValue(straightHighestCardValue), mostSuit};

          if (find(fieldAndHand.begin(), fieldAndHand.end(), cardCheck) != fieldAndHand.end())
          {
            continue;
          }

          else
          {
            checkIfStraightFlush = false;
            break;
          }
        }

        if (checkIfStraightFlush)
        {
          currentPlayerHand.second.first = GreaterNum(9, currentPlayerHand.second.first);

          if (straightHighestCardValue == 13)
          {
            currentPlayerHand.second.first = GreaterNum(10, currentPlayerHand.second.first);
          }
        }
      }
    }

    else if (hasStraight)
    {
      currentPlayerHand.second.first = GreaterNum(5, currentPlayerHand.second.first);
    }

    currentPlayerHand.second.second = TopFiveCards(fieldAndHand, currentPlayerHand.second.first, Pairs, straightHighestCardValue, mostSuit);
    player->handStrength =currentPlayerHand.second.first;

    if (currentPlayerHand.second.first > currentWinner.second.first)
    {
      currentWinner = currentPlayerHand;
    }

    else if (currentPlayerHand.second.first == currentWinner.second.first)
    {
      for (int counter = 0; counter < 5; counter++)
      {
        if (currentPlayerHand.second.second.at(counter) > currentWinner.second.second.at(counter))
        {
          currentWinner = currentPlayerHand;
          break;
        }

        else if (currentPlayerHand.second.second.at(counter) < currentWinner.second.second.at(counter))
        {
          break;
        }
      }
    }

    else
    {
      continue;
    }
  }

  return currentWinner.first;
}

/*
    bool hasFlush = false;
    bool hasPair = false;
    bool hasStraight = false;
    bool has3OfKind = false;
    bool has4OfKind = false;


*/
#ifndef BASE_H
#define BASE_H

#include<string>
#include<stack>

class BaseCardData
{
  public:
    std::stack<std::pair<std::string, std::string>> MainDeck;
  protected:
    const std::string Suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    const std::string Values[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
};

#endif
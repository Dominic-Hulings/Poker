#ifndef BASE_H
#define BASE_H

#include <stack>
#include <string>

// Just a class for Deck to inherit from containing base data

class BaseCardData
{
  public:
    const std::string Suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    const std::string Values[13] = {"Ace",   "Two",  "Three", "Four", "Five",  "Six", "Seven",
                                    "Eight", "Nine", "Ten",   "Jack", "Queen", "King"};

  protected:
    std::stack<std::pair<std::string, std::string>> MainDeck;
};

#endif
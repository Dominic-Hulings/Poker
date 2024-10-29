#ifndef BASE_H
#define BASE_H

#include <stack>
#include <string>

#include "types.h"

// Just a class for Deck to inherit from containing base data

class BaseCardData : public customTypes
{
  public:
    const std::string Suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    const std::string Values[13] = {"Ace",   "Two",  "Three", "Four", "Five",  "Six", "Seven",
                                    "Eight", "Nine", "Ten",   "Jack", "Queen", "King"};

  protected:
    std::stack<typeCards> MainDeck;
};

#endif
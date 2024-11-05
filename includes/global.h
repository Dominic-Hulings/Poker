#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>

struct CT
{
  public:
    typedef std::pair<std::string, std::string> Card;
    const std::string Suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    const std::string Values[13] = {"Ace",   "Two",  "Three", "Four", "Five",  "Six", "Seven",
                                    "Eight", "Nine", "Ten",   "Jack", "Queen", "King"};
};

#endif
#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <vector>

struct CT
{
public:
  typedef std::pair<std::string, std::string> Card;
  const std::string Suits[4] = { "Spades", "Clubs", "Hearts", "Diamonds" };
  const std::vector<std::string> Values = { "Ace",   "Two",  "Three", "Four", "Five",  "Six", "Seven",
                                            "Eight", "Nine", "Ten",   "Jack", "Queen", "King" };
};

#endif
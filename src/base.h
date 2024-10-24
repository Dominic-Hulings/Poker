#ifndef BASE_H
#define BASE_H

#include<string>

class baseCardData
{
  public:
    std::string MainDeck[52][2];
  protected:
    const std::string Suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    const std::string Values[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
};

#endif
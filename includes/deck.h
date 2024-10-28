#ifndef DECK_H
#define DECK_H

#include "base.h"                // Includes base card data

class Deck : public BaseCardData //* Inherits protected list of suits and a protected list of values /
{                                //* along with a public stack of string pairs called MainDeck
  public:
    Deck();
  protected:
    void Shuffle(); //* Constructor and Shuffle defined in deck.cpp
};

#endif
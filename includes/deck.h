#ifndef DECK_H
#define DECK_H

#include <string>

#include "base.h" // Includes base card data

class Deck : BaseCardData //* Inherits protected list of suits and a protected list of values /
{                         //* along with a public stack of string pairs called MainDeck
  public:
    Deck();
    typeCards GETTopMainDeck();

  protected:
    void Shuffle(); //* Constructor and Shuffle defined in deck.cpp
};

#endif
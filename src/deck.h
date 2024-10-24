#ifndef DECK_H
#define DECK_H

#include "base.h"

namespace deckHFile
{
  class Deck : baseCardData
  {
    public:
      Deck();
      void NewDeck();
      void Shuffle();
  };
}

#endif
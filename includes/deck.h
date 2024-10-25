#ifndef DECK_H
#define DECK_H

#include "base.h"

namespace deckHFile
{
  class Deck : public BaseCardData
  {
    public:
      Deck();
      void Shuffle();
  };
}

#endif
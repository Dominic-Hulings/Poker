#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include "deck.h"

using std::string, std::random_device, std::mt19937, std::shuffle, std::vector, std::cout;
using namespace deckHFile;

Deck::Deck()
{
  int iteratorCounter = 0;

  for (string suit : this->Suits)
  {
    for (string value : this->Values)
    {
      this->MainDeck[iteratorCounter][0] = value;
      this->MainDeck[iteratorCounter][1] = suit;
      ++iteratorCounter;
    }
  }
}


#include <stack>
#include <string>
#include "deck.h"

using std::string, std::pair;
using namespace deckHFile;

Deck::Deck()
{
  int iteratorCounter = 0;

  for (string suit : this->Suits)
  {
    for (string value : this->Values)
    {
      pair<string, string> card = {value, suit};
      this->MainDeck.push(card);
    }
  }
}

void Deck::Shuffle()
{
  
}

/*

this->MainDeck[iteratorCounter][0] = value;
      this->MainDeck[iteratorCounter][1] = suit;
      ++iteratorCounter;




*/
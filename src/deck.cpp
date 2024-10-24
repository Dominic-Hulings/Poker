#include <stack>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <array>
#include "deck.h"

using std::string, std::pair, std::shuffle, std::default_random_engine, std::array;
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
  unsigned seed = 0; 
  pair<string, string> shufflingDeck[52];
  array<int, 52> orderOfShuffledDeck;
  int iteratorCounter = 0;

  while(!this->MainDeck.empty())
  {
    shufflingDeck[iteratorCounter] = this->MainDeck.top();
    this->MainDeck.pop();
    orderOfShuffledDeck[iteratorCounter] = iteratorCounter;
    iteratorCounter++;
  }

  shuffle(orderOfShuffledDeck.begin(), orderOfShuffledDeck.begin(), default_random_engine(seed));

  for(int num : orderOfShuffledDeck)
  {
    pair<string, string> moveCard = shufflingDeck[num];
    this->MainDeck.push(moveCard);
  }
}

/*

this->MainDeck[iteratorCounter][0] = value;
      this->MainDeck[iteratorCounter][1] = suit;
      ++iteratorCounter;




*/
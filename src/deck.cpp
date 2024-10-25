#include <stack>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <array>
#include "deck.h"

using std::string, std::pair, std::shuffle, std::default_random_engine, std::array;
using namespace deckHFile; // Links main.cpp to deck.cpp through deck.h in the namespace deckHFile

Deck::Deck() // Sets the Deck constructor
{
  int iteratorCounter = 0;

  for (string suit : this->Suits) // Suits is specified in base.h
  {
    for (string value : this->Values) // Values is specified in base.h
    {
      pair<string, string> card = {value, suit};
      this->MainDeck.push(card); // Put the pair of value and suit onto a stack
    }
  }
}

void Deck::Shuffle() // Sets the Deck's shuffle method
{
  unsigned seed = 0; 
  pair<string, string> shufflingDeck[52]; //* Temporary array for shuffling
  array<int, 52> orderOfShuffledDeck; //* Array holding numbers 0-51 representing each index of shufflingDeck
  int iteratorCounter = 0;

  while(!this->MainDeck.empty()) // Until the stack is empty
  {
    shufflingDeck[iteratorCounter] = this->MainDeck.top(); // Read the top card and put it in the next availible spot in shufflingDeck
    this->MainDeck.pop(); // Remove the card from the stack
    orderOfShuffledDeck[iteratorCounter] = iteratorCounter; // Add the next number to the orderOfShuffledDeck array
    iteratorCounter++;
  }

  shuffle(orderOfShuffledDeck.begin(), orderOfShuffledDeck.end(), default_random_engine(seed)); //* Randomly shuffles orderOfShuffledDeck's indexes

  for(int num : orderOfShuffledDeck) // For each number in orderOfShuffledDeck
  {
    pair<string, string> moveCard = shufflingDeck[num]; //* Take the {num} index of shufflingDeck
    this->MainDeck.push(moveCard); //* Add that card to the stack
  }
}
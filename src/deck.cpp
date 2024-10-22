#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

struct //* Struct used for storing suits + values and to pass the 2d array deck of cards from Deck.CreateNewDeck() => main.cpp.
{
  string Suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
  string Values[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  string MainDeck[52][2];
} CardCreation;

class Deck // Class that takes care of the deck
{
public:
  void CreateNewDeck() // Creates a new deck of cards (Overrides previous deck) and passes the 2d array ([$VALUE, $SUIT]) to CardCreation.MainDeck
  {
    int NewDeckIterator = 0; // A counter for iterating through the array

    for (int suitCounter = 0; suitCounter < 4; suitCounter++) // A counter for iterating through every suit
    {
      for (int valueCounter = 0; valueCounter < 13; valueCounter++) // A counter for iterating through ever value
      {
        CardCreation.MainDeck[NewDeckIterator][0] = CardCreation.Values[valueCounter];
        CardCreation.MainDeck[NewDeckIterator][1] = CardCreation.Suits[suitCounter];
        NewDeckIterator++;
      }
    }
  }

  void ShuffleDeck()
  {
    random_device rd;
    mt19937 g(rd());

    string unshuffledDeck[52][2];
    int shufflingDeck[52];
    string shuffledDeck[52][2];

    for (int iteratorCounter = 0; iteratorCounter < 52; iteratorCounter++)
    {
      unshuffledDeck[iteratorCounter][0] = CardCreation.MainDeck[iteratorCounter][0];
      unshuffledDeck[iteratorCounter][1] = CardCreation.MainDeck[iteratorCounter][1];
    }

    for (int iteratorCounter = 0; iteratorCounter < 52; iteratorCounter++)
    {
      shufflingDeck[iteratorCounter] = iteratorCounter;
    }

    shuffle(shufflingDeck.begin(), shufflingDeck.end(), g);
    int iteratorCounter = 0;

    for (int order : shufflingDeck)
    {
      shuffledDeck[iteratorCounter][0] = unshuffledDeck[order][0];
      shuffledDeck[iteratorCounter][1] = unshuffledDeck[order][1];
      iteratorCounter++;
    }

    for (int iteratorCounter = 0; iteratorCounter < 52; iteratorCounter++)
    {
      CardCreation.MainDeck[iteratorCounter][0] = shuffledDeck[iteratorCounter][0];
      CardCreation.MainDeck[iteratorCounter][1] = shuffledDeck[iteratorCounter][1];
    }
  }
};
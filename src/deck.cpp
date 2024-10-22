#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct
{
  string Suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
  string Values[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  string MainDeck[52][2];
} CardCreation;

class Deck
{
  public:
    void CreateNewDeck()
    {
      int NewDeckIterator = 0;

      for ( int suitCounter = 0; suitCounter < 4; suitCounter++ )
      {
        for ( int valueCounter = 0; valueCounter < 13; valueCounter++ )
        {
          CardCreation.MainDeck[NewDeckIterator][0] = CardCreation.Values[valueCounter];
          CardCreation.MainDeck[NewDeckIterator][1] = CardCreation.Suits[suitCounter];
          NewDeckIterator++;
        }
      }
    }
};
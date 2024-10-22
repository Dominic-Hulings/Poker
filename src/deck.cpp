#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Deck
{
  const vector<string> Suits = {"Spades", "Clubs", "Hearts", "Diamonds"};
  const vector<string> Values = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

  public:
    int CreateNewDeck()
    {
      const string* NewDeck[52][2];
      int NewDeckIterator = 0;

      for ( int suitCounter = 0; suitCounter < 4; suitCounter++ )
      {
        for ( int valueCounter = 0; valueCounter < 13; valueCounter++ )
        {
          NewDeck[NewDeckIterator][0] = &Suits[suitCounter];
          NewDeck[NewDeckIterator][1] = &Values[valueCounter];
        }
      }
      
      return 1;
    }
};
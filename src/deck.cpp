#include<iostream>
#include<string>
#include<vector>

using namespace std;
typedef string* tNewDeck[52][2];

class Deck
{
  public:
    tuple <vector<string>, vector<string>> CardCreationData()
    {
      tuple <vector<string>, vector<string>> SuitsAndValues[2];
      vector<string> Suits = {"Spades", "Clubs", "Hearts", "Diamonds"};
      vector<string> Values = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
      return make_tuple(Suits, Values);
    }

    tNewDeck* CreateNewDeck()
    {

      string* NewDeck[52][2];
      tNewDeck* pNewDeck = &NewDeck;

      int NewDeckIterator = 0;
      
      vector<string> Suits, Values;
      tuple <vector<string>, vector<string>> SuitsPlusValues(Suits, Values);
      SuitsPlusValues = CardCreationData();

      for ( int suitCounter = 0; suitCounter < 4; suitCounter++ )
      {
        for ( int valueCounter = 0; valueCounter < 13; valueCounter++ )
        {
          NewDeck[NewDeckIterator][0] = &Suits[suitCounter];
          NewDeck[NewDeckIterator][1] = &Values[valueCounter];
          NewDeckIterator++;
        }
      }

      return pNewDeck;
    }
};
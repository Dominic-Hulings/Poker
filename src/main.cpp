#include<iostream>
#include<string>
#include<gtk/gtk.h>
#include<vector>
#include"deck.cpp"

using namespace std;
typedef string* tNewDeck[52][2];

int main()
{
  Deck NewDeck;
  tNewDeck* CreatedDeck = NewDeck.CreateNewDeck();

  vector<string> Suits, Values;
  tuple <vector<string>, vector<string>> SuitsPlusValues(Suits, Values);
  SuitsPlusValues = NewDeck.CardCreationData();

  for ( int testCounter = 0; testCounter < 52; testCounter++)
  {
    string* x = *CreatedDeck[0][testCounter];
    string* y = *CreatedDeck[1][testCounter];

    cout << *x << "\n";
    cout << *y << "\n";
  }
  
  return 1;
}
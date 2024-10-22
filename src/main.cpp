#include<iostream>
#include<string>
#include<gtk/gtk.h>
#include<vector>
#include"deck.cpp"

using namespace std;

int main()
{
  Deck NewDeck;
  NewDeck.CreateNewDeck();

  for ( int testCounter = 0; testCounter < 52; testCounter++)
  {
    cout << CardCreation.MainDeck[testCounter][0] << " of ";
    cout << CardCreation.MainDeck[testCounter][1] << "\n";
  }
  
  return 1;
}
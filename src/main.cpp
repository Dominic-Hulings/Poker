#include<iostream>
#include<string>
#include<gtk/gtk.h>
#include"deck.cpp"

using namespace std;

int main()
{
  Deck NewDeck;
  NewDeck.CreateNewDeck();

  for ( int index = 0; index < 52; index++ )
  {
    string x;
    NewDeck[0][index] = x;
  }
  return 1;
}
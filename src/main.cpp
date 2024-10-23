#include <iostream>
#include <string>
#include <gtk/gtk.h>
#include "deck.cpp"

using std::string, std::cout;

int main()
{
  Deck NewDeck; // Creates a new Deck object from deck.cpp

  NewDeck.ShuffleDeck();

  for (int test = 0; test < 52; test++)
  {
    cout << CardCreation.MainDeck[test][0];
    cout << CardCreation.MainDeck[test][1] << "\n";
  }

  return 1;
}
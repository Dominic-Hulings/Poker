#include <iostream>
#include <string>
#include <gtk/gtk.h>
#include "deck.h"

using std::string, std::cout;
using namespace deckHFile;

int main()
{

  Deck deck;

  for(int i = 0; i < 52; i++)
  {
    cout << deck.MainDeck[i][0];
    cout << deck.MainDeck[i][1] << "\n";
  }

  return 1;
}
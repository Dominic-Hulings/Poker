#include <iostream>
#include <string>
#include <stack>
#include <gtk/gtk.h>
#include "deck.h"

using std::string, std::cout;
using namespace deckHFile;

int main() 
{
  Deck deck;
  deck.Shuffle();

  while(!deck.MainDeck.empty())
  {
    cout << deck.MainDeck.top().first << deck.MainDeck.top().second << "\n";
    deck.MainDeck.pop();
  }

  return 1;
}
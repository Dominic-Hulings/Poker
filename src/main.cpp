#include <iostream>
#include <string>
// #include <stack>
// #include <gtk/gtk.h>

// #include "deck.h"
#include "dealer.h"

using std::string, std::cout;

int main() //* Where the main function will be, just used for testing as of now
{
  Dealer y;
  
  while(!y.DealerDeck.empty()) // Just to display if the cards are shuffled (Testing purposes)
  {
    cout << y.DealerDeck.top().first << y.DealerDeck.top().second << "\n";
    y.DealerDeck.pop();
  }

  return 1;
}

/*

Deck deck; // Create new object from deck.cpp using deck.h

  while(!deck.MainDeck.empty()) // Just to display if the cards are shuffled (Testing purposes)
  {
    cout << deck.MainDeck.top().first << deck.MainDeck.top().second << "\n";
    deck.MainDeck.pop();
  }

*/
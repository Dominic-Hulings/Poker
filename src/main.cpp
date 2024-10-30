#include <string>
#include <iostream>
#include <ctime>

#include "player.h"
#include "table.h"

using std::string, std::cout;

int main() //* Where the main function will be, just used for testing as of now
{
  Player Dominic("User-Dominic");
  Table NewTable(5, "placeholder_name", false);
  NewTable.NewPlayerJoin(Dominic.GETpSelfPointer());

  std::pair<string, string> x = NewTable.playerIDsVec.front();

  cout << x.first << ", " << x.second << "\n";
  cout << Dominic.GETuserName() << "\n";
  cout << Dominic.GETplayerID();

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
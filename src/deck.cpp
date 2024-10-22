#include<iostream>
#include<string>
#include<vector>
#include"deck.h"

class Deck
{
  public:
    std::vector<std::string> CreateDeck()
    {
      std::vector<std::string> Deck;
      std::string cardSuits[4] = {"Spades", "Clubs", "Diamonds", "Hearts"};
      std::string cardValues[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

      for( std::string suit : cardSuits )
      {
        for( std::string value : cardValues )
        {
          Deck.push_back(value + " of " + suit);
        }
      }
      return Deck;
    }
};
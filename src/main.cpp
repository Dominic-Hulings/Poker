#include<iostream>
#include<string>
#include<gtk/gtk.h>
#include"deck.cpp"

using namespace std;

int main()
{
  Deck NewDeck; // Creates a new Deck object from deck.cpp

  NewDeck.CreateNewDeck(); // Creates a new deck array from deck.cpp
  
  return 1;
}
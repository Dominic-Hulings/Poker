#include<iostream>
#include<string>
#include<gtk/gtk.h>
#include"deck.h"

int main()
{
  CreateDeck();
  std::cout << Deck;
  return 1;
}
#include<iostream>
#include<string>
#include<gtk/gtk.h>
#include"deck.h"

using namespace std;

int main()
{
  CreateDeck();
  std::cout << Deck;
  return 1;
}
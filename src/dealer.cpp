#include "deck.h"
#include "dealer.h"

Dealer::Dealer()
{
  Deck DealerDeck;
  this->SETButtonPositions(1, 2, 3);
};

void Dealer::SETButtonPositions(int dPos, int lbPos, int bbPos)
{
  this->buttonPositions[0] = dPos;
  this->buttonPositions[1] = lbPos;
  this->buttonPositions[2] = bbPos;
};
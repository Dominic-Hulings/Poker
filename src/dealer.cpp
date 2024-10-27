#include "deck.h"
#include "dealer.h"

using std::string, std::to_string;

Dealer::Dealer()
{
  Deck DealerDeck;
  this->SETButtonPositions(1, 2, 3);
  string* ptest = &this::Hand;
}

void Dealer::preHandCheck()
{
  //TODO: Add checks to prevent cheating
  Dealer::Hand ThisHand;
  ThisHand.CheckResult(1);
}

Dealer::Hand Hand()
{
  string* pHandObj = ;
}

Dealer::Hand CheckResult(int checkResult)
{
  if(int checkResult = 1)
  {
    
  }
}

void Dealer::Hand::CurrentHand()
{

}

string Dealer::GETButtonPositions()
{
  string buttons = to_string(buttonPositions[0]) + to_string(buttonPositions[1]) + to_string(buttonPositions[2]);
  return buttons;
}

void Dealer::SETButtonPositions(int dPos, int lbPos, int bbPos)
{
  this->buttonPositions[0] = dPos;
  this->buttonPositions[1] = lbPos;
  this->buttonPositions[2] = bbPos;
};
#ifndef DEALER_H
#define DEALER_H

#include <stack>
#include <string>

#include "global.h"

class Dealer : CT
{
  public:
    Dealer();
    int GETButtonPositions();
    void preHandCheck();
    void SETplayersToDeal(int players);

  private:
    int playersToDeal;
    std::stack<Card> DealerDeck;
    int Hand(bool isTime);
    void SETButtonPositions(int buttonPos);
    int buttonPosition;
};

#endif
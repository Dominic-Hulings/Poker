#ifndef DEALER_H
#define DEALER_H

#include <stack>
#include <string>

#include "global.h"

class Dealer : CT
{
  public:
    Dealer();
    std::string GETButtonPositions();
    void preHandCheck();
    void SETplayersToDeal(int players);

  private:
    int playersToDeal;
    std::stack<Card> DealerDeck;
    int Hand(bool isTime);
    void SETButtonPositions(int dPos, int lbPos, int bbPos);
    int buttonPositions[3];
};

#endif
#ifndef DEALER_H
#define DEALER_H

#include <stack>
//#include <string>

#include "global.h"

class Dealer : CT
{
  public:
    Dealer();
    int GETButtonPositions();
    void preHandCheck(void* p2pPlayerIDsVec);
    void SETplayersToDeal(int players);

  private:
    int playersToDeal;
    int buttonPosition;
    std::stack<Card> DealerDeck;
    int Hand(bool isTime, void* p2pPlayerIDsVec);
    void SETButtonPositions(int buttonPos);
};

#endif
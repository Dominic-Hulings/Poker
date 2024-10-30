#ifndef DEALER_H
#define DEALER_H

#include <stack>
#include <vector>
//#include <string>

#include "player.h"
#include "global.h"

class Dealer : CT
{
  public:
    Dealer();
    int GETButtonPositions();
    void preHandCheck(std::vector<Player*>* p2pPlayerIDsVec);
    void SETplayersToDeal(int players);

  private:
    int playersToDeal;
    int buttonPosition;
    std::stack<Card> DealerDeck;
    int Hand(bool isTime, std::vector<Player*>* p2pPlayerIDsVec);
    void SETButtonPositions(int buttonPos);
};

#endif
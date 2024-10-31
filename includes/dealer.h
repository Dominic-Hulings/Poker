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
    int GETButtonPosition();
    std::pair<int, int> GETblinds();
    void preHandCheck(std::vector<Player*>* p2pPlayerIDsVec);
    void SETplayersToDeal(int players);
    void SETblinds(std::pair<int, int> blinds);

  private:
    int playersToDeal;
    int buttonPosition;
    int littleBlind;
    int bigBlind;
    std::stack<Card> DealerDeck;
    Player* Hand(bool isTime, std::vector<Player*>* p2pPlayerIDsVec);
    void SETbuttonPosition(int buttonPos);
    int CheckIfNeg(int num, int replaceNumIfNeg);
};

#endif
#ifndef DEALER_H
#define DEALER_H

#include <stack>
#include <vector>
// #include <string>

#include "global.h"
#include "player.h"

class Dealer : CT
{
  public:
    Dealer();
    int GETButtonPosition();
    std::pair<int, int> GETblinds();
    std::vector<Card> GETfield();
    void preHandCheck(std::vector<Player *> *p2pPlayerIDsVec);
    void SETplayersToDeal(int players);
    void SETblinds(std::pair<int, int> blinds);
    void PlayCardsToField(int amtOfCards);

  protected:
    int playersToDeal;
    int buttonPosition;
    int littleBlind;
    int bigBlind;
    int toAct;
    std::vector<Player*> playersVec;
    int CheckIfNeg(int num, int replaceNumIfNeg);

  private:
    std::stack<Card> DealerDeck;
    std::vector<Card> Field;
    Player *Hand(bool isTime, std::vector<Player *> *p2pPlayerIDsVec);
    void SETbuttonPosition(int buttonPos);
};

#endif
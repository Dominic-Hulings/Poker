#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "global.h"

class Player : CT
{
  public:
    Player(std::string inUserName);
    std::string GETuserName();
    std::string GETplayerID();
    std::pair<Card, Card> GETplayerHand();
    Player* GETpSelfPointer();
    void SETplayerID(std::string id);
    void GIVEplayerCard(Card givenCard);
  private:
    std::pair<Card, Card> playerHand;
    Player* pSelfPointer;
    std::string userName;
    std::string playerID;
};

#endif
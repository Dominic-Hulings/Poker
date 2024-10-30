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
    Player* GETpSelfPointer();
    void SETplayerID(std::string id);
    void GIVEplayerCard(Card givenCard);
    std::pair<Card, Card> playerHand;
  private:
    //std::pair<Card, Card> playerHand;
    Player* pSelfPointer;
    std::string userName;
    std::string playerID;
};

#endif
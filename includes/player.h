#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include <string>

class Player : CT
{
  public:
    Player(std::string inUserName);
    std::string GETuserName();
    std::string GETplayerID();
    int GETplayerStack();
    std::pair<Card, Card> GETplayerHand();
    Player *GETpSelfPointer();
    void SETplayerID(std::string id);
    void GIVEplayerCard(Card givenCard);
    int blindInput(int amount, int blind);
    void SETplayerStack(int amt, bool isRemoving);  //* if isRemoving = false then add the total instead
    int blind;
    bool turnOver;
    int amtInPot;

  private:
    std::pair<Card, Card> playerHand;
    int playerStack;
    Player *pSelfPointer;
    std::string userName;
    std::string playerID;
};

#endif
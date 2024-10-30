#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
  public:
    Player(std::string inUserName);
    std::string GETuserName();
    std::string GETplayerID();
    Player* GETpSelfPointer();
    void SETplayerID(std::string id);
  private:
    Player* pSelfPointer;
    std::string userName;
    std::string playerID;
};

#endif
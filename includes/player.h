#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
  public:
    Player(std::string inUserName);
    std::string GETuserName();
    void SETplayerID(std::string id);
  private:
    std::string userName;
    std::string playerID;
};

#endif
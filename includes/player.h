#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
  public:
    Player(std::string inUserName);
    void GETuserName();
  private:
    std::string UserName;
};

#endif
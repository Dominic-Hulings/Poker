#include <string>
//#include <iostream>

#include "player.h"
#include "global.h"

using std::string;

typedef CT::Card Card;

Player::Player(string inUserName)
{
  this->userName = inUserName;
}

string Player::GETuserName()
{
  return userName;
}

string Player::GETplayerID()
{
  return playerID;
}

void Player::SETplayerID(string id)
{
  playerID = id;
}
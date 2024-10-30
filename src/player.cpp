#include <string>
//#include <iostream>

#include "player.h"
#include "global.h"

using std::string;

typedef CT::Card Card;

Player::Player(string inUserName)
{
  this->userName = inUserName;
  this->pSelfPointer = this;
}

string Player::GETuserName()
{
  return userName;
}

string Player::GETplayerID()
{
  return playerID;
}

Player* Player::GETpSelfPointer()
{
  return pSelfPointer;
}

void Player::SETplayerID(string id)
{
  playerID = id;
}
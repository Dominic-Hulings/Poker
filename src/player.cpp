#include <string>
//#include <iostream>

#include "player.h"
#include "global.h"

using std::string, std::pair;

typedef CT::Card Card;

Player::Player(string inUserName)
{
  this->userName = inUserName;
  this->pSelfPointer = this;
  this->playerHand.first = {"clear", "clear"};
  this->playerHand.second = {"clear", "clear"};
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

void Player::SETplayerHand(Card givenCard)
{

}

void Player::SETplayerID(string id)
{
  playerID = id;
}
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
  this->playerStack = 500;
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

pair<Card, Card> Player::GETplayerHand()
{
  return playerHand;
}

int Player::GETplayerStack()
{
  return playerStack;
}

void Player::GIVEplayerCard(Card givenCard)
{
  if(playerHand.first.first == "clear")
  {
    playerHand.first = givenCard;
  }

  else
  {
    playerHand.second = givenCard;
  }
}

int Player::blindInput(int amount, int blind  = 0)
{
  this->playerStack -= amount;
  this->blind = blind;
  return amount;
}

void Player::SETplayerID(string id)
{
  playerID = id;
}
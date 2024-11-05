#include <string>
// #include <iostream>

#include "global.h"
#include "player.h"

using std::string, std::pair;

typedef CT::Card Card;

Player::Player(string inUserName)
{
  this->userName = inUserName;
  this->pSelfPointer = this;
  this->playerHand.first = {"clear", "clear"};
  this->playerHand.second = {"clear", "clear"};
  this->playerStack = 5000;
  this->blind = 0;
  this->amtInPot = 0;
}

string Player::GETuserName()
{
  return userName;
}

string Player::GETplayerID()
{
  return playerID;
}

Player *Player::GETpSelfPointer()
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
  if (playerHand.first.first == "clear")
  {
    playerHand.first = givenCard;
  }

  else
  {
    playerHand.second = givenCard;
  }
}

int Player::blindInput(int amount, int blind)
{
  this->playerStack -= amount;
  this->blind = blind;
  this->amtInPot = amount;
  return amount;
}

void Player::SETplayerStack(int amt, bool isRemoving)
{
  if (!isRemoving)
  {
    this->playerStack += amt;
  }

  else
  {
    this->playerStack -= amt;
  }
}

void Player::SETplayerID(string id)
{
  playerID = id;
}
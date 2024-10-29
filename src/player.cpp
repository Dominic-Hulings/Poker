#include <string>
//#include <iostream>

#include "player.h"
#include "global.h"

using std::string;

typedef CT::Card Card;

Player::Player(string inUserName)
{
  this->UserName = inUserName;
}
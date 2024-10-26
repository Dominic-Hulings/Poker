#include <string>

#include "game.h"
#include "dealer.h"

using std::string;

Table::Table(int startingPlayers, string tableName, bool isSave)
{
  Dealer TableDealer;
  this->playerCount = startingPlayers;

};
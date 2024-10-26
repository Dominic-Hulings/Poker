#include <string>

#include "game.h"
#include "dealer.h"

using std::string;

Table::Table(int inMaxPlayers, string tableName, bool isSave)
{
  Dealer TableDealer;
  maxPlayers = inMaxPlayers;
};

int Table::GETplayerCount()
{
  return playerCount;
}
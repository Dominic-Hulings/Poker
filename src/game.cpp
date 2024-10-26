#include <string>

#include "game.h"
#include "dealer.h"

using std::string;

Table::Table(int inMaxPlayers, string inTableName, bool isSave)
{
  Dealer TableDealer;
  maxPlayers = inMaxPlayers;
  tableName = inTableName;
  SETplayerCount(1);
}

void Table::NewHand()
{
  TableDealer.preCheck();
}

int Table::GETplayerCount()
{
  return playerCount;
}

int Table::GETmaxPlayers()
{
  return maxPlayers;
}

void Table::SETplayerCount(int pCount)
{
  playerCount = pCount;
}

void Table::SETmaxPlayers(int max)
{
  maxPlayers = max;
}
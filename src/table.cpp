#include <string>

#include "table.h"

using std::string;

/*
private class Table::TableDealer
{
  public:
    Dealer();
    std::string GETButtonPositions();
    void preHandCheck();
    std::stack<std::pair<std::string, std::string>> DealerDeck;
  private:
    int Hand(bool isTime);
    void SETButtonPositions(int dPos, int lbPos, int bbPos);
    int buttonPositions[3];
}
*/

Table::Table(int inMaxPlayers, string inTableName, bool isSave)
{
  maxPlayers = inMaxPlayers;
  tableName = inTableName;
  SETplayerCount(1);
}

void Table::NewHand()
{
  this->TableDealer.preHandCheck();
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
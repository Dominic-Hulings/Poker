#include <string>
#include <iostream>
#include <random>
#include <ctime>

#include "table.h"
#include "player.h"
//#include "global.h"

using std::string, std::cout, std::to_string;

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

void Table::NewHand()
{
  this->TableDealer.SETplayersToDeal(this->GETplayerCount());
  this->TableDealer.preHandCheck();
}

int Table::NewPlayerJoin(Player* pPlayer)
{
  if(!(maxPlayers >= playerCount))
  {
    cout << "Max Player limit met and/or exceeded" << "\n";
    return 0;
  }

  const string charList = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

  std::random_device rDev;
  std::mt19937 rng(rDev());
  std::uniform_int_distribution<std::mt19937::result_type> dist62(1, 62);
  string playerID;

  for (int counter = 0; counter < 20; counter++)  
  {
    playerID += to_string(charList[dist62(rng)]);
  }

  playerIDsVec.push_back({playerID, pPlayer->GETuserName()});
  pPlayer->SETplayerID(playerID);

  return 1;
}
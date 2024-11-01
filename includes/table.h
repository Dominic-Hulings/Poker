#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "dealer.h"
#include "player.h"

class Table
{
  public:
    Table(int inMaxPlayers, std::string tableName, bool isSave);
    std::string tableName;
    int GETplayerCount();
    int GETmaxPlayers();
    void SETmaxPlayers(int max);
    void SETplayerCount(int pCount);
    void SETdBlinds(std::pair<int, int> blinds);
    int NewPlayerJoin(Player *pPlayer);
    void NewHand();
    std::vector<Player *> pPlayerIDsVec;    //* Stores as {playerID, userName}
    std::vector<Player *> *p2pPlayerIDsVec; //* Stores a pointer to pPlayerIDsVec
  private:
    int playerCount;
    int maxPlayers;
    std::pair<int, int> blinds;
    Dealer TableDealer;
};

#endif
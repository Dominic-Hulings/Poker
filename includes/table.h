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
    int NewPlayerJoin(Player* pPlayer);
    void NewHand();
    std::vector<std::pair<std::string, std::string>> playerIDsVec; //* Stores as {playerID, userName}

  private:
    int playerCount;
    int maxPlayers;
    //std::vector<std::pair<std::string, std::string>> playerIDsVec;
    Dealer TableDealer;
};

#endif
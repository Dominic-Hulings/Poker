#ifndef GAME_H
#define GAME_H

#include <string>

class Table
{
  public:
    Table(int inMaxPlayers, std::string tableName, bool isSave);
    std::string tableName;
    int GETplayerCount();
    int GETmaxPlayers();
    void SETmaxPlayers(int max);
    void SETplayerCount(int pCount);
    void NewHand();
  private:
    int playerCount;
    int maxPlayers;
    class TableDealer;
};

#endif
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
    int SETplayerCount();
    int SETmaxPlayers();
  private:
    int playerCount;
    int maxPlayers;
    class TableDealer;
};

#endif
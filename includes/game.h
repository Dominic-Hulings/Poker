#ifndef GAME_H
#define GAME_H

#include <string>

class Table
{
  public:
    Table(int startingPlayers, std::string tableName, bool isSave);
    int playerCount;
    std::string tableName;

  private:
    class TableDealer;
};

#endif
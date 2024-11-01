#ifndef LOGIC_H
#define LOGIC_H

#include "dealer.h"

class PokerLog : protected Dealer
{
  public:
    PokerLog();
    void AllPhases();

  private:
    int pot;
    void Action();
    void Flop();
    void Turn();
    void River();
    void Winner(Player* player, int amtWon);
    bool onePlayerLeft();
};

#endif
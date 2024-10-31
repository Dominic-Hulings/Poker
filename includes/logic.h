#ifndef LOGIC_H
#define LOGIC_H

#include "dealer.h"

class PokerLog : protected Dealer
{
  public:
    PokerLog();
    void AllPhases();
  private:
    void Action();
    void Flop();
    void Turn();
    void River();
};



#endif
#ifndef LOGIC_H
#define LOGIC_H

#include <vector>
#include "player.h"
#include "global.h"

class PokerLog : CT
{
  public:
    PokerLog(int inToAct, std::vector<Player*>* inpPlayersVec, int inPlayersToDeal, int inLittleBlind, int inBigBlind);
    void AllPhases();

  private:
    int pot;
    int toAct;
    int littleBlind;
    int bigBlind;
    int playersToDeal;
    std::vector<Player*> playersVec;
    void Action();
    void Flop();
    void Turn();
    void River();
    void Winner(Player* player, int amtWon);
    bool onePlayerLeft();
    int CheckIfNeg(int num, int replaceNumIfNed);
};

#endif
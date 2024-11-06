#ifndef LOGIC_H
#define LOGIC_H

#include <vector>
#include "dealer.h"
#include "player.h"
#include "global.h"

class PokerLog : CT
{
  public:
    PokerLog(Dealer* inpDealer, int inToAct, std::vector<Player*>* inpPlayersVec, int inPlayersToDeal, int inLittleBlind, int inBigBlind);
    void PrintField();
    void AllPhases();

  private:
    int pot;
    int toAct;
    int littleBlind;
    int bigBlind;
    int playersToDeal;
    Dealer* pMyDealer;
    std::vector<Player*> playersVec;
    std::vector<int> ConvertValueToNum(std::vector<std::string> values);
    std::string ConvertNumToValue(int value);
    bool HasAce(std::vector<int> values);
    void Action();
    void Flop();
    void Turn();
    void River();
    void WhoWon(std::vector<Player*> players, std::vector<Card> field);
    void Winner(Player* player, int amtWon);
    bool onePlayerLeft();
    int CheckIfNeg(int num, int replaceNumIfNed);
    int GreaterNum(int num1, int num2);
};

#endif
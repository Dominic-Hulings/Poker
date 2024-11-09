#ifndef LOGIC_H
#define LOGIC_H

#include "dealer.h"
#include "global.h"
#include "player.h"
#include <vector>

class PokerLog : CT
{
public:
  PokerLog( Dealer* inpDealer, int inToAct, std::vector<Player*>* inpPlayersVec, int inPlayersToDeal, int inLittleBlind,
            int inBigBlind );
  void TestFieldAndWin();
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
  std::vector<int> ConvertValuesToNum( std::vector<std::string> values );
  int ConvertValueToNum( std::string value );
  std::string ConvertNumToValue( int value );
  bool HasAce( std::vector<int> values );
  void Action();
  void Flop();
  void Turn();
  void River();
  Player* WhoWon( std::vector<Player*> players, std::vector<Card> field );
  void Winner( Player* player, int amtWon, int handStrength );
  std::vector<Card> TopFiveCards( std::vector<Card> cards, int handStrength,
                                  std::vector<std::pair<std::string, int>> pairs, int straightHighestCardValue,
                                  std::string suit );
  bool onePlayerLeft();
  int CheckIfNeg( int num, int replaceNumIfNed );
  int GreaterNum( int num1, int num2 );
  int LesserNum( int num1, int num2 );
};

#endif
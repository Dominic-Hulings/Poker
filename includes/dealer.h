#ifndef DEALER_H
#define DEALER_H

#include <string>

class Dealer
{
  public:
    Dealer();
    std::string GETButtonPositions();
    std::string* ptest;
    void preHandCheck();
    class Hand
    {
      public:
        Hand();
        std::string* pHandObj;
        void CheckResult(int checkResult);
      private:
        void CurrentHand();
    };
  private:
    class DealerDeck;
    void SETButtonPositions(int dPos, int lbPos, int bbPos);
    int buttonPositions[3];
};

#endif
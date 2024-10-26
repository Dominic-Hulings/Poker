#ifndef DEALER_H
#define DEALER_H

#include <string>

class Dealer
{
  public:
    Dealer();
    std::string GETButtonPositions();
    void preCheck();
    class Hand
    {
      public:
        Hand();
      private:
        void CurrentHand();
    };
  private:
    class DealerDeck;
    void SETButtonPositions(int dPos, int lbPos, int bbPos);
    int buttonPositions[3];
};

#endif
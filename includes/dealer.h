#ifndef DEALER_H
#define DEALER_H

#include <string>

class Dealer
{
  public:
    Dealer();
    std::string GETButtonPositions();
    void preHandCheck();
  private:
    int Hand(bool isTime);
    class DealerDeck;
    void SETButtonPositions(int dPos, int lbPos, int bbPos);
    int buttonPositions[3];
};

#endif
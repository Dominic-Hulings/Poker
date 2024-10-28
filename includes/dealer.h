#ifndef DEALER_H
#define DEALER_H

#include <string>
#include <stack>

class Dealer
{
  public:
    Dealer();
    std::string GETButtonPositions();
    void preHandCheck();
    std::stack<std::pair<std::string, std::string>> DealerDeck;
  private:
    int Hand(bool isTime);
    void SETButtonPositions(int dPos, int lbPos, int bbPos);
    int buttonPositions[3];
};

#endif
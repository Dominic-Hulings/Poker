#ifndef DEALER_H
#define DEALER_H

class Dealer
{
  public:
    Dealer();
    int GETButtonPositions();
  private:
    class DealerDeck;
    void SETButtonPositions(int dPos, int lbPos, int bbPos);
    int buttonPositions[3];
};

#endif
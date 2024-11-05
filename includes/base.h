#ifndef BASE_H
#define BASE_H

#include <stack>
//#include <string>

#include "global.h"

// Just a class for Deck to inherit from containing base data

class BaseCardData : protected CT
{
  protected:
    std::stack<Card> MainDeck;
};

#endif
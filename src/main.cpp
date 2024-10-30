#include <string>
//#include <iostream>
#include <ctime>

#include "player.h"
#include "table.h"

using std::string;

int main() //* Where the main function will be, just used for testing as of now
{
  Player Dominic("User-Dominic");
  Player Guest("User-Guest");
  Player Guest1("User-Guest1");

  Table NewTable(5, "placeholder_name", false);

  NewTable.NewPlayerJoin(Dominic.GETpSelfPointer());
  NewTable.NewPlayerJoin(Guest.GETpSelfPointer());
  NewTable.NewPlayerJoin(Guest1.GETpSelfPointer());

  NewTable.NewHand();

  /*for(Player* player : NewTable.pPlayerIDsVec)
  {
    Player PlayerObj = *player;
    cout << PlayerObj.GETuserName() << " " << PlayerObj.GETplayerID() << "\n";
  }*/



  return 1;
}
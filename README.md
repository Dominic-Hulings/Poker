Making an online poker app you can play with your friends using c++ and the gtk gui lilbrary.

Unsure if docker works or if this even works on other systems/OS's but I will get to that

App functions

Functions:
|___Deck
|     |____Make new deck x
|     |____Shuffle deck x
|     |____Base Card Data x
|___Dealer
|     |____Make Dealer specific deck on init x
|     |____Deal cards
|     |____Burn cards
|     |____Play cards to the board
|     |____Compare cards to see who won
|     |____Button control
|___Player
|     |____Hand
|     |____Table Position
|     |____Turn and Blind check
|     |____Betting
|     |____Chat
|     |____Name
|     |____Account?
|___Online functionality
|     |____Lobby create
|     |____Lobby password (public/private)
|     |____Join game
|     |____Turn queue
|     |____Host game settings
|___Gui
|     |____Table designs
|     |____Menu (Settings, title screen, ect)
|     |____Card display
|___Chips
|     |____Default lobby starting amount
|     |____Keeping track of bets
|     |____isAllin variable
|     |____Moving chips
|     |____Miniumum + max bet size
|     |____Check if player is out

The play moves clockwise around the table, starting with action to the left of the dealer button. The 'button' is a round disc that sits in front of a player and is rotated one seat to the left every hand.

Royal Flush 10
Straight Flush  9
Four-of-a-Kind  8
Full House  7
Flush 6
Straight  5
Three-of-a-Kind 4
Two Pair  3
One Pair  2
High Card 1

DISCLAIMER!
  The app uses FAKE MONEY, no actual gambling is being incited


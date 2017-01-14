#BTP600 Assignment 1 
##Game Choosen: Big Two
***

### Classes
* BTP600A1: Program beginning point. Runs BigTwo
* BigTwo: Game that plays Hand until one player get score of 49
* Hand: Game that plays Round until either all player pass or one player is out of card
* Round: Game that draws card(s) based on the card on the table or initiate the hand
* Turn: Class to hold the information about last draw cards and players
* Also there are Player, Card, Deck classes but not directly related to understand how the game works.

### How to Play
This game only takes numbers.

Set number of players -- minium 2 to maximum 4

Set number of NPC  -- mimimum 0 to maximum (Number of Players)

For the first player - select number of cards to draw -- 1, 2, 3, or 5

Than select card by the number on the right (e.g. 3.[3S]) means card number 3. To choose, simply enter 3

Card is indicated with [ ], first number or alphbet is the face number (A~K) and second digit is the shape (H- Heart, C - Clover, S - Spade, D - Diamond)

Enter 0 anytime to pass the turn.

Please only select the numbers indicated. If the maximum number is 10, don't select 11 or bigger.

All validation is based on the game rule from the website.

AI is really simple..If the cards on table is more than 1 it passes. Otherwise draw random single card that is valid to play.

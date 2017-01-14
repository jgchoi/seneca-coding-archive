package BigTwo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

import cgfw.card.Card;
import cgfw.game.Game;
import cgfw.game.move.MoveStrategy;
import cgfw.player.Player;

public class BigTwoHumanMove implements MoveStrategy {
	private Game game;
	private ArrayList<Player> players;
	private Player currentPlayer;
	
	private enum HandType {
		 STRAIGHT_FLASH(5), FOUR_OF_KIND(4), FULL_HOUSE(3), FLASH(2), STRAIGHT(1);
		 private final int power;
		 private HandType(int power) {
			 this.power = power;
		 }
	 };

	@Override
	public void move() {
		getInitialData();
		setCurrentPlayer();
		if(((BigTwoPlayer) currentPlayer).isPassed()){
			System.out.println("*** Player already passed ***");
		}else if(currentPlayer.getCardsInHand().count() == 0){
			System.out.println("*** No more cards to play. Player Won the Hand ***");
			((BigTwoPlayer) currentPlayer).setIsPassed(true);
		}else{
			getCardSelection();
		}
	}
	
	private void setCurrentPlayer() {
		for(Player player : players){
			if(((BigTwoPlayer) player).isCurrentPlayer()){
				currentPlayer = (BigTwoPlayer) player;
			}
	    }
	}

	private void getInitialData() {
		game = Game.getInstance();
		players = game.getPlayers();
	}

	//Human Player's method for selecting cards to play
	private void getCardSelection() {
		ArrayList<Card> lastPlayedCards = null;
		ArrayList<Card> selected = null;
		int numberOfCards = 0;

		Scanner reader = new Scanner(System.in);

		boolean isUserSelectionValid = false;

		while(!isUserSelectionValid) {

			//Display cards on hand
			displayCards();

			selected = new ArrayList<Card>();
			if (game.getCardsOnTable().get(0) == null) {
				//First player, choose how many cards to draw
				System.out.print("Choose number of cards to play - Single(1), Double(2), Triple(3), Poker Combination (5): ");
				numberOfCards = reader.nextInt();
			} else {
				lastPlayedCards = game.getCardsOnTable().get(0).getAllCards();
				numberOfCards = lastPlayedCards.size();
			}


			for (int i = 0; i < numberOfCards; i++) {
				if(!((BigTwoPlayer) currentPlayer).isPassed()){
					System.out.print("Enter card number - Selected Cards(" + (i) + "/" + numberOfCards + "): ");
					int cardIndex = reader.nextInt();
					if (cardIndex == 0) {
						if(currentPlayer.getCardsInHand().getCardAtIndex(0).compareTo(new Card(2,0))==0){
							System.out.println("Player with 3D can't pass");
						}else{
							((BigTwoPlayer) currentPlayer).setIsPassed(true);
							((BigTwoPlayer) currentPlayer).setCurrentSelection(null);
							isUserSelectionValid = true;
						}
					}else{
						selected.add(currentPlayer.getCardsInHand().getCardAtIndex(cardIndex - 1));
						Collections.sort(selected);
						isUserSelectionValid = isValidSelection(lastPlayedCards, selected);
					}
				}
			}
		}
		
		if(selected.size() != 0){
			//Remove selected card from cards on hand when selection is valid
			for(Card card : selected){
				currentPlayer.getCardsInHand().getAllCards().remove(card);
			}

			((BigTwoPlayer) currentPlayer).setCurrentSelection(selected);
		}

	}
    
    //Check if user selected card is valid and return boolen
    //Takes cards on the table and cards selected
    private boolean isValidSelection(ArrayList<Card> lastPlayedCards, ArrayList<Card> selected) {
    	
        if(selected.size() == 4){
            System.out.println("Cannot choose 4 cards..");
            return false;
        }

        if(selected.size() == 0){
            System.out.println("First player can't pass");
            return false;
        }

        //If first player
        if(lastPlayedCards == null){
            //If user have 3D, selection must have 3D
            Card smallestCardFromHand = currentPlayer.getCardsInHand().getCardAtIndex(0);
            Card smallestCardFromSelection = selected.get(0);
            if(smallestCardFromHand.compareTo(new Card(2,0)) == 0){
                if(smallestCardFromHand.compareTo(smallestCardFromSelection) != 0){
                    System.out.println("Invalid Card(s): 3D must be included");
                    return false;
                }
            }
        }

        //Card size 1 ~ 3 - number must be same
        int cardSize = selected.size();
        if(cardSize == 1 | cardSize == 2 | cardSize == 3){
            boolean result = true;
            int cardNumber = selected.get(0).getRank();
            //Check if card is valid (all same)
            for (Card card: selected) {
                if(card.getRank() != cardNumber){
                    System.out.println("Invalid Card(s): For single, double, and triple cards, all cards should have same number");
                    return false;
                }
            }

            //Check if selected card is higher than lastPlayedCards
            if(lastPlayedCards != null && lastPlayedCards.get(cardSize-1).compareTo(selected.get(cardSize-1)) > 0){
                System.out.println("Invalid Card(s): Selected cards are smaller(weaker) than the cards on the table");
                return false;
            }
        }

        //If card size is 5...
        //straight flush / four of kinds / full house/ flush / Straight

        if(cardSize == 5){

            HandType typeOfSelectedCard = findHandType(selected);
            System.out.println(" - Poker Hand Detected: " + typeOfSelectedCard);
            if(typeOfSelectedCard == null) {
                System.out.println("Selected 5 cards are not poker hands");
                return false;
            }

            //Compare power if there's cards on table
            if(lastPlayedCards != null  ) {
                HandType typeOfCardOnTable = findHandType(lastPlayedCards);
                //5 Cards are weaker than the cards on table
                if (typeOfCardOnTable.power > typeOfSelectedCard.power) {
                    System.out.println("Selected 5 cards are weaker than cards on table");
                    return false;
                }

                //5 Cards are same rank but still weaker
                if (typeOfCardOnTable.power == typeOfCardOnTable.power) {
                    if (typeOfCardOnTable == HandType.FLASH || typeOfCardOnTable == HandType.STRAIGHT || typeOfCardOnTable == HandType.STRAIGHT_FLASH) {
                        //This case, just compare the largest
                        if (lastPlayedCards.get(cardSize - 1).compareTo(selected.get(cardSize - 1)) > 0) {
                            System.out.println("Selected 5 cards are same rank but weaker than cards on table:FLASH/STRAIGHT/STRAIGHTFLASH");
                            return false;
                        }
                    } else {
                        //For full house and fourcard, compare middle one
                        if (lastPlayedCards.get(2).compareTo(selected.get(2)) > 0) {
                            System.out.println("Selected 5 cards are same rank but weaker than cards on table:FullHouse/FOURCARDS");
                            return false;
                        }
                    }
                }
            }
        }

        //All test passed
        return true;
    }

    //Check cards hands return the type of hands
    //Taks set of Card objects
    private HandType findHandType(ArrayList<Card> _cards) {
        boolean isStraight = true;
        for(int i=0; i<4; i++){
            if((_cards.get(i).getRank()+1)%13 != _cards.get(i+1).getRank()){
                isStraight = false;
            }
        }

        //Flash?
        boolean isFlash = true;
        int cardType = _cards.get(0).getSuite();
        for (Card card: _cards) {
            if(card.getSuite() != cardType){
                isFlash = false;
            }
        }

        boolean isFourOfKind = false;
        boolean isFullHouse = false;
        //Four Cards?
        //Possible case XXXX Y OR Y XXXX
        if((    _cards.get(0).getRank() == _cards.get(1).getRank() &&
                _cards.get(1).getRank() == _cards.get(2).getRank() &&
                _cards.get(2).getRank() == _cards.get(3).getRank()    ) ||
            (   _cards.get(1).getRank() == _cards.get(2).getRank() &&
                _cards.get(2).getRank() == _cards.get(3).getRank() &&
                _cards.get(3).getRank() == _cards.get(4).getRank()    )){
            isFourOfKind = true;
        }else
        if((    _cards.get(0).getRank() == _cards.get(1).getRank() &&
                _cards.get(1).getRank() == _cards.get(2).getRank()    ) ||
            (   _cards.get(2).getRank() == _cards.get(3).getRank() &&
                _cards.get(3).getRank() == _cards.get(4).getRank()    )){

            //Full House?
            ///Possible case XXX YY OR YY XXX
            isFullHouse = true;
        }

        if(isFlash && isStraight){
            return HandType.STRAIGHT_FLASH;
        }else if(isFlash){
            return HandType.FLASH;
        }else if(isStraight){
            return HandType.STRAIGHT;
        }else if(isFourOfKind){
            return HandType.FOUR_OF_KIND;
        }else if(isFullHouse){
            return HandType.FULL_HOUSE;
        }else{
            return null;
        }
    }

    //Displays cards on hand
    public void displayCards() {
        System.out.print("Cards on Hand:\n");
        int i = 1;
        for (Card card : currentPlayer.getCardsInHand().getAllCards()){
            System.out.print(i++ + ".");
            System.out.print(card);
            System.out.print(" ");
        }
        System.out.print("0.Pass");
        System.out.println("");

    }

}

package BigTwo;

import java.util.ArrayList;
import java.util.Collections;

import cgfw.card.Card;
import cgfw.game.Game;
import cgfw.game.move.MoveStrategy;
import cgfw.player.Player;

public class BigTwoComputerMove implements MoveStrategy {
	private Game game;
	private ArrayList<Player> players;
	private Player currentPlayer;

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
	
	private void getInitialData() {
		game = Game.getInstance();
		players = game.getPlayers();
	}
	
	private void setCurrentPlayer() {
		for(Player player : players){
			if(((BigTwoPlayer) player).isCurrentPlayer()){
				currentPlayer = (BigTwoPlayer) player;
			}
	    }
	}
	
	  protected void getCardSelection() {
		  ArrayList<Card> lastPlayedCards = null;
		  ArrayList<Card> selected = new ArrayList<Card>();
		  int numberOfCards = 0;
		  if (game.getCardsOnTable().get(0) != null) {
				lastPlayedCards = game.getCardsOnTable().get(0).getAllCards();
				numberOfCards = lastPlayedCards.size();
			}
		  
	        //If not begin or single, no cards to play pass.
	        if(numberOfCards > 1 || currentPlayer.getCardsInHand().count() == 0){
	        	((BigTwoPlayer) currentPlayer).setIsPassed(true);
				((BigTwoPlayer) currentPlayer).setCurrentSelection(null);
	        }else{

	        //If begin, return single, smallest

	        //if NPC is the first player, always draw smallest single
	        if(numberOfCards == 0){
	            selected.add(currentPlayer.getCardsInHand().removeCardAtIndex(0));
	        } else {
	            //Otherwise... select random within the range..
	            Card minimumRequired = lastPlayedCards.get(lastPlayedCards.size()-1);

	            //Filter drawable cards... (larger than minium card)
	            ArrayList<Card> drawable = new ArrayList<Card>();
	            for(Card card : currentPlayer.getCardsInHand().getAllCards()){
	                if(minimumRequired.compareTo(card)<0){
	                    drawable.add(card);
	                }
	            }

	            //There is no card to play
	            if(drawable.size() == 0){
	                //pass and return null
	            	((BigTwoPlayer) currentPlayer).setIsPassed(true);
					((BigTwoPlayer) currentPlayer).setCurrentSelection(null);
	            }else{
	            	int randomNumber = (int)(Math.random() * drawable.size());
	            	selected.add(drawable.get(randomNumber));
	            }
	        }

	        //Sort selected
	        Collections.sort(selected);

	        if(selected.size() != 0){
				//Remove selected card from cards on hand when selection is valid
				for(Card card : selected){
					currentPlayer.getCardsInHand().getAllCards().remove(card);
				}

				((BigTwoPlayer) currentPlayer).setCurrentSelection(selected);
			}
	    }
	  }

}

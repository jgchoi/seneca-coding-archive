package BigTwo;

import cgfw.card.CardsStack;
import cgfw.card.Deck;
import cgfw.game.GameComposite;
import cgfw.player.Player;

public class BigTwoGame extends GameComposite{

	//Game Ended
	@Override
	public void postGame() {
		
	}

	@Override
	public void preGame() {

	}

	//Set new deck & distribute to player
	//Empty table
	@Override
	public void preRun() {
		Deck deck = new Deck();
		int numberOfCards = 13;
		for(Player player : super.getPlayers()){
			CardsStack cards = deck.getCards(numberOfCards);
			cards.sort();
			player.setCardsInHand(cards);
			
		}
		super.setCardsOnTable(null);
	}

	@Override
	public void postRun() {
		updateScore();
		displayScores();
	}

	//Check if any player reached score of 49
	//Return true if player with score more than 49 exist
	@Override
	public boolean isGameCompleted() {
		for(Player player : super.getPlayers()){
			if(player.getScore() >= 49){
				return true;
			}
		}
		return false;
	}
	
	// -- Method copied from A1
	//---- After BigTwo is Completed ----
    //After big two is completed update score for BigTwo to recognize
    private void updateScore() {
        System.out.println("====================");
        System.out.println("Hand is Completed");
        System.out.println("====================");

        // Score = number of cards left * 2 ^ number of 2 draw by last player
        int numberOfCardsLeft = 0;
        int numberOfTwo = 0;
        int score = 0;
        Player winner = null;

        for (Player player : super.getPlayers()){
        	//Casting for BigTwoPlayer Methods
            numberOfCardsLeft += player.getCardsInHand().count();
            if(((BigTwoPlayer) player).isHandWinner()){
            	winner = player;
                numberOfTwo = ((BigTwoPlayer) player).numberOfTwoInLastPlayedCards();
            }
        }

        if(numberOfTwo != 0){
            score = (int) (numberOfCardsLeft * Math.pow(2, numberOfTwo));
        }else{
            score = numberOfCardsLeft;
        }

        System.out.println("-Winnder: Player " + (super.getPlayers().indexOf(winner)+1));
        System.out.println("-Score Earned: " + score);
        winner.updateScore(score);
    }
    
    //Displays score
    private void displayScores() {
        System.out.println("");
        System.out.println("====================");
        System.out.println("     Score Board");
        System.out.println("====================");
        System.out.println("");
        for(Player player : super.getPlayers()){
            System.out.print("-Player" + (super.getPlayers().indexOf(player)+1));
            System.out.println(" Score " + player.getScore() + "/49");
        }
    }
    
    

}

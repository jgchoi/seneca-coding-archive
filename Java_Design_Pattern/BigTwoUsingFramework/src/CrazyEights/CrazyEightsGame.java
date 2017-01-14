package CrazyEights;

import java.util.Scanner;

import cgfw.card.*;
import cgfw.game.*;
import cgfw.player.Player;

public class CrazyEightsGame extends GameComposite {

	protected static int consecutivePasses = 0;
	private static int currentLeaderIndex = -1;
	private CardsStack starterPile = new CardsStack();
	private CardsStack stockPile = new CardsStack();
	
	@Override
	public void postGame() {
		System.out.println("Game Over!!!!!");
		System.out.println("");
		System.out.println("----------- Scores -----------");
		
		// Update and display scores
		updateGameScores();
		for( Player player : super.getPlayers() ) {
			System.out.println(player.getUserName() + ": " + player.getScore());
		}
		System.out.println("");
		System.out.println("***** Winner: " + super.getPlayerAtIndex(currentLeaderIndex).getUserName() + " !! *****");
		
		String proceed = "";
		@SuppressWarnings("resource")
		Scanner input = new Scanner(System.in);
		System.out.print( "Play another game ? [Y]=> " );
        proceed = input.nextLine();
        if( proceed.equalsIgnoreCase("y"))
        	super.run();
        else
        	System.out.println("Thanks for playing, GoodBye!!");
		
	}

	// Updates scores for each player, gets winner
	private void updateGameScores() {
	     int lowestScore = 10000000;
	     
	     for( int x = 0; x < super.getPlayers().size(); x++ )
	        {
	            int total = 0;
	            for( int i = 0; i < super.getPlayerAtIndex(x).getCardsInHand().count(); i++ )
	            {
	                Card card = super.getPlayerAtIndex(x).getCardsInHand().getCardAtIndex(i);
	                if( card.getRankFaceValue() == 8 )
	                    total += 50;
	                else if( card.getRankFaceValue() >= 10 && card.getRankFaceValue() <= 13 )
	                    total += 10;
	                else
	                    total += card.getRankFaceValue();
	            }
	            super.getPlayerAtIndex(x).updateScore(total);
	            if( super.getPlayerAtIndex(x).getScore() < lowestScore )
	            {
	                lowestScore = super.getPlayerAtIndex(x).getScore();
	                currentLeaderIndex = x;
	            }
	        }
	}

	@Override
	public void preGame() {
		Deck deck = new Deck();
		int numberOfCards = 5;
		for(Player player : super.getPlayers()){
			player.setCardsInHand(deck.getCards(numberOfCards));
		}
		stockPile = deck;
		
		Card card = stockPile.removeCardFromTop();
		System.out.println("");
		System.out.println("Initial Card: *" + card.toString() + "*");
		while ( card.getRankFaceValue() == 8 ) {
			System.out.println("--------- Initial Card will be changed -----------");
			stockPile.addCard(card);
			stockPile.shuffle();
			card = stockPile.removeCardFromTop();
		}
		// CardsStack starterPile = new CardsStack();
		starterPile.addCard(card);
		
		// Set initial legal rank and legal suite
		if(super.getGameComponent() instanceof CrazyEightsTurn) {
			( (CrazyEightsTurn)super.getGameComponent() ).setLegalRank( card.getRankFaceValue() );
			( (CrazyEightsTurn)super.getGameComponent() ).setLegalSuite( card.getSuite() );
		}
			
	}

	@Override
	public void preRun() {
	}

	@Override
	public void postRun() {
	}

	@Override
	public boolean isGameCompleted() {
		// If everyone has passed
		if( consecutivePasses >= super.getPlayers().size() )
			return true;
		// If a player has 0 cards left
		for( Player player : super.getPlayers() ) {
			if( player.getCardsInHand().count() <= 0) {
				return true;
			}
		}
		return false;
	}
	
	public GameComponent getGameComponent() {
		return super.getGameComponent();
	}

	public CardsStack getStarterPile() {
		return starterPile;
	}

	public void setStarterPile(CardsStack starterPile) {
		this.starterPile = starterPile;
	}

	public CardsStack getStockPile() {
		return stockPile;
	}

	public void setStockPile(CardsStack stockPile) {
		this.stockPile = stockPile;
	}

}

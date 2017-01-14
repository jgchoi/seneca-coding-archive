package GoFish;

import cgfw.card.Deck;
import cgfw.game.GameComposite;
import cgfw.player.Player;

public class GoFishGame extends GameComposite{

	@Override
	public void postGame() {
		System.out.println("Game Over!!!!!");
		System.out.println("----Display Scores-----");
		for(Player player : super.getPlayers()){
			// get score for each player, find Winner
		}
		System.out.println("Winner: ********** ");
	}

	@Override
	public void preGame() {
		Deck deck = new Deck();
		int numberOfCards = super.getPlayers().size() < 4 ? 7 : 5;
		for(Player player : super.getPlayers()){
			player.setCardsInHand(deck.getCards(numberOfCards));
		}
		super.setCardsOnTable(deck);
	}

	@Override
	public void preRun() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void postRun() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public boolean isGameCompleted() {
		//All books are made
		//Loop through players cards and see if books are completed.
		return false;
	}

}

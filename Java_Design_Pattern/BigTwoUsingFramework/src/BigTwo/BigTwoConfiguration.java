package BigTwo;

import cgfw.game.Game;
import cgfw.game.GameComposite;
import cgfw.game.config.ConfigurationBuilder;

public class BigTwoConfiguration implements ConfigurationBuilder {
	private Game game;
	
	public BigTwoConfiguration(){
		game = Game.getInstance();
	}
	
	@Override
	public void hasJoker() {
		game.setHasJoker(false);	
	}

	@Override
	public void maxNumberOfPlayer() {
		game.setMaxPlayers(4);		
	}

	@Override
	public void minNumberOfPlayer() {
		game.setMinPlayers(2);
	}

	@Override
	public void numberOfPlayersPerDeck() {
		game.setNumPlayersPerDeck(4);
	}

	@Override
	public void playerFactory() {
		game.setPlayerFactory(new BigTwoPlayerFactory());
	}

	@Override
	public void suitOrder() {
		game.setSuitOrder(new String[] {"D", "C", "H", "S"});	
	}

	@Override
	public void highestRank() {
		game.setHighestRank(2); //Highest rank is 2
	}

	@Override
	public void hasComputerPlayer() {
		game.setHasComputerPlayer(true);
	}

	@Override
	public void gameComponent() {
		GameComposite bigTwo	= new BigTwoGame();
		GameComposite hand		= new BigTwoHand();
		GameComposite round		= new BigTwoRound();
		
		//Construct Game
		round.setGame(new BigTwoTurn());
		hand.setGame(round);
		bigTwo.setGame(hand);
	
		game.setGameComponent(bigTwo);
	}

	@Override
	public void humanMove() {
		game.setHumanMoves(new BigTwoHumanMove());
	}

	@Override
	public void computerMove() {
		game.setComputerMoves(new BigTwoComputerMove());
	}

	@Override
	public void setDeck() {
		game.setDeck();
	}

	@Override
	public void setPlayers() {
		game.setPlayers();
	}

	@Override
	public void displayGameTitle() {
		System.out.println("=========================");
		System.out.println("=    B I G     T W O    =");
		System.out.println("=========================");
	}

	@Override
	public Game getGame() {
		return game;
	}

}

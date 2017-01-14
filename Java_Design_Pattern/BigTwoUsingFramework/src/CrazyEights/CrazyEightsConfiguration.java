package CrazyEights;

import cgfw.game.Game;
import cgfw.game.GameComposite;
import cgfw.game.config.ConfigurationBuilder;

//Concrete Builder implementing abstract ConfigurationBuilder class
public class CrazyEightsConfiguration implements ConfigurationBuilder {

	private Game game;
	
	public CrazyEightsConfiguration() {
		game = Game.getInstance();
	}
	@Override
	public void hasJoker() {
		game.setHasJoker(false);
	}

	@Override
	public void maxNumberOfPlayer() {
		game.setMaxPlayers(6);
	}

	@Override
	public void minNumberOfPlayer() {
		game.setMinPlayers(2);
	}

	@Override
	public void numberOfPlayersPerDeck() {
		game.setNumPlayersPerDeck(6);
		
	}

	@Override
	public void playerFactory() {
		game.setPlayerFactory( new CrazyEightsPlayerFactory() );
	}

	@Override
	public void suitOrder() {
		game.setSuitOrder(new String[] {"D", "C", "H", "S"});
	}

	@Override
	public void highestRank() {
		game.setHighestRank(7);           // 8
	}

	@Override
	public void hasComputerPlayer() {
		game.setHasComputerPlayer(true);
	}

	@Override
	public void gameComponent() {
		GameComposite cc = new CrazyEightsGame();
		cc.setGame(new CrazyEightsTurn());			   // Set game component
		game.setGameComponent(cc);		
	}

	@Override
	public void humanMove() {
		game.setHumanMoves( new CrazyEightsHumanMove() );
	}

	@Override
	public void computerMove() {
		game.setComputerMoves( new CrazyEightsComputerMove() );		
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
		
		System.out.println("============================");
		System.out.println("****  Crazy Eights !!!  ****");
		System.out.println("============================");
		System.out.println("");
	}

	@Override
	public Game getGame() {
		return game;
	}

}

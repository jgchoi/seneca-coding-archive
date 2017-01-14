package GoFish;

import cgfw.game.Game;
import cgfw.game.GameComponent;
import cgfw.game.GameComposite;
import cgfw.game.config.ConfigurationBuilder;
import cgfw.game.config.PlayerFactory;
import cgfw.game.move.MoveStrategy;

// Concrete Builder implementing abstract ConfigurationBuilder class
public class GoFishConfiguration implements ConfigurationBuilder {

	private Game game;
	
	public GoFishConfiguration() {
		game = Game.getInstance();
	}
	
	@Override
	public void hasJoker() {
		game.setHasJoker(false);
	}

	@Override
	public void maxNumberOfPlayer() {
		game.setMaxPlayers(5);
	}

	@Override
	public void minNumberOfPlayer() {
		game.setMinPlayers(2);
	}

	@Override
	public void numberOfPlayersPerDeck() {
		game.setNumPlayersPerDeck(5);
	}

	@Override
	public void playerFactory() {
		game.setPlayerFactory( new GoFishPlayerFactory() );
	}

	@Override
	public void suitOrder() {
		game.setSuitOrder(new String[] {"D", "C", "H", "S"});
	}

	@Override
	public void highestRank() {
		game.setHighestRank(0);
	}

	@Override
	public void hasComputerPlayer() {
		game.setHasComputerPlayer(true);
	}

	@Override
	public void gameComponent() {
		GameComposite gc = new GoFishGame();
		gc.setGame(new GoFishTurn());
		game.setGameComponent(gc);
		
	}

	@Override
	public void humanMove() {
		game.setHumanMoves(new GoFishHumanMove() );
	}

	@Override
	public void computerMove() {
		game.setComputerMoves( new GoFishComputerMove() );
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
	public Game getGame() {
		return game;
	}

	@Override
	public void displayGameTitle() {

		System.out.println("Go Fish!!!");
		System.out.println("====================");
		System.out.println("");
		
	}

}

package cgfw.game.config;

import cgfw.game.Game;
import cgfw.game.GameComponent;
import cgfw.game.move.MoveStrategy;

// Abstract Builder for Game configurations
public interface ConfigurationBuilder {
	
	//Set joker
	public void hasJoker();
	
	//set max number of player
	public void maxNumberOfPlayer();
	
	//set min number of player
	public void minNumberOfPlayer();
	
	//set number of players per a deck
	public void numberOfPlayersPerDeck();
	
	//set factory for sepcific game
	public void playerFactory();
	
	//set suit order
	public void suitOrder();
			 
	//Set highest rank
	//Index of Rank, 0 = A, 1 = 2... 9 = 10, 10 = J, 11 = Q, 12 = K
	public void highestRank();
	
	//Set if game has compute player
	public void hasComputerPlayer();
	
	//Set game component (layers)
	public void gameComponent();
	
	//set move strategy for human
	public void humanMove();
	
	//set computer strategy
	public void computerMove();	
	
	//set deck variables
	public void setDeck();
	
	//create new players
	public void setPlayers();
	
	//show game title
	public void displayGameTitle();
	
	//return game object
	public Game getGame();
}

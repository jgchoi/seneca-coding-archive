package cgfw.game;

import java.util.ArrayList;

import cgfw.card.CardsStack;
import cgfw.player.Player;

public abstract class GameComponent {
	private static ArrayList<Player> players;
	private static ArrayList<CardsStack> cardsOnTable = new ArrayList<>();
	
	//Return players
	public ArrayList<Player> getPlayers(){
		return players;
	}
	
	//Set players for game (unique players through the game)
	public void setPlayers(ArrayList<Player> _players){
		players = _players;
	}
	
	//Run game component
	public abstract void run();
	
	//Set cards on table can be 1 stack or more
	public void setCardsOnTable(CardsStack stack){
		cardsOnTable.add(stack);
	}
	
	//Return cards on table
	public ArrayList<CardsStack> getCardsOnTable() {
		return cardsOnTable;
	}
	
	//return a player object at index
	public Player getPlayerAtIndex( int index ) {
		return players.get(index);
	}
}

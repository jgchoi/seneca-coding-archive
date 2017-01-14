package GoFish;

import java.util.ArrayList;

import cgfw.game.Game;
import cgfw.game.move.MoveStrategy;
import cgfw.player.Player;

public class GoFishHumanMove implements MoveStrategy {

	@Override
	public void move() {
		Game game = Game.getInstance();
		ArrayList<Player> players = game.getPlayers();
		
		//Select a player to ask 
		
		//Within the cards that player have,
		//Make selection for which card to ask
		
		//Check if the selected player has the card
		
		//If they have the card,
			//Move the all the cards to current player
		
		//Else (Go Fish)
			//set player isTurnCompleted to true
		
	}

}

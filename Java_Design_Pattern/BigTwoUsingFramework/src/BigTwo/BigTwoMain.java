package BigTwo;

import cgfw.game.Game;
import cgfw.game.config.GameEngineer;

public class BigTwoMain {
	public static void main(String [] args){
		// Initialize GameEngineer by passing Game Configuration type (concrete ConfigurationBuilder)
		GameEngineer gameEngineer = new GameEngineer( new BigTwoConfiguration() );
		// Build game
		gameEngineer.configureGame();
		// Return game
		Game game = gameEngineer.getGame();
		// Run game
		game.run();
	}
}

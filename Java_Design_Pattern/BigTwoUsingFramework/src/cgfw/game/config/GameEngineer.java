package cgfw.game.config;

import cgfw.game.Game;

public class GameEngineer {
	
	private ConfigurationBuilder configBuilder;
	
	//Constructor with game specific config
	public GameEngineer( ConfigurationBuilder configType ) {
		configBuilder = configType;
	}
	
	//Return game
	public Game getGame() {
		return configBuilder.getGame();
	}
	
	// Configures game, concrete builders implement values for each element of the game
	public void configureGame() {

		configBuilder.displayGameTitle();
		configBuilder.hasJoker();
		configBuilder.maxNumberOfPlayer();
		configBuilder.minNumberOfPlayer();
		configBuilder.numberOfPlayersPerDeck();
		configBuilder.playerFactory();
		configBuilder.suitOrder();
		configBuilder.highestRank();
		configBuilder.hasComputerPlayer();
		configBuilder.gameComponent();
		configBuilder.humanMove();
		configBuilder.computerMove();
		configBuilder.setPlayers();
		configBuilder.setDeck();
	}
	

}

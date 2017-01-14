package cgfw.game;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

import cgfw.card.Card;
import cgfw.card.CardsStack;
import cgfw.card.Deck;
import cgfw.game.config.PlayerFactory;
import cgfw.game.move.MoveStrategy;
import cgfw.player.Player;

public class Game {
	private static final Game game = new Game();
	
   //private ConfigurationBuilder cs; // All data can be accessed from Game class, configBuilder data member not required
	private int numberOfComputers;
	private int numberOfPlayers;
	private GameComponent gameComponent;
	private PlayerFactory playerFactory;
	
	// Game Features
	private int maxPlayers;
	private int minPlayers;
	private boolean hasJoker;
	private int numPlayersPerDeck;
	private String[] suitOrder;
	private int highestRank;
	private boolean hasComputerPlayer;
	private MoveStrategy humanMoves;
	private MoveStrategy computerMoves;
	
	//---- Public method --- Thinking about singleton 
	private Game(){}
	
	//Return game instance
	public static Game getInstance(){
		return game;
	}
	
	//Return unique players reference for game
	public ArrayList<Player> getPlayers(){
		return gameComponent.getPlayers();
	}
	
	//Return list of cardstacks on the table (not in players)
	public ArrayList<CardsStack> getCardsOnTable(){
		return gameComponent.getCardsOnTable();
	}
	
	//Set the new deck
	public void setDeck() {
		Deck.setHasJoker(hasJoker);
		int numberOfDecks = (int) Math.ceil((numberOfPlayers*1.0)/numPlayersPerDeck);
		Deck.setNumberOfDecks(numberOfDecks);
	}

	//Start playing the game
	public void run(){
		gameComponent.run();
	}
	
	//Set human/computer players by asking number of players to user
	public void setPlayers(){
		//If game is not single play game get number of players
		if(maxPlayers != 1)
			getNumberOfPlayers();
		
		//Set Players
		ArrayList<Player> players = new ArrayList<Player>();
		for (int i = 0; i < numberOfPlayers; i++){
			//Player object
			cgfw.player.Player newPlayer = playerFactory.getPlayer();
			
			//Set player name
			
			if(i < numberOfComputers){
				newPlayer.setMove(computerMoves);
				newPlayer.setUserName("RoboGamer ");
			}else{
				newPlayer.setMove(humanMoves);
				newPlayer.setUserName("Player ");
			}
			players.add(newPlayer);
		}
		Collections.shuffle(players);
		
		for( int i = 0; i < numberOfPlayers; i++ )
			players.get(i).setUserName(players.get(i).getUserName()+ i );
		
		gameComponent.setPlayers(players);
	}

	//Get number of players
	private void getNumberOfPlayers() {
		System.out.println("Setting Players");
		System.out.println("===============");
		
		@SuppressWarnings("resource")
		Scanner reader = new Scanner(System.in);
		
		System.out.print("Enter a number of players:\n");
		System.out.print("*Integers Only* MIN: " + minPlayers + " MAX: " + maxPlayers+"): ");
		//validation based on min and max player
		numberOfPlayers = reader.nextInt();
		
		//If game has computer player
		if(hasComputerPlayer){
			System.out.print("Enter a number of NPC players (Less than number of players): ");
			numberOfComputers = reader.nextInt();
		} 
		
	}

	// Below methods are Getters and Setters for Game elements
	public GameComponent getGameComponent() {
		return gameComponent;
	}

	public void setGameComponent(GameComponent gameCoponent) {
		this.gameComponent = gameCoponent;
	}

	public PlayerFactory getPlayerFactory() {
		return playerFactory;
	}

	public void setPlayerFactory(PlayerFactory playerFactory) {
		this.playerFactory = playerFactory;
	}

	public int getMaxPlayers() {
		return maxPlayers;
	}

	public void setMaxPlayers(int maxPlayers) {
		this.maxPlayers = maxPlayers;
	}

	public int getMinPlayers() {
		return minPlayers;
	}

	public void setMinPlayers(int minPlayers) {
		this.minPlayers = minPlayers;
	}

	public boolean isHasJoker() {
		return hasJoker;
	}

	public void setHasJoker(boolean hasJoker) {
		this.hasJoker = hasJoker;
	}

	public int getNumPlayersPerDeck() {
		return numPlayersPerDeck;
	}

	public void setNumPlayersPerDeck(int numPlayersPerDeck) {
		this.numPlayersPerDeck = numPlayersPerDeck;
	}

	public String[] getSuitOrder() {
		return suitOrder;
	}

	public void setSuitOrder(String[] suitOrder) {
		this.suitOrder = suitOrder;
	}

	public int getHighestRank() {
		return highestRank;
	}

	public void setHighestRank(int highestRank) {
		Card.setHighestRank(highestRank);
	}

	public boolean isHasComputerPlayer() {
		return hasComputerPlayer;
	}

	public void setHasComputerPlayer(boolean hasComputerPlayer) {
		this.hasComputerPlayer = hasComputerPlayer;
	}

	public MoveStrategy getHumanMoves() {
		return humanMoves;
	}

	public void setHumanMoves(MoveStrategy humanMoves) {
		this.humanMoves = humanMoves;
	}

	public MoveStrategy getComputerMoves() {
		return computerMoves;
	}

	public void setComputerMoves(MoveStrategy computerMoves) {
		this.computerMoves = computerMoves;
	}

}

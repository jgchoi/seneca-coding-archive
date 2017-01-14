package cgfw.game;

import cgfw.player.Player;

public abstract class GameLeaf extends GameComponent {
	
	protected static int currentPlayerIndex = -1;
	
	//Run game with given structure
	@Override
	public void run() {
		if(currentPlayerIndex == -1)
			setInitialPlayer();
		preGame();
		while(!isGameLeafCompleted()){
			preRun();
			currentPlayer().makeMove();
			postRun();
		}
		postGame();
	}
	
	//Select initial player
	public abstract void setInitialPlayer();
	
	//Return player that need to be play
	public abstract Player currentPlayer();
	
	//Same as methods in GameComposite
	public abstract void postGame();
	public abstract void preGame();
	public abstract void preRun();
	public abstract void postRun();
	public abstract boolean isGameLeafCompleted();
}

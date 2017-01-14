package cgfw.game;

public abstract class GameComposite extends GameComponent {
	private GameComponent game;
	
	//Run game..
	//With given structure
	@Override
	public void run() {
		preGame();
		while(!isGameCompleted()){
			preRun();
			game.run();
			postRun();
		}
		postGame();
	}
	
	//Set a game for composit (adding layer)
	public void setGame(GameComponent _game){
		game = _game;
	}
	
	//method that need to be run after while loop
	public abstract void postGame();
	
	//method that need to be run before while loop
	public abstract void preGame();
	
	//Method that need to be run befor run
	public abstract void preRun();
	
	//Method that need to be run after run
	public abstract void postRun();
	
	//Return boolean and condition for loop to be completed
	public abstract boolean isGameCompleted();
	
	// Get the game component
	public GameComponent getGameComponent() {
		return game;		
	}
	
}

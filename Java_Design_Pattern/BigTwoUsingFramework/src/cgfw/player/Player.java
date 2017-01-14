package cgfw.player;
import cgfw.card.CardsStack;
import cgfw.game.move.MoveStrategy;

public abstract class Player {
	private MoveStrategy moveStrategy;
	private String userName;
	private CardsStack cardsInHand;
	protected int score;
	private boolean isTurnComplete = false;
	
	//Take player's turn
	public void makeMove(){
		moveStrategy.move();
	}
	
	//Return cards in hand
	public CardsStack getCardsInHand(){
		return cardsInHand;
	}
	
	//Set username
	public void setUserName(String _userName){
		userName = _userName;
	}
	
	//empty player's card in hand
	public CardsStack removeCardsInHand(){
		CardsStack result = cardsInHand;
		cardsInHand = null;
		return result;
	}
	
	//return user name
	public String getUserName(){
		return userName;
	}
	
	//set player's card in hand
	public void setCardsInHand(CardsStack cards){
		cardsInHand = cards;
	}
	
	//return player's score
	public int getScore(){
		return score;
	}
	
	//Update score method, needed to be implemented for specific game
	public abstract void updateScore(int _score);
	
	//set move (wether for human or computer)
	public void setMove(MoveStrategy _moveStrategy){
		moveStrategy = _moveStrategy;
	}

	//return the turn status 
	public boolean isTurnComplete(){
		return isTurnComplete;
	}
	
	//Set turn status, if true, turn is over
	public void setIsTurnComplete(boolean _isTurnComplete){
		isTurnComplete = _isTurnComplete;
	}
	
}

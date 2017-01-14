package BigTwo;

import java.util.ArrayList;

import cgfw.card.Card;
import cgfw.card.CardsStack;
import cgfw.player.Player;

public class BigTwoPlayer extends Player {

	private CardsStack lastSelection;
	private CardsStack currentSelection;
	private boolean isPassed;
	private boolean isCurrentPlayer;
	
	public void setCurrentPlayer(boolean _isCurrentPlayer){
		isCurrentPlayer = _isCurrentPlayer;
	}
	
	public boolean isCurrentPlayer(){
		return isCurrentPlayer;
	}
	
	public BigTwoPlayer(){
		lastSelection = null;
		isPassed = false;
	}
	
	//Return smallest card - by comparsion method defined by Card
    public Card smallestCard() {
        Card smallestCard = new Card(super.getCardsInHand().getCardAtIndex(0));
        return smallestCard;
    }
    
    public void setCurrentSelection(ArrayList<Card> _currentSelection){
    	if(_currentSelection == null){
    		currentSelection = null;
    	}else{
	    	currentSelection = new CardsStack();
	    	for (Card card : _currentSelection){
	    		currentSelection.addCard(card);
	    	}
    	}
    }
    
    public void setLastSelection(ArrayList<Card> _currentSelection){
    	if(_currentSelection == null){
    		lastSelection = null;
    	}else{
	    	lastSelection = new CardsStack();
	    	for (Card card : _currentSelection){
	    		lastSelection.addCard(card);
	    	}
    	}
    }
    
    public ArrayList<Card> getCurrentSelection(){
    	if(currentSelection != null){
			return currentSelection.getAllCards();	
		}
		return null;
    }
	
	 public boolean isPassed() {
	        return isPassed;
	    }

	 //Reset the pass status to false
	 public void resetPassStatus() {
		 isPassed = false;
	 }
	 
	 public void setIsPassed(boolean _isPassed){
		 isPassed = _isPassed;
	 }
	
	@Override
	public void updateScore(int _score) {
		score += _score;
		
	}
	
	public boolean isHandWinner(){
		return super.getCardsInHand().count() == 0;
	}
	
	public ArrayList<Card> getLastSelection(){
		if(lastSelection != null){
			return lastSelection.getAllCards();	
		}
		return null;
	}
	
	public int numberOfTwoInLastPlayedCards() {
        int numberOfTwo = 0;
        for(Card card : lastSelection.getAllCards()){
            if (card.getRank() == 1){ //Rank 2
                numberOfTwo++;
            }
        }
        return numberOfTwo;
    }

	
	

}

package GoFish;

import cgfw.game.GameLeaf;
import cgfw.player.Player;

public class GoFishTurn extends GameLeaf {
	
	@Override
	public Player currentPlayer() {
		return super.getPlayerAtIndex(currentPlayerIndex);
	}

	@Override
	public void postGame() {
		//Player getting one card from cards on table
		// ** Need implementation
		// Advance index if turns of current player finished
		currentPlayerIndex++;
	}

	@Override
	public void preGame() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void preRun() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void postRun() {
		// TODO Auto-generated method stub
		//Check if book is made, and if it did, remove from cards in hand
		//Update score for player
		super.getPlayerAtIndex(currentPlayerIndex).updateScore(0);
		
	}

	@Override
	public boolean isGameLeafCompleted() {
		// Check boolean to see if current players turn has ended
		
		return super.getPlayerAtIndex(currentPlayerIndex).isTurnComplete();
	}

	@Override
	public void setInitialPlayer() {
		currentPlayerIndex = 0;
		
	}
}

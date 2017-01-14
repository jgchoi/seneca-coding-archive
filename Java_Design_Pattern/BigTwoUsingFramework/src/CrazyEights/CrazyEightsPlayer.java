package CrazyEights;

import cgfw.player.Player;

public class CrazyEightsPlayer extends Player {
	
	private boolean currentPlayer = false;

	@Override
	public void updateScore(int _score) {
		super.score += _score;
		
	}
	
	public void makePlayerCurrent( boolean isCurrent) {
		currentPlayer = isCurrent;
	}
	
	public boolean isCurrentPlayer() {
		return currentPlayer;
	}

}

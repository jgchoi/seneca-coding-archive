package GoFish;

import cgfw.player.Player;

public class GoFishPlayer extends Player {
	
	@Override
	public void updateScore(int _score) {
		//Logic for updating score when 1 book is detected
		//in player's card after removing
		//if different update method required, developer can use
		//parameter _score
		super.score++;

	}
	
	

}

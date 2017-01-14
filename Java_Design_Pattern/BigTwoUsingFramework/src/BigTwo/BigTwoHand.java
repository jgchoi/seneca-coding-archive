package BigTwo;

import cgfw.game.GameComposite;
import cgfw.player.Player;

public class BigTwoHand extends GameComposite{
	
	@Override
	public void postGame() {
		for(Player player : getPlayers()){
			((BigTwoPlayer)player).setCurrentPlayer(false);
		}
	}

	@Override
	public void preGame() {
	}

	@Override
	public void preRun() {
	}

	@Override
	public void postRun() {
		
	}

	@Override
	public boolean isGameCompleted() {
		for(Player player : getPlayers()){
            if(((BigTwoPlayer) player).isHandWinner()){
                return true;
            }
        }
        return false;
	}

}

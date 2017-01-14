package GoFish;

import cgfw.game.config.PlayerFactory;
import cgfw.player.Player;

public class GoFishPlayerFactory implements PlayerFactory {

	@Override
	public Player getPlayer() {
		return new GoFishPlayer();
	}

}

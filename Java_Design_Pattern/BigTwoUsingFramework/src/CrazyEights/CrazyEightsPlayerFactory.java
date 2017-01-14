package CrazyEights;

import cgfw.game.config.PlayerFactory;
import cgfw.player.Player;

public class CrazyEightsPlayerFactory implements PlayerFactory {

	@Override
	public Player getPlayer() {
		return new CrazyEightsPlayer();
	}

} 
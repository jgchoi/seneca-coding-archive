package BigTwo;

import cgfw.game.config.PlayerFactory;
import cgfw.player.Player;

public class BigTwoPlayerFactory implements PlayerFactory {

	@Override
	public Player getPlayer() {
		return new BigTwoPlayer();
	}

}

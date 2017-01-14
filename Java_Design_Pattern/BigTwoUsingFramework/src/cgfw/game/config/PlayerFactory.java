package cgfw.game.config;

import cgfw.player.Player;

//return Player objct for specific game
public interface PlayerFactory {
	public Player getPlayer();
}

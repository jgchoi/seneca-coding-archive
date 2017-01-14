package CrazyEights;

import cgfw.game.GameLeaf;
import cgfw.player.Player;

public class CrazyEightsTurn extends GameLeaf {

	protected static boolean validMoveMade = false;
	private int legalRank = -1;
	private int legalSuite = -1;
	
	@Override
	public void setInitialPlayer() {
		currentPlayerIndex = 0;
	}

	@Override
	public Player currentPlayer() {
		return (CrazyEightsPlayer)getPlayerAtIndex(currentPlayerIndex);
	}

	@Override
	public void postGame() {
		CrazyEightsPlayer p1 = (CrazyEightsPlayer) getPlayerAtIndex(currentPlayerIndex);
		p1.makePlayerCurrent(false);
		currentPlayerIndex++;
		currentPlayerIndex = currentPlayerIndex % getPlayers().size();
		CrazyEightsPlayer p2 = (CrazyEightsPlayer) getPlayerAtIndex(currentPlayerIndex);
		p2.makePlayerCurrent(true);
		
	}

	@Override
	public void preGame() {
		CrazyEightsPlayer player = (CrazyEightsPlayer) getPlayerAtIndex(currentPlayerIndex);
		player.makePlayerCurrent(true);
		validMoveMade = false;
	}

	@Override
	public void preRun() {
		if( legalRank >= 0 && legalSuite >=0 ) {
			System.out.println("");
			System.out.println("*************************************************");
			System.out.println(" Legal Rank: " + getLegalRankName() + "  |  Legal Suite: " + getLegalSuiteName() );
			System.out.println("*************************************************");
			System.out.println("Current Status (# of Cards left to shed): ");
			for( Player player : getPlayers() ) {
				System.out.print( player.getUserName() + ": " + player.getCardsInHand().count() + " | ");
			}
			System.out.println("");
		}
	}

	@Override
	public void postRun() {
	}

	@Override
	public boolean isGameLeafCompleted() {
			return validMoveMade;
			
	}

	public int getLegalRank() {
		return legalRank;
	}

	public void setLegalRank(int legalRank) {
		this.legalRank = legalRank;
	}

	public int getLegalSuite() {
		return legalSuite;
	}
	
	// Return string name of suite
	public String getLegalSuiteName() {
		if( legalSuite == 0)
			return "Diamond";
		else if( legalSuite == 1)
			return "Club";
		else if( legalSuite == 2 )
			return "Heart";
		else if( legalSuite == 3 )
			return "Spade";
		else
			return null;
	}
	
	// Return string name of suite
	public String getLegalRankName() {
		if( legalRank == 1 )
			return "Ace";
		else if( legalRank == 11 )
			return "Jack";
		else if( legalRank == 12 )
			return "Queen";
		else if( legalRank == 13 )
			return "King";
		else
			return String.valueOf(legalRank);
	}

	public void setLegalSuite(int legalSuite) {
		this.legalSuite = legalSuite;
	}

	

}

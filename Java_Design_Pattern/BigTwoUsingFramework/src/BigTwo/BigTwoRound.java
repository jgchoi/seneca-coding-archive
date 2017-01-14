package BigTwo;


import cgfw.game.GameComposite;
import cgfw.player.Player;

public class BigTwoRound extends GameComposite{
	@Override
	public void postGame() {
		displayRoundCompletion();
		resetPlayersStatus();
		resetCardsOnTable();
	}

	private void resetCardsOnTable() {
		getCardsOnTable().remove(0);
		getCardsOnTable().add(null);
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
		
		for(Player player : getPlayers()){
			if(!((BigTwoPlayer) player).isPassed()){
				return false;
			}
		}
		
		return true;
	}
	
	//Displays when round is completed
    private void displayRoundCompletion() {
        System.out.println("");
        System.out.println("===============");
        System.out.println("Round Completed");
        System.out.println("===============");
        System.out.println("");
    }
    
  //Removed all passed, and currentPlayer status
    private void resetPlayersStatus() {
        for(Player player : getPlayers()){
            ((BigTwoPlayer) player).resetPassStatus();
            ((BigTwoPlayer) player).setCurrentSelection(null);
        }
    }
    
  

}

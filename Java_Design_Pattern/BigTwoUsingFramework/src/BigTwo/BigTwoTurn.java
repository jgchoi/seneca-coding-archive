package BigTwo;

import java.util.ArrayList;

import cgfw.card.Card;
import cgfw.card.CardsStack;
import cgfw.game.GameLeaf;
import cgfw.player.Player;

public class BigTwoTurn extends GameLeaf {
	BigTwoPlayer currentPlayer = null;
	
	public BigTwoPlayer getCurrentPlayer(){
		return currentPlayer;
	}

	@Override
	public void setInitialPlayer() {
		
		
	}

	@Override
	public Player currentPlayer() {
		if(isFirstRound()){
			setPlayerForFirstRound();
		}
		for(Player player : super.getPlayers()){
			if(((BigTwoPlayer) player).isCurrentPlayer()){
				currentPlayer = (BigTwoPlayer) player;
				displayTurnMessage();
				return player;
			}
        }
		
		return null;
		
	}

	@Override
	public void postGame() {
		//Check current player's current selection
		ArrayList<Card> currentSelection = null;
		
		ArrayList<Card> lastSelection = null;
		
		if(currentPlayer.getCurrentSelection() != null){
			currentSelection = currentPlayer.getCurrentSelection();
		}
		
		
		if(currentPlayer.getLastSelection() != null){
			lastSelection = currentPlayer.getLastSelection();
		}
		
		//Did player played new card?
		
		if (currentSelection != null) {
            System.out.print("-Player " + (getPlayers().indexOf(currentPlayer) + 1)
                    + " Played :");
            for (Card card : currentSelection) {
                System.out.print(card);
            }
            System.out.println("");
            
            
            
            //Set current selection as cards on table
            CardsStack newCardsOnTable = new CardsStack();
            for(Card card : currentSelection){
            	newCardsOnTable.addCard(card);
            }
            getCardsOnTable().clear();
            getCardsOnTable().add(newCardsOnTable);
            
           
            //Set current selection as last selection
            currentPlayer.setLastSelection(currentSelection);
            
            //Set empty current selection
            currentPlayer.setCurrentSelection(null);
        }
		
		
		if(!isAllPlayerPassed()){
			//Set for next player
			setNextPlayer();
	
		}		
	}

	private boolean isAllPlayerPassed() {

		for(Player player : getPlayers()){
			if(!((BigTwoPlayer) player).isPassed()){
				return false;
			}
		}
		
		return true;
	}

	@Override
	public void preGame() {
		for(Player player : getPlayers()){
			((BigTwoPlayer) player).setLastSelection(null);
		}
		
		
	}

	@Override
	public void preRun() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void postRun() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public boolean isGameLeafCompleted() {
		if(currentPlayer != null){
			//2 conditions
			ArrayList<Card> currentSelection = currentPlayer.getCurrentSelection();
			boolean isPassed = currentPlayer.isPassed();
			
			//Check If Current Player is winner
			if(isPassed){
				return true;
			}
			
			//Did player played new card?
			if (currentSelection != null) {
				return true;
			}
		}
		return false;
	}
	
	// ---- Added Methods

	//Check all player to see if current player is set
	//If no player is set to be current player
	//return true
	private boolean isFirstRound() {
		for(Player player : super.getPlayers()){
			if(((BigTwoPlayer) player).isCurrentPlayer()){
				return false;
			}
        }
		return true;
	}
	
	private void setPlayerForFirstRound() {
		Player firstPlayer = getPlayerAtIndex(0);
        for(int i=1; i < getPlayers().size();i++){
        	((BigTwoPlayer) firstPlayer).setCurrentPlayer(false);
            if(((BigTwoPlayer) firstPlayer).smallestCard().compareTo(((BigTwoPlayer) getPlayerAtIndex(i)).smallestCard()) > 0){
                firstPlayer = super.getPlayerAtIndex(i);
           }
        ((BigTwoPlayer) firstPlayer).setCurrentPlayer(true);
        }
	}
	
	//Set next player from the array list
    private void setNextPlayer() {
        BigTwoPlayer nextPlayer = (BigTwoPlayer) getPlayerAtIndex((getPlayers().indexOf(currentPlayer) + 1)
                % getPlayers().size());
        currentPlayer.setCurrentPlayer(false);
        currentPlayer = nextPlayer;
        ((BigTwoPlayer) nextPlayer).setCurrentPlayer(true);
    }
	
	//Display message regarding the turn and cards on table and which player's turn to play
    private void displayTurnMessage() {
        System.out.println("");
        //System.out.print("Turn " + ++turnCounter);
        System.out.println(" - Player " + (getPlayers().indexOf(currentPlayer) + 1));
        System.out.println("==================");
        if (getCardsOnTable().get(0) == null) {
            System.out.println("-Table is Empty");
        } else {
            System.out.println("-Cards on Table - Number of Cards ("
                    +getCardsOnTable().get(0).count() + ")");
            System.out.print("-");
            for (Card card : getCardsOnTable().get(0).getAllCards()) {
                System.out.print(card);
            }
            System.out.println("");
        }

    }



}

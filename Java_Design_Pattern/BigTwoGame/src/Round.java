import java.util.ArrayList;


public class Round {
    private ArrayList<Player> players;

    //Setup
    public Round(Boolean _isFirstRound, ArrayList<Player> _players) {
        players = _players;
        if(_isFirstRound){
            setFirstPlayerForFirstRound();
        }
    }

    //Find first player by searching for minimum card (ideally looking for 3D)
    private void setFirstPlayerForFirstRound() {
        Player firstPlayer = players.get(0);
        for(int i=1; i < players.size()-1;i++){
            if(firstPlayer.smallestCard().compareTo(players.get(i).smallestCard()) > 0){
                firstPlayer = players.get(i);
            }
        }
        firstPlayer.setCurrentPlayer(true);
    }


    //Begin round..player take turns until either round completed or any player win
    public void beginRound() {
        Player roundWinner = null;
        Turn turn = new Turn(players);
        while(!isRoundCompleted()){
            roundWinner = turn.play();
        }

        displayRoundCompletion();

        resetPlayersStatus();
        roundWinner.setCurrentPlayer(true);
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
        for(Player player : players){
            player.resetPassStatus();
            player.setCurrentPlayer(false);
        }
    }

    //Round is completed when everyone is passed.
    //Round is completed when any player wins
    //Return the value if round is completed
    public Boolean isRoundCompleted(){
        for(Player player : players){
            if(player.isWin()){
                return true;
            }
            if(!player.isPassed()){
                return false;
            }
        }
        return true;
    }
}

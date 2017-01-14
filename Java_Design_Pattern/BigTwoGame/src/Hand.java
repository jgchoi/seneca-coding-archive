import java.util.ArrayList;

public class Hand {
    private ArrayList<Player> players;
    private Deck deck;
    private static final int BigTwoCardsQuantity = 13;

    //---- Set Up ----
    public Hand(ArrayList<Player> _players) {
        players = _players;
        deck = new Deck();
        setPlayers();
    }

    //Set player's card on hand
    private void setPlayers(){
        for (Player player : players){
            player.setCards(deck.getRandomCards(BigTwoCardsQuantity));
        }
    }

    // ---- Play ----
    //Goal of Hand - use all cards!
    //Play round until any player used all cards
    public void beginBigTwo(){
        Boolean isFirstRound = true;
        while(!isBigTwoCompleted()){
            Round round = new Round(isFirstRound, players);
            round.beginRound();
            isFirstRound = false;
        }
        updateScore();
        displayScores();
    }

    //Goal of Big Two is one player is win the round
    public Boolean isBigTwoCompleted(){
        for(Player player : players){
            if(player.isWin()){
                return true;
            }
        }
        return false;
    }

    //---- After BigTwo is Completed ----
    //After big two is completed update score for BigTwo to recognize
    private void updateScore() {
        System.out.println("====================");
        System.out.println("Big Two is Completed");
        System.out.println("====================");

        // Score = number of cards left * 2 ^ number of 2 draw by last player
        int numberOfCardsLeft = 0;
        int numberOfTwo = 0;
        int score = 0;
        Player winner = null;

        for (Player player : players){
            numberOfCardsLeft += player.numberOfCards();
            if(player.isWin()){
                winner = player;
                numberOfTwo = player.numberOfTwoInLastPlayedCards();
            }
        }

        if(numberOfTwo != 0){
            score = (int) (numberOfCardsLeft * Math.pow(2, numberOfTwo));
        }else{
            score = numberOfCardsLeft;
        }

        System.out.println("-Winnder: Player " + (players.indexOf(winner)+1));
        System.out.println("-Score Earned: " + score);
        winner.updateScore(score);
    }

    //Displays score
    private void displayScores() {
        System.out.println("");
        System.out.println("====================");
        System.out.println("     Score Board");
        System.out.println("====================");
        System.out.println("");
        for(Player player : players){
            System.out.print("-Player" + (players.indexOf(player)+1));
            System.out.println(" Score " + player.getScore() + "/49");
        }
    }



}

import java.util.ArrayList;

public class Turn {
    private ArrayList<Player> players;
    private ArrayList<Card> lastPlayedCards;
    private Player currentPlayer;
    private int turnCounter = 0;

    //Set all players and cards on table (i.e. lastPlayedCards)
    public Turn(ArrayList<Player> _players) {
        players = _players;
        lastPlayedCards = new ArrayList<Card>();
    }

    //Decide which player's turn to play based on player's status
    private void setCurrentPlayer() {
        for (Player player : players) {
            if (player.isCurrentPlayer()) {
                player.setCurrentPlayer(false);
                currentPlayer = player;
            }
        }
    }

    //Play the turn with current turn player
    //Return Last played player for keep track of round winner
    public Player play() {
        setCurrentPlayer();
        setNextPlayer();
        displayTurnMessage();

        ArrayList<Card> _lastPlayedCards = currentPlayer.takeTurn(lastPlayedCards);

        if (_lastPlayedCards != null) {
            lastPlayedCards = _lastPlayedCards;
            System.out.print("-Player " + (players.indexOf(currentPlayer) + 1)
                    + " Played :");
            for (Card card : lastPlayedCards) {
                System.out.print(card);
            }
            System.out.println("");
        } else {
            System.out.println("-Player passed");
        }

        return currentPlayer;
    }

    //Set next player from the array list
    private void setNextPlayer() {
        Player nextPlayer = players.get((players.indexOf(currentPlayer) + 1)
                % players.size());
        nextPlayer.setCurrentPlayer(true);
    }

    //Display message regarding the turn and cards on table and which player's turn to play
    private void displayTurnMessage() {
        System.out.println("");
        System.out.print("Turn " + ++turnCounter);
        System.out.println(" - Player " + (players.indexOf(currentPlayer) + 1));
        System.out.println("==================");
        if (lastPlayedCards.size() == 0) {
            System.out.println("-Table is Empty");
        } else {
            System.out.println("-Cards on Table - Number of Cards ("
                    + lastPlayedCards.size() + ")");
            System.out.print("-");
            for (Card card : lastPlayedCards) {
                System.out.print(card);
            }
            System.out.println("");
        }

    }
}
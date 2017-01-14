import java.util.ArrayList;
import java.util.Scanner;

public class BigTwo {
    private ArrayList<Player> players;
    private int numberOfPlayers;
    private int numberOfNPC;

    //Constructor - Show Title, get number of players, and set players
    public BigTwo(){
        displayGameTitle();
        getNumberOfPlayers();
        setPlayers();
    }

    //Show BigTwo Title
    private void displayGameTitle(){
        System.out.println("BIG TWO");
        System.out.println("=======");
        System.out.println("");
    }


    //Set number of players by user input
    private void getNumberOfPlayers(){
        System.out.println("Setting Players");
        System.out.println("===============");

        Scanner reader = new Scanner(System.in);

        System.out.print("Enter a number of players (integers only!! Min:2 Max:4): ");
        numberOfPlayers = reader.nextInt();

        System.out.print("Enter a number of NPC players (Less than number of players): ");
        numberOfNPC = reader.nextInt();
    }

    //Set players as person or non-person player
    private void setPlayers(){
        players = new ArrayList<Player>();

        for (int i = 0; i < numberOfPlayers; i++){
            Player newPlayer;
            if(i < numberOfNPC){
                newPlayer = new NPCPlayer();
            }else{
                newPlayer = new Player();
            }
            players.add(newPlayer);
        }
    }

    //---- BigTwo Play ----
    public void beginGame(){
        //Play Hand until one player gets score of 49!
        while(!isGameCompleted()){
            Hand hand = new Hand(players);
            hand.beginBigTwo();
        }
    }

    //Check if any player have reached score of 49..
    private Boolean isGameCompleted(){
        for(Player player : players){
            if(player.getScore() >= 49){
                return true;
            }
        }
        return false;
    }
}

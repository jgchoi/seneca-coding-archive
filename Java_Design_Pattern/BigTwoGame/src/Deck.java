import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Deck {
    private ArrayList<Card> cards;

    public Deck(){
        cards = new ArrayList<Card>();
        setDeck();
    }

    //Set a single deck -- from 0 ~ 12 (index for A - K) type of 0 ~ 3 (index for DCHS)
    private void setDeck(){
        //2~9,j,q,k,a for DCHS (D = lowest, S = strongest)
        for(int i = 0; i < Card.NumberOfRange; i++){
            for(int j = 0; j < Card.NumberOfTypes; j++){
                cards.add(new Card(i,j));
            }
        }
    }

    //Suffle the cards in the deck..
    private void shuffle(){
        long seed = System.nanoTime();
        Collections.shuffle(cards, new Random(seed));
    }

    //Suffle the cards then return the set of cards based on the
    //int from the parameter
    public ArrayList<Card> getRandomCards(int quantity) {
        shuffle();
        ArrayList<Card> cardsForPlayer = new ArrayList<Card>();
        for(int i=0; i < quantity; i++){
            cardsForPlayer.add(cards.remove(0));
        }
        return cardsForPlayer;
    }
}

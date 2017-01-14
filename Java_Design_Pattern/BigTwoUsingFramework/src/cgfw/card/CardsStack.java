package cgfw.card;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class CardsStack {
	protected ArrayList<Card> cards;
	
	//Creates empty cards stack
	public CardsStack(){
		cards = new ArrayList<Card>();
	}
	
	//Suffle cards in stack
	public void shuffle(){
		long seed = System.nanoTime();
		Collections.shuffle(cards, new Random(seed));
	}
	
	//Remove card object at stack
	public Card removeCard(Card card){
		return cards.remove(cards.indexOf(card));
	}
	
	//Return number of cards in stack
	public int count(){
		return cards.size();
	}
	
	//Add new card (required for some game)
	public void addCardToTop(Card card){
		addCard(card);
	}
	
	public ArrayList<Card> getAllCards(){
		return cards;
	}
	
	//Add new card
	public void addCard(Card card){
		cards.add(card);
	}
	
	//remove card from top (last card added)
	public Card removeCardFromTop(){
		return cards.remove(cards.size()-1);
	}
	
	//return last card added
	public Card getCardFromTop(){
		return cards.get(cards.size()-1);
	}
	
	//return cards with given index with datatype int
	public Card getCardAtIndex(int index){
		return cards.get(index);
	}
	
	//delete card at index and return it as Card object
	public Card removeCardAtIndex(int index){
		return cards.remove(index);
	}
	
	//Add another list of cardstack into current stack
	public void appendCardsStack(CardsStack anotherCards){
		for(Card card : anotherCards.cards)
			cards.add(card);
	}
	
	//Sort card with given compare method defined in Card
	public void sort(){
		Collections.sort(cards);
	}

}

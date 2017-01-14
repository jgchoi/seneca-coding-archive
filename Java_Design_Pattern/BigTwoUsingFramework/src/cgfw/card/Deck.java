package cgfw.card;

public class Deck extends CardsStack {
	private static boolean hasJoker = false;
	private static int numberOfDecks = 1;
	
	public Deck(){
		super();
		setNewDecks();
	}
	
	//Create new deck with given number of decks
	private void setNewDecks() {
		for(int i=0; i<numberOfDecks; i++)
			appendADeck();
	}

	//Create a (1) deck and append it to card stack
	private void appendADeck() {
		//Add 2 Jokers to deck
		if(hasJoker){
			Card joker = new Card();
			joker.setJoker(true);
			cards.add(joker);
			cards.add(joker);
		}
		
		//Add all other cards
		for(int i=0; i < Card.numberOfRanks; i++)
			for(int j=0; j < Card.NumberOfSuites; j++)
				cards.add(new Card(i,j));	
	}

	//Set the deck as having jokers or not when creating the deck
	public static void setHasJoker(boolean _hasJoker){
		hasJoker = _hasJoker;
	}
	
	//Set the number of decks need to be created upon new deck request
	public static void setNumberOfDecks(int _numberOfDecks){
		numberOfDecks = _numberOfDecks;
	}
	
	//Return shffled card with given number of cards requested
	public CardsStack getCards(int numberOfCards){
		super.shuffle();
		CardsStack cardsForPlayer = new CardsStack();
		for(int i=0; i < numberOfCards; i++){
			cardsForPlayer.addCard(cards.remove(0));
		}
		return cardsForPlayer;
	}

}

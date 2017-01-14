package cgfw.card;

public class Card implements Comparable<Card>{
	private int rank;
	private int suite;
	private boolean isJoker;
	private static String[] suites = new String[] {"D", "C", "H", "S"}; // Default
	private static final String[] ranks = new String[] {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	private static int highestRank = 0;
	
	//What's the range of cards? A - K = 13
	public static final int numberOfRanks = 13;
	//What types of cards are used. If all, return 4
	public static final int NumberOfSuites = 4;
	
	//Default constructor
	public Card(){
		rank = -1;
		suite = -1;
	}
	
	public static void setHighestRank(int _highestRank){
		highestRank = _highestRank;
	}
	
	//Return String Value of Rank
	public int getRank(){
		return rank;
	}
	
	// Get Rank face value
	public int getRankFaceValue() {
		return rank+1;
	}
	
	// Are cards equal
	public boolean isEqualTo(Card card) {
		return ( card.rank == this.rank && card.suite == this.suite ) ? true : false;
	}
	
	// Return true if cards have the same suite
	public boolean isSameSuite(Card card) {
		return ( card.suite == this.suite ) ? true : false;
	}
	
	//Return index (integer) Value of Suite
	public int getSuite(){
		return suite;
	}
	
	// Return string name of suite
	public String getSuiteName() {
		if( suite == 0)
			return "Diamond";
		else if( suite == 1)
			return "Club";
		else if( suite == 2 )
			return "Heart";
		else if( suite == 3 )
			return "Spade";
		else
			return null;
	}
	
	// Return string name of suite
	public String getRankName() {
		if( rank == 0 )
			return "Ace";
		else if( rank == 10 )
			return "Jack";
		else if( rank == 11 )
			return "Queen";
		else if( rank == 12 )
			return "King";
		else
			return String.valueOf(rank+1);
	}
	
	//Set a card as joker
	//Receives boolean value to set to variable
	public void setJoker(boolean _isJoker){
		isJoker = _isJoker;
	}
	
	//Return true if the card is set as joker
	public boolean isJoker(){
		return isJoker;
	}
	
	//Cocstructor with int
	public Card(int _rank, int _suite){
		rank = _rank;
		suite = _suite;
	}
	
	//Hard Copy of card object
	public Card(Card card) {
		rank = card.rank;
		suite = card.suite;
	}

	//Return card information as UI string
	public String toString(){
		return "["+ranks[rank]+suites[suite]+"]";
	}
	
	// Return detailed card information as a statement for UI
	public String toStringDetail() {
		return (ranks[rank] + " of " + getSuiteName());
	}
	
	//Compare current card with other card given
	//return 1 if self is larger, -1 if smaller, 0 if same (rank and suite)
	public int compareTo(Card otherCard) {
		if(getAbsoluteNumber() < otherCard.getAbsoluteNumber()){
			return -1;
		}
		
		if(getAbsoluteNumber() > otherCard.getAbsoluteNumber()){
			return 1;
		}
		
		//If same number
		if(suite < otherCard.suite){
			return -1;
		}else if(suite > otherCard.suite){
			return 1;
		}
		
		//Same Card
		return 0;
	}
	
	//Return card rank as set by configuration
	private int getAbsoluteNumber(){
		return (rank+(13-highestRank))%13;
	}
	
	//Check if two cards are same
	public boolean equals(Card otherCard) { 
		return compareTo(otherCard) == 0 ? true : false;
	}
	
	
}

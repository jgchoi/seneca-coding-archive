public class Card implements Comparable<Card>{
    private int number;
    private int typeIndex;
    private static final char[] types = new char[] {'D', 'C', 'H', 'S'};
    private static final String[] numbers = new String[] {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    //What's the range of cards? A - K = 13
    public static final int NumberOfRange = 13;

    //What types of cards are used. If all, return 4
    public static final int NumberOfTypes = 4;

    //Default constructor - should not be called
    public Card(){
        number = -1;
        typeIndex = -1;
    }

    public int getType(){ return typeIndex;}

    //Return number on the card
    public int getNumber(){
        return number;
    }

    //Constructor for card with given number and type
    public Card(int _number, int _typeIndex){
        number = _number;
        typeIndex = _typeIndex;
    }

    //Copy constructor it's a hard copy
    public Card(Card _card) {
        number = _card.number;
        typeIndex = _card.typeIndex;
    }

    //Return string of Card in format
    public String toString(){
        return "["+numbers[number]+types[typeIndex]+"]";
    }

    //Compare two cards, receive other Card object
    //Return -1 if This object is smaller, 0 for same, 1 if larger
    public int compareTo(Card _otherCard) {
        // 2 is largest range is 0 ~ 12, to make 2 is the largest, add +10 to value and mod by 13, 2 will be the largest
        if(getAbsoluteNumber() < _otherCard.getAbsoluteNumber()){
            return -1;
        }

        if(getAbsoluteNumber() > _otherCard.getAbsoluteNumber()){
            return 1;
        }

        //If same number
        if(typeIndex < _otherCard.typeIndex){
            return -1;
        }else if(typeIndex > _otherCard.typeIndex){
            return 1;
        }

        //Same Card
        return 0;
    }

    //Since big 2's biggest card is 2,, add 11 and mod 13 gives correct number for compare
    private int getAbsoluteNumber(){
        return (number+11)%13;
    }

    //return true if two cards are equal
    public boolean equals(Card otherCard) {
        return compareTo(otherCard) == 0 ? true : false;
    }
}

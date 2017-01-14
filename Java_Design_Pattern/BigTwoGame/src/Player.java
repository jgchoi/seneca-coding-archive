import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Player {
    protected ArrayList<Card> cards;
    protected ArrayList<Card> lastSelection;
    private int score;
    protected Boolean passed;
    private Boolean isCurrentPlayer;
    private enum HandType { STRAIGHT_FLASH(5), FOUR_OF_KIND(4), FULL_HOUSE(3), FLASH(2), STRAIGHT(1);
        private final int power;

        private HandType(int power) {
            this.power = power;
        }};

    public Player(){
        cards = new ArrayList<Card>();
        updateScore(0);
        passed = false;
        isCurrentPlayer = false;
    }

    //hold the cards for the player
    public void setCards(ArrayList<Card> _card) {
        cards = _card;
        Collections.sort(cards);
    }

    //Return current score
    public int getScore() {
        return score;
    }

    //Append score with given from the parameter
    public void updateScore(int _score) {
        score += _score;
    }

    //Return boolean value for if player win the Hand bt checking number of cards on hand
    public boolean isWin() {
        return cards.size()==0 ? true : false;
    }

    //Return boolean value if player has passed for the round
    public boolean isPassed() {
        return passed;
    }

    //Reset the pass status to false
    public void resetPassStatus() {
        passed = false;
    }

    //Return smallest card - by comparsion method defined by Card
    public Card smallestCard() {
        Card smallestCard = new Card(cards.get(0));
        return smallestCard;
    }

    //Select appropriate card
    //Getting cards on table by previous player
    //Return set of card that selected from cards on hand
    public ArrayList<Card> takeTurn(ArrayList<Card> _lastPlayedCards) {
        //if user already passed, return null
        if(passed){
            System.out.println("Player already passed");
            return null;
        }

        //If there's no card to play .. that means this user won the game
        if(cards.size() == 0){
            System.out.println("No more cards to play. Player Won.");
            passed = true;
            return null;
        }

        //return selection of cards (either PC or NPC)
        return getCardSelection(_lastPlayedCards);
    }

    //Human Player's method for selecting cards to play
    protected ArrayList<Card> getCardSelection(ArrayList<Card> _lastPlayedCards) {
        int numberOfCards = 0;
        ArrayList<Card> selected = null;

        Scanner reader = new Scanner(System.in);

        boolean isUserSelectionValid = false;

        while(!isUserSelectionValid) {

            //Display cards on hand
            displayCards();

            selected = new ArrayList<Card>();
            if (_lastPlayedCards.size() == 0) {
                //First player, choose how many cards to draw
                System.out.print("Choose number of cards to play - Single(1), Double(2), Triple(3), Poker Combination (5): ");
                numberOfCards = reader.nextInt();
            } else {
                numberOfCards = _lastPlayedCards.size();
            }


            for (int i = 0; i < numberOfCards; i++) {
                System.out.print("Enter card number - Selected Cards(" + (i) + "/" + numberOfCards + "): ");
                int cardIndex = reader.nextInt();
                if (cardIndex == 0) {
                    if(cards.get(0).compareTo(new Card(2,0))==0){
                        System.out.println("Player with 3D can't pass");
                    }
                    passed = true;
                    return null;
                }
                selected.add(cards.get(cardIndex - 1));
            }

            Collections.sort(selected);

            isUserSelectionValid = isValidSelection(_lastPlayedCards, selected);
        }

        //Remove selected card from cards on hand when selection is valid
        for(Card card : selected){
            cards.remove(card);
        }

        lastSelection = selected;

        return selected;
    }

    //Check if user selected card is valid and return boolen
    //Takes cards on the table and cards selected
    private boolean isValidSelection(ArrayList<Card> _lastPlayedCards, ArrayList<Card> _selected) {
        if(_selected.size() == 4){
            System.out.println("Cannot choose 4 cards..");
            return false;
        }

        if(_selected.size() == 0){
            System.out.println("First player can't pass");
            return false;
        }

        //If first player
        if(_lastPlayedCards.size() == 0){
            //If user have 3D, selection must have 3D
            Card smallestCardFromHand = cards.get(0);
            Card smallestCardFromSelection = _selected.get(0);
            if(smallestCardFromHand.compareTo(new Card(2,0)) == 0){
                if(smallestCardFromHand.compareTo(smallestCardFromSelection) != 0){
                    System.out.println("Invalid Card(s): 3D must be included");
                    return false;
                }
            }
        }

        //Card size 1 ~ 3 - number must be same
        int cardSize = _selected.size();
        if(cardSize == 1 | cardSize == 2 | cardSize == 3){
            boolean result = true;
            int cardNumber = _selected.get(0).getNumber();
            //Check if card is valid (all same)
            for (Card card: _selected) {
                if(card.getNumber() != cardNumber){
                    System.out.println("Invalid Card(s): For single, double, and triple cards, all cards should have same number");
                    return false;
                }
            }

            //Check if selected card is higher than lastPlayedCards
            if(_lastPlayedCards.size() != 0 && _lastPlayedCards.get(cardSize-1).compareTo(_selected.get(cardSize-1)) > 0){
                System.out.println("Invalid Card(s): Selected cards are smaller(weaker) than the cards on the table");
                return false;
            }
        }

        //If card size is 5...
        //straight flush / four of kinds / full house/ flush / Straight

        if(cardSize == 5){

            HandType typeOfSelectedCard = findHandType(_selected);
            System.out.println(" - Poker Hand Detected: " + typeOfSelectedCard);
            if(typeOfSelectedCard == null) {
                System.out.println("Selected 5 cards are not poker hands");
                return false;
            }

            //Compare power if there's cards on table
            if(_lastPlayedCards.size() != 0 ) {
                HandType typeOfCardOnTable = findHandType(_lastPlayedCards);
                //5 Cards are weaker than the cards on table
                if (typeOfCardOnTable.power > typeOfSelectedCard.power) {
                    System.out.println("Selected 5 cards are weaker than cards on table");
                    return false;
                }

                //5 Cards are same rank but still weaker
                if (typeOfCardOnTable.power == typeOfCardOnTable.power) {
                    if (typeOfCardOnTable == HandType.FLASH || typeOfCardOnTable == HandType.STRAIGHT || typeOfCardOnTable == HandType.STRAIGHT_FLASH) {
                        //This case, just compare the largest
                        if (_lastPlayedCards.get(cardSize - 1).compareTo(_selected.get(cardSize - 1)) > 0) {
                            System.out.println("Selected 5 cards are same rank but weaker than cards on table:FLASH/STRAIGHT/STRAIGHTFLASH");
                            return false;
                        }
                    } else {
                        //For full house and fourcard, compare middle one
                        if (_lastPlayedCards.get(2).compareTo(_selected.get(2)) > 0) {
                            System.out.println("Selected 5 cards are same rank but weaker than cards on table:FullHouse/FOURCARDS");
                            return false;
                        }
                    }
                }
            }
        }

        //All test passed
        return true;
    }

    //Check cards hands return the type of hands
    //Taks set of Card objects
    private HandType findHandType(ArrayList<Card> _cards) {
        boolean isStraight = true;
        for(int i=0; i<4; i++){
            if((_cards.get(i).getNumber()+1)%13 != _cards.get(i+1).getNumber()){
                isStraight = false;
            }
        }

        //Flash?
        boolean isFlash = true;
        int cardType = _cards.get(0).getType();
        for (Card card: _cards) {
            if(card.getType() != cardType){
                isFlash = false;
            }
        }

        boolean isFourOfKind = false;
        boolean isFullHouse = false;
        //Four Cards?
        //Possible case XXXX Y OR Y XXXX
        if((    _cards.get(0).getNumber() == _cards.get(1).getNumber() &&
                _cards.get(1).getNumber() == _cards.get(2).getNumber() &&
                _cards.get(2).getNumber() == _cards.get(3).getNumber()    ) ||
            (   _cards.get(1).getNumber() == _cards.get(2).getNumber() &&
                _cards.get(2).getNumber() == _cards.get(3).getNumber() &&
                _cards.get(3).getNumber() == _cards.get(4).getNumber()    )){
            isFourOfKind = true;
        }else
        if((    _cards.get(0).getNumber() == _cards.get(1).getNumber() &&
                _cards.get(1).getNumber() == _cards.get(2).getNumber()    ) ||
            (   _cards.get(2).getNumber() == _cards.get(3).getNumber() &&
                _cards.get(3).getNumber() == _cards.get(4).getNumber()    )){

            //Full House?
            ///Possible case XXX YY OR YY XXX
            isFullHouse = true;
        }

        if(isFlash && isStraight){
            return HandType.STRAIGHT_FLASH;
        }else if(isFlash){
            return HandType.FLASH;
        }else if(isStraight){
            return HandType.STRAIGHT;
        }else if(isFourOfKind){
            return HandType.FOUR_OF_KIND;
        }else if(isFullHouse){
            return HandType.FULL_HOUSE;
        }else{
            return null;
        }
    }

    //Displays cards on hand
    public void displayCards() {
        System.out.print("Cards on Hand:\n");
        int i = 1;
        for (Card card : cards){
            System.out.print(i+++".");
            System.out.print(card);
            System.out.print(" ");
        }
        System.out.print("0.Pass");
        System.out.println("");

    }

    //Return number of cards on hand
    public int numberOfCards() {
        return cards.size();
    }

    //Return how many 2 were played for last play (used for score calculation)
    public int numberOfTwoInLastPlayedCards() {
        int numberOfTwo = 0;
        for(Card card : lastSelection){
            if (card.getNumber() == 2){
                numberOfTwo++;
            }
        }
        return numberOfTwo;
    }

    //Set the player as current player
    public void setCurrentPlayer(Boolean _isFirstPlayer) {
        isCurrentPlayer = _isFirstPlayer;
    }

    //Return the boolean value if the player is the current player
    public boolean isCurrentPlayer() {
        return isCurrentPlayer;
    }
}

class NPCPlayer extends Player{

    //NPC - Really really simple AI
    protected ArrayList<Card> getCardSelection(
            ArrayList<Card> _lastPlayedCards) {

        //If not begin or single, no cards to play pass.
        if(_lastPlayedCards.size() > 1 || cards.size() == 0){
            passed = true;
            return null;
        }

        //If begin, return single, smallest
        ArrayList<Card> selected = new ArrayList<Card>();

        //if NPC is the first player, always draw smallest single
        if(_lastPlayedCards.size() == 0){
            selected.add(cards.remove(0));
        } else {
            //Otherwise... select random within the range..
            int cardSize = _lastPlayedCards.size();
            Card minimumRequired = _lastPlayedCards.get(cardSize-1);

            //Filter drawable cards... (larger than minium card)
            ArrayList<Card> drawable = new ArrayList<Card>();
            for(Card card : cards){
                if(minimumRequired.compareTo(card)<0){
                    drawable.add(card);
                }
            }

            //There is no card to play
            if(drawable.size() == 0){
                //pass and return null
                passed = true;
                return null;
            }

            int randomNumber = (int)(Math.random() * drawable.size());
            selected.add(drawable.get(randomNumber));
        }

        //removed selected cards
        for(Card card : selected){
            cards.remove(card);
        }

        //Sort selected
        Collections.sort(selected);

        lastSelection = selected;

        //return
        return selected;
    }
}

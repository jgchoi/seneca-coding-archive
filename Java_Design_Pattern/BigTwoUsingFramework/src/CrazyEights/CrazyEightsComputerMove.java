package CrazyEights;

import java.util.ArrayList;

import cgfw.card.Card;
import cgfw.card.CardsStack;
import cgfw.game.Game;
import cgfw.game.move.MoveStrategy;
import cgfw.player.Player;

public class CrazyEightsComputerMove implements MoveStrategy {
	
	private Game game;
	private Player currentPlayer;
	CrazyEightsGame gameComposite;
	CrazyEightsTurn gameTurn;

	@Override
	public void move() {
		// Initialize game components
		initializeGameData();	
		
		ArrayList<Card> playable = new ArrayList<>();           // Playable cards
        ArrayList<Integer> cardIndex = new ArrayList<>();       // Index position of corresponding playable card in the player's cards list
        ArrayList<Integer> wildCardIndex = new ArrayList<>();   // Wild '8's

        // Get legal move options: Same rank, same suit or wild cards
        CardsStack cards = currentPlayer.getCardsInHand();
        System.out.println("");
		System.out.println("Current Player =======> " + currentPlayer.getUserName());
        
        for( int i = 0; i < cards.count(); i++ )
        {

            if( cards.getCardAtIndex( i ).getRankFaceValue() == 8 )
                wildCardIndex.add( i );
            else {
                if( cards.getCardAtIndex( i ).getSuite() == gameTurn.getLegalSuite() ) {
                    playable.add( cards.getCardAtIndex( i ) );
                    cardIndex.add( i );
                }
                if( cards.getCardAtIndex( i ).getRankFaceValue() == gameTurn.getLegalRank() ) {
                    playable.add( cards.getCardAtIndex( i ) );
                    cardIndex.add( i );
                }
            }
        }

        // If computer has legal move options: Same suit or same rank cards
        if( playable.size() > 0 )
        {
            int numOfCardsOfSameSuit = 0;
            int pos = -1;

            // Calculates which suit cards, out of the playable options, it has the most of
            for( int i = 0; i < playable.size(); i++ )
            {
                if( numOfSameSuitCards( playable.get( i ) ) >= numOfCardsOfSameSuit )
                {
                    numOfCardsOfSameSuit = numOfSameSuitCards( playable.get( i ) );
                    pos = i;
                }
            }

            // Computer attempts to play card of the suit that he has the most cards of (Calculated above).
            // Attempts to get rid of the card with the most points. Makes the move.
            Card selectedCard = cards.getCardAtIndex( cardIndex.get( pos ) );
            
            // If playing the same suit card, play the highest value suit card in hand
            if( selectedCard.getSuite() == gameTurn.getLegalSuite() )
            {
                int x = indexOfHighestCardOfSuit( selectedCard );
                if( gameTurn.currentPlayer().getCardsInHand().getCardAtIndex(x).getRankFaceValue() != 8 )
                    gameComposite.getStarterPile().addCardToTop( gameTurn.currentPlayer().getCardsInHand().removeCardAtIndex(x) );
                else
                	gameComposite.getStarterPile().addCardToTop( gameTurn.currentPlayer().getCardsInHand().removeCardAtIndex( cardIndex.get( pos ) ) );
            }
            // Play the same rank card
            else if( selectedCard.getRankFaceValue() == gameTurn.getLegalRank() )
            {
            	gameComposite.getStarterPile().addCardToTop( gameTurn.currentPlayer().getCardsInHand().removeCardAtIndex( cardIndex.get( pos ) ) );
            }

            Card topCard = gameComposite.getStarterPile().getCardFromTop();
            gameTurn.setLegalRank( topCard.getRankFaceValue() );
            gameTurn.setLegalSuite( topCard.getSuite() );
            
            System.out.println( gameTurn.currentPlayer().getUserName() + " played : *" + topCard.toStringDetail() + "*" );
            CrazyEightsTurn.validMoveMade = true;   // Legal move made
            CrazyEightsGame.consecutivePasses = 0;
        }
        // If user doesn't have same suit or rank cards, but has wild cards
        else if( playable.size() <= 0 && wildCardIndex.size() > 0)
        {
        	gameComposite.getStarterPile().addCardToTop( gameTurn.currentPlayer().getCardsInHand().removeCardAtIndex( wildCardIndex.get(wildCardIndex.size()-1) ) );
            System.out.println( gameTurn.currentPlayer().getUserName() + " played a WILD EIGHT!!! : *" + gameComposite.getStarterPile().getCardFromTop().toString() + "*");
            gameTurn.setLegalRank(8);

            for( int i = 3; i >= 0; i--)
            {
                if( numOfSameSuitCards( new Card( 1, 0 ) ) >= i )
                	gameTurn.setLegalSuite(0);
                else if( numOfSameSuitCards( new Card( 1, 1 ) ) >= i )
                	gameTurn.setLegalSuite(1);
                else if( numOfSameSuitCards( new Card( 1, 2 ) ) >= i )
                	gameTurn.setLegalSuite(2);
                else if( numOfSameSuitCards( new Card( 1, 3 ) ) >= i )
                	gameTurn.setLegalSuite(3);
            }
            System.out.println( gameTurn.currentPlayer().getUserName() + " has chosen the suit: " + gameTurn.getLegalSuiteName() );
            CrazyEightsTurn.validMoveMade = true;   // Legal move made
            CrazyEightsGame.consecutivePasses = 0;
        }
        // No playable cards, no wild cards in hand to play. Draw card from the deck
        else
        {
            System.out.println( "Drawing a card from the Deck........");
            if( gameComposite.getStockPile().count() > 0 )
            	gameTurn.currentPlayer().getCardsInHand().addCardToTop( gameComposite.getStockPile().removeCardFromTop() );
            else
            {
                System.out.println("Game Deck is empty, Player will pass his turn");
                CrazyEightsGame.consecutivePasses++;
                CrazyEightsTurn.validMoveMade = true;   // Legal move made
            }

        }
        
	}
	
	private void initializeGameData() {
		game = Game.getInstance();
				
		if( game.getGameComponent() instanceof CrazyEightsGame )
			gameComposite = (CrazyEightsGame) game.getGameComponent();
		if( gameComposite.getGameComponent() instanceof CrazyEightsTurn ) {
			gameTurn = (CrazyEightsTurn) gameComposite.getGameComponent();
			currentPlayer = ((CrazyEightsTurn) gameComposite.getGameComponent()).currentPlayer();
		}
		
	}
	
	 // Returns number of cards of the same suit as the card passed
    public int numOfSameSuitCards(Card cardToMatch) {
        int total = 0;
        for(Card card: currentPlayer.getCardsInHand().getAllCards() )
        {
            if(card.isSameSuite(cardToMatch))
                total++;
        }
        return total;
    }

    // Returns the card of the highest value, same suit as the card passed
    public int indexOfHighestCardOfSuit(Card card) {
        int value = 0;
        int index = -1;
        for( int i = 0; i < currentPlayer.getCardsInHand().count(); i++ )
        {
            if( currentPlayer.getCardsInHand().getCardAtIndex(i).isSameSuite(card) )
            {
                if (currentPlayer.getCardsInHand().getCardAtIndex(i).getRankFaceValue() >= value) {
                    value = currentPlayer.getCardsInHand().getCardAtIndex(i).getRankFaceValue();
                    index = i;
                }
            }
        }
        return index;
    }

}

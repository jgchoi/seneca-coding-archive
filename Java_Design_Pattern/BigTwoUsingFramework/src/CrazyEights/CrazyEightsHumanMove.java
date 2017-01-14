package CrazyEights;

import java.util.Scanner;

import cgfw.card.Card;
import cgfw.game.Game;
import cgfw.game.move.MoveStrategy;
import cgfw.player.Player;

public class CrazyEightsHumanMove implements MoveStrategy {

	private Game game;
	private Player currentPlayer;
	CrazyEightsGame gameComposite;
	CrazyEightsTurn gameTurn;
	
	@Override
	public void move() {
		
		initializeGameData();
		System.out.println("");
		System.out.println("Current Player (Computer) =======> " + currentPlayer.getUserName());
        int option;

        @SuppressWarnings("resource")
		Scanner input = new Scanner(System.in);
        String proceed = "";

        // Display cards in hand for the player
        while( !proceed.equalsIgnoreCase( "Y" ))
        {
            System.out.print( currentPlayer.getUserName() + " Ready to view your cards? [Y]=> " );
            proceed = input.nextLine();
        }

        System.out.println();
        System.out.println();
        System.out.println(" OPTIONS |   MOVE  ");
        for (option = 1; option <= currentPlayer.getCardsInHand().count(); option++ )
        {
            System.out.println( "[  " + option + "  ] " + currentPlayer.getCardsInHand().getCardAtIndex(option-1).toString() );
        }
        System.out.println( "[  " + option + "  ] Draw a card from the Deck" + "\n");

        int choice;

        try
        {
            System.out.print( " Your Move (Choice number) : " );
            choice = input.nextInt();
        } catch(Exception e) {
            System.out.println("Invalid Input type");  // input not an integer
            input.nextLine();                           // clear buffer
            choice = 0;
        }
        System.out.println();

        // Play selected Card or draw from deck
        Card selectedCard;

        if( choice > 0 && choice < option)
        {
            selectedCard = currentPlayer.getCardsInHand().getCardAtIndex(choice - 1);
            System.out.println("You've played : *" + selectedCard.toStringDetail() + "*");

            // Check if selected card can be played as a legal move
            if( selectedCard.getRankFaceValue() == gameTurn.getLegalRank()
                    || ( selectedCard.getSuite() == gameTurn.getLegalSuite() )
                    || selectedCard.getRankFaceValue() == 8 )
            {
                Card cardPlayed = gameTurn.currentPlayer().getCardsInHand().removeCardAtIndex(choice-1);
                gameComposite.getStarterPile().addCardToTop( cardPlayed );
                gameTurn.setLegalRank( cardPlayed.getRankFaceValue() );
                gameTurn.setLegalSuite( cardPlayed.getSuite() );

                // Player plays an '8', eights are 'wild'
                if( cardPlayed.getRankFaceValue() == 8 )
                {
                	gameTurn.setLegalRank( 8 );
                	gameTurn.setLegalSuite( -1 );

                    // Get a valid choice of suit
                    while(gameTurn.getLegalSuite() == -1) {
                        try
                        {
                            System.out.print( "You can specify the new suit [1] Diamond, [2] Club, [3] Heart, OR [4] Spade: " );
                            choice = input.nextInt();
                        } catch (Exception e) {
                            System.out.println("Invalid Input type");           // Input is not an integer
                            input.nextLine();                                   // Clear buffer
                            choice = 0;
                        }
                        System.out.println();
                        if( choice >= 1 && choice <= 4) 
                        	gameTurn.setLegalSuite(choice - 1); 
                        else {
                        	gameTurn.setLegalSuite(-1) ;
                        	System.out.println("Invalid Selection");  
                        }
                    }
                }
                CrazyEightsTurn.validMoveMade = true;
                CrazyEightsGame.consecutivePasses = 0;
            }
            else {
                System.out.println("Invalid move. Card must be the same rank or the same suit as the top card.");
                CrazyEightsTurn.validMoveMade = false;
            }
        }
        // Draw a card from the deck
        else if ( choice == option )
        {
            System.out.println( "Drawing a card from the Deck........");
            if( gameComposite.getStockPile().count() > 0)
            	gameTurn.currentPlayer().getCardsInHand().addCardToTop( gameComposite.getStockPile().removeCardFromTop() );
            else
            {
            	System.out.println("Game Deck is empty, Player will pass his turn");
                CrazyEightsGame.consecutivePasses++;
                CrazyEightsTurn.validMoveMade = true;   // Legal move made
            }
        }
        else {
            System.out.println("Invalid choice, please try again");
            CrazyEightsTurn.validMoveMade = false;
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

}

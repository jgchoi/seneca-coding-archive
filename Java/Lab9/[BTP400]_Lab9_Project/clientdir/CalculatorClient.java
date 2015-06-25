import java.rmi.*;
import java.rmi.server.*;
import java.util.Scanner;

public class CalculatorClient
{
	public static void main(String[] args) {


		String url = "rmi://localhost:/"+args[0];
		System.out.println(url);
		try {		
			String names[] = Naming.list( "rmi://localhost:"+args[0] );
			
			Calculator c = (Calculator) Naming.lookup(names[0]);

			//Welcome
			System.out.print("Echo from the server:");
			System.out.println(c.welcome());

			while(true)
			{
				//client request
				Scanner keyboard = new Scanner( System.in );
				System.out.print( "command >> " );
				String buffer = keyboard.nextLine();   // nextInt()

				//send commend
				buffer = c.command(buffer);

				//If lastWord(Thank you!) than break
				if(buffer.equals("Thank you!"))
					break;


				//Expect OK or choice
				if(buffer.equals("OK")) // OK with more data 
				{
					System.out.print("Echo from the server: ");
					System.out.println(buffer);

					buffer = c.answer();
					System.out.println(buffer);
				}
				else // selection
				{
					System.out.print("ENTER YOUR CHOICE: ");
					System.out.println(buffer);
				}
			}
		}

		catch( Exception e ) {
			System.out.println( "Error " + e );
		}

		System.out.println( "rmi client: THE END!" );
	}
}


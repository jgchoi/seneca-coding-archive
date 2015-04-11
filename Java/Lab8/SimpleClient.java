//Libaray
import java.net.*;
import java.io.*;
import java.util.*;

public class SimpleClient {
	private Socket clientSocket;
	private DataOutputStream dosToServer;
	private DataInputStream disFromServer;
	private int portNumber;

	public SimpleClient()
	{
		this("20000");
	}
	public SimpleClient(String arg)
	{
		System.out.println( "...Client constructor" );

		//Conversion String to int
		portNumber = Integer.parseInt(arg);
	}
	public void openConnection( ) // connect to a server
	{
		try {
			clientSocket = new Socket( InetAddress.getByName( "localhost" ),portNumber );
			dosToServer = new DataOutputStream(clientSocket.getOutputStream());
			disFromServer = new DataInputStream(clientSocket.getInputStream());

		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void run( ) // process data communication with the server
	{
		//variables
		String buffer;

		try {
			//Receiving initial message
			System.out.print("Echo from the server: ");
			buffer = disFromServer.readUTF();
			System.out.println(buffer);

			while(true)
			{
				//client request
				Scanner keyboard = new Scanner( System.in );
				System.out.print( "command >> " );
				buffer = keyboard.nextLine();   // nextInt()

				//keyboard.close(); -- cause me error
				//send commend
				dosToServer.writeUTF(buffer);
				dosToServer.flush();

				//If lastWord(Thank you!) than break
				if(buffer.equals("Thank you!"))
					break;

				//receive data
				buffer = disFromServer.readUTF();

				//Expect OK or choice
				if(buffer.equals("OK")) // OK with more data 
				{
					System.out.print("Echo from the server: ");
					System.out.println(buffer);

					//Another receiving response 1
					System.out.print(disFromServer.readUTF());
					//Response 2 with double
					System.out.println(disFromServer.readDouble());
				}
				else if(buffer.equals("circle, rectangle"))// selection
				{
					System.out.print("ENTER YOUR CHOICE: ");
					System.out.println(buffer);
				}
				else //Handling error, just show error message received.
				{
					System.out.println(buffer);
				}

			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	public void close( ) // close the socket connection and all data streams
	{
		try {
			System.out.println("Closing connection...");
			dosToServer.close();
			disFromServer.close();
			clientSocket.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public static void main(String[] args) 
	{
		SimpleClient c = new SimpleClient(args[0]);
		c.openConnection();
		c.run();
		c.close();
	}
}

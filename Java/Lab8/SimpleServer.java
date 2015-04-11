//Library
import java.math.BigDecimal;
import java.net.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.io.*;
//Invalid input handling exceptions
class InvalidCommanDetected extends Exception {
	public InvalidCommanDetected(String message) {
		super(message);
	}
}


public class SimpleServer {
	//Properties
	private ServerSocket serverSocket;
	private DataOutputStream dosToClient;
	private DataInputStream disFromClient;
	private Socket socketConnection;

	//Static ending value
	static public String lastWord = "Thank you!";
	public void noProblem() throws IOException
	{
		System.out.println("###Invalid Command Detected###");
		String buffer = "### Invalid command ###\nValid commands are:\n 1) area \n 2) rectangle ##.## ##.## \n 3) circle ##,##\n 4) Thank you!\n  -##.## indicates any double value\n  -Double values must be greater than 0";

		//Send data
		dosToClient.writeUTF(buffer);
		dosToClient.flush();

	}
	//Methods
	public SimpleServer()
	{ 
		//Random port
		this("20000");
	}

	public SimpleServer (String arg)
	{
		System.out.println( "...Server constructor" );

		//Conversion String to int
		int portNumber = Integer.parseInt(arg);

		try {
			serverSocket = new ServerSocket(portNumber);
		} catch (IOException e) {
			System.out.println( "I/O error in data exchange @ SimpleServer()" );
			e.printStackTrace();
		}
	}
	public void acceptNewConnection() // listen for a new connection
	{
		System.out.println( "...Accepting new connection" );
		try {
			//start accept
			socketConnection = serverSocket.accept();

			//Connection made, assign data stream
			dosToClient = new DataOutputStream(socketConnection.getOutputStream());
			disFromClient = new DataInputStream(socketConnection.getInputStream());
			System.out.println("...New connection established");

			System.out.println( "...I/O streams connected to the socket");
		} catch (IOException e) {
			System.out.println( "I/O error in data exchange @ Close() @ acceptNewConnection()" );
			e.printStackTrace();
		}

	}
	public void run() // process data communication with the client
	{
		//variables
		double value1;
		double value2 = 0; // In case for circle
		double answer;
		String buffer;
		String selection;

		try 
		{
			//How may I help you? with datetime to server and client
			buffer = "How may I help you? (" +  LocalDateTime.now().format(DateTimeFormatter.ofPattern("M/dd/yyyy hh:mm a")) + ")";
			//To server
			System.out.println(buffer);
			//To client
			dosToClient.writeUTF(buffer);
			dosToClient.flush();

			while(true)
			{
				try // For invalid input catch
				{
					//Read client request
					buffer = disFromClient.readUTF();

					//display client request
					System.out.println("client's request: "+buffer);

					//End connection if lastword is detected;
					if(buffer.equals(SimpleServer.lastWord))
					{
						System.out.println("THANK YOU RECEIVED!");
						break;
					}

					//Handling "area" commend
					if(buffer.equals("area"))
					{
						//Send the choices
						buffer = "circle, rectangle";

						//Send data
						dosToClient.writeUTF(buffer);
						dosToClient.flush();
					}
					else //not equal, not area, try split
					{
						if(buffer.split(" ")[0].equals("circle") || buffer.split(" ")[0].equals("rectangle"))
						{
							//Parse values
							selection = buffer.split(" ")[0];
							value1 = Double.parseDouble (buffer.split(" ")[1]);

							//valud validation
							if(value1 <=0 )
								throw new InvalidCommanDetected("invalid");
							
							//for rectangle
							if(buffer.split(" ").length == 3)
							{
								value2 = Double.parseDouble (buffer.split(" ")[2]);
								
								//valud validation
								if(value2 <=0)
									throw new InvalidCommanDetected("invalid");
							}

							//if any of values are equals to 0 or negative number invalid
							
							//calculation
							if(selection.equals("circle"))
								answer = Math.PI * value1 * value1;
							else
								answer = value1 * value2;
												
							//Send OK!
							dosToClient.writeUTF("OK");
							dosToClient.flush();

							buffer = "area of the  "+ selection + ": ";

							//Send data
							dosToClient.writeUTF(buffer);
							dosToClient.flush();

							//Send result
							dosToClient.writeDouble(new BigDecimal(answer ).setScale(2, BigDecimal.ROUND_HALF_UP).doubleValue());
						}
						else // If un splitable means invalid command
						{
							throw new InvalidCommanDetected("Invalid");
						}
					}


				}
				catch (InvalidCommanDetected e) // Handling invalid command and continue receiving command
				{
					noProblem();
				}
				catch (ArrayIndexOutOfBoundsException e) // It happens if user input commands like area (empty) or rectangle (empty)
				{
					noProblem();
				}
				catch (NumberFormatException e) //trying to parse char to double..
				{
					noProblem();
				}
			}
		}
		catch (IOException e) 
		{
			System.out.println( "I/O error in data exchange @ run()" );
			e.printStackTrace();
		}

	}
	public void close() // close the socket connection and all data streams
	{
		try {
			dosToClient.close();
			disFromClient.close();
			socketConnection.close();
		} catch (IOException e) {
			System.out.println( "I/O error in data exchange @ Close()" );
			e.printStackTrace();
		}

	}


	//Main Function
	public static void main(String[] args) 
	{
		SimpleServer s = new SimpleServer(args[0]);
		while(true) // No exit state! (Peter's favorite program)
		{
			s.acceptNewConnection();
			s.run();
			s.close();
		}
	} // end main
}

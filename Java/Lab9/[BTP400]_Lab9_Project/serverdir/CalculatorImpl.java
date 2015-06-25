import java.io.IOException;
import java.math.BigDecimal;
import java.rmi.*;
import java.rmi.server.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

class InvalidCommanDetected extends Exception {
	public InvalidCommanDetected(String message) {
		super(message);
	}
}

public class CalculatorImpl extends UnicastRemoteObject
implements Calculator {

	static private String calType = "circle, rectangle";
	static private String OK = "OK";
	static public String lastWord = "Thank you!";

	private String answer;
	private double value1;
	private double value2;
	private String selection;


	public CalculatorImpl()	throws Exception
	{
		answer = null;
		selection = null;
		value1 = 0;
		value2 = 0;
	}


	private String noProblem()
	{
		System.out.println("###Invalid Command Detected###");
		String buffer = "### Invalid command ###\nValid commands are:\n 1) area \n 2) rectangle ##.## ##.## \n 3) circle ##,##\n 4) Thank you!\n  -##.## indicates any double value\n  -Double values must be greater than 0";

		return buffer;
	}

	public String welcome() throws RemoteException
	{
		return "How may I help you? (" +  LocalDateTime.now().format(DateTimeFormatter.ofPattern("M/dd/yyyy hh:mm a")) + ")";
	}

	public String command(String buffer) throws RemoteException
	{
		try // For invalid input catch
		{
			//display client request
			System.out.println("client's request: "+buffer);

			//End connection if lastword is detected;
			if(buffer.equals(lastWord))
			{
				System.out.println("THANK YOU RECEIVED!");
				return lastWord;
			}


			//Handling "area" commend
			if(buffer.equals("area"))
			{

				return calType;
			}
			else //not equal, not area, try split
			{
				if(buffer.split(" ")[0].equals("circle") || buffer.split(" ")[0].equals("rectangle"))
				{
					//Value initialize
					value1=0;
					value2=0;
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
					else if(buffer.split(" ")[0].equals("rectangle"))
					{
						if(value2 <=0)
							throw new InvalidCommanDetected("invalid");
					}
						

					//if any of values are equals to 0 or negative number invalid
					
					buffer = "area of the  "+ selection + ": ";
					double temp=0;

					//calculation
					if(selection.equals("circle"))
						temp += Math.PI * value1 * value1;
					else
						temp += value1 * value2;

					answer = buffer + (new BigDecimal(temp).setScale(2, BigDecimal.ROUND_HALF_UP).doubleValue());
					
					return OK;
				}
				else // If un splitable means invalid command
				{
					throw new InvalidCommanDetected("Invalid");
				}
			}


		}
		catch (InvalidCommanDetected e) // Handling invalid command and continue receiving command
		{
			buffer= noProblem();			
		}
		catch (ArrayIndexOutOfBoundsException e) // It happens if user input commands like area (empty) or rectangle (empty)
		{
			buffer= noProblem();
		}
		catch (NumberFormatException e) //trying to parse char to double..
		{
			buffer= noProblem();
		}
		
		return buffer;
	}

	public String answer() throws RemoteException { return answer; }


}
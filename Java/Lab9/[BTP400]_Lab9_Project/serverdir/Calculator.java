import java.rmi.*;

public interface Calculator extends Remote
{
	public String welcome() throws RemoteException;
	public String command(String buffer) throws RemoteException;
	public String answer() throws RemoteException;
}
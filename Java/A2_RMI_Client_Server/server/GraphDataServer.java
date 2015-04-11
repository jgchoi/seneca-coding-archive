
import java.rmi.*;
//import java.rmi.server.*;


public class GraphDataServer {
	
	public static void main(String[] args) {
		
		try 
		{
			System.out.println( "Starting a server..." );

			DataResourceImpl d = new DataResourceImpl();

			System.out.println( "Binding remote objects to rmi registry" );

			Naming.rebind( "rmi://localhost:"+args[0]+"/dataResource", d);   // <name, reference>

			System.out.println( "These remote objects are waiting for clients..." );
		}
		catch( Exception e ) 
		{
			System.out.println( "Error: " + e );
		}
		
		System.out.println( "... the main thread is put into a wait state!!!" );
	}
}

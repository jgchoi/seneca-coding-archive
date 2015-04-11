
import java.rmi.*;
import java.rmi.server.*;
import java.sql.*;

public class DataResourceImpl extends UnicastRemoteObject implements
DataResource {
	// #########################################################################
	// Variables
	public static final String[] type = { "Snow Fall in cm", "Precipitation in mm", "Average wet day in a year" };
	public static final String[] year = {"2013", "2012"};
	static final String drivername = "com.mysql.jdbc.Driver"; // JDBC driver (a// class name)
	static final String sysName = "zenit.senecac.on.ca"; // database server
	static final String dbName = "btp400_151a16"; // database name
	static final String userid = "btp400_151a16";
	static final String password = "gnYE4396";

	private Connection conn; // database connnection

	// #########################################################################
	// Methods
	protected DataResourceImpl() throws RemoteException 
	{
		super();

		//JDBC driver test
		try 
		{
			Class.forName( drivername );  // load the Java class(i.e. JDBC driver) at run time
		}
		catch( ClassNotFoundException ec) 
		{ 
			ec.printStackTrace();
			System.out.println( "MySQL JDBC driver not found!" );
			System.exit(1);
		}
		System.out.println("JDBC class found");

		if(!DBConnection( sysName, dbName ))/* test the connection */		
		{
			System.out.println( "Failed to connect to DB!" );
			System.exit(1);
		}
		testQueryAll();
	}



	public boolean DBConnection(String sys, String databaseName) {

		System.out.println( "Connecting to the MySQL server: " + sys + "...");

		try
		{
			/* Step 2: connect to the database
		     		   datasbase URL:
			   		   jdbc:<subprotocol>:<system url>/<collection name> */

			conn = DriverManager.getConnection( "jdbc:mysql:" +
					"//" + sys +
					"/"  + databaseName,
					userid, password
					);
		}

		catch ( SQLException exc )  /* SQLException */
		{
			System.out.println( "connection failed with: " +
					exc.getMessage() );
			return false;
		}

		System.out.println( "database connection-OK" );

		return true;
	}

	public boolean testQueryAll() {

		/*  Step 3: Prepare the SQL statement object
	        Step 4: Execute the SQL statement object */

		// drop the table if it already exists!

		System.out.println( "dropping a table if it exists..." );

		try {
			Statement dropTable = conn.createStatement();
			dropTable.executeUpdate( "DROP TABLE " + "Weather" ); 	      // table name: Test
			dropTable.close();
		}
		catch( SQLException e ) { }

		System.out.println( "creating a database table..." );

		try {
			// SQL statements: create a table and insert data

			Statement stat = conn.createStatement();

			stat.executeUpdate( "CREATE TABLE Weather (CITY CHAR(20), TYPE CHAR(50), AMOUNT INT, YEAR INT )" );

			// What if there's SQL syntax error? e.g. missing ')'
			//Dataset for Year 2013
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'St. Johns', 'Snow Fall in cm',322,2013 )" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Charlottetown', 'Snow Fall in cm', 311,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Halifax', 'Snow Fall in cm', 230,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Fredericton', 'Snow Fall in cm', 231,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Qubec', 'Snow Fall in cm', 276,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Montrel', 'Snow Fall in cm', 315,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Ottawa', 'Snow Fall in cm', 217,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Toronto', 'Snow Fall in cm', 235,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Winnipeg', 'Snow Fall in cm', 115,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Regina', 'Snow Fall in cm', 110,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Edmonton', 'Snow Fall in cm', 105,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Calgary', 'Snow Fall in cm', 121,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Vancouver', 'Snow Fall in cm', 126,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Victoria', 'Snow Fall in cm', 47,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Whitehorse', 'Snow Fall in cm',43,2013 )" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Yellowknife', 'Snow Fall in cm',145,2013 )" );

			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'St. Johns', 'Precipitation in mm', 1513,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Charlottetown', 'Precipitation in mm', 1173,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Halifax', 'Precipitation in mm', 1452,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Fredericton', 'Precipitation in mm', 1143,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Qubec', 'Precipitation in mm', 1230,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Montrel', 'Precipitation in mm', 978,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Ottawa', 'Precipitation in mm', 743,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Toronto', 'Precipitation in mm', 792,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Winnipeg', 'Precipitation in mm', 513,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Regina', 'Precipitation in mm', 388,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Edmonton', 'Precipitation in mm', 482,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Calgary', 'Precipitation in mm',412 ,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Vancouver', 'Precipitation in mm', 1199,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Victoria', 'Precipitation in mm', 883,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Whitehorse', 'Precipitation in mm', 267,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Yellowknife', 'Precipitation in mm', 280,2013)" );

			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'St. Johns', 'Average wet day in a year', 215,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Charlottetown', 'Average wet day in a year', 184,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Halifax', 'Average wet day in a year', 156,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Fredericton', 'Average wet day in a year', 181,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Qubec', 'Average wet day in a year', 163,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Montrel', 'Average wet day in a year', 162,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Ottawa', 'Average wet day in a year', 145,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Toronto', 'Average wet day in a year', 123,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Winnipeg', 'Average wet day in a year', 114,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Regina', 'Average wet day in a year', 124,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Edmonton', 'Average wet day in a year', 113,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Calgary', 'Average wet day in a year', 166,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Vancouver', 'Average wet day in a year', 154,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Victoria', 'Average wet day in a year', 122,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Whitehorse', 'Average wet day in a year', 154,2013)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Yellowknife', 'Average wet day in a year', 122,2013)" );

			//Dataset for year 2012

			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'St. Johns', 'Snow Fall in cm',222,2012 )" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Charlottetown', 'Snow Fall in cm', 151,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Halifax', 'Snow Fall in cm', 320,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Fredericton', 'Snow Fall in cm', 331,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Qubec', 'Snow Fall in cm', 256,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Montrel', 'Snow Fall in cm', 315,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Ottawa', 'Snow Fall in cm', 267,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Toronto', 'Snow Fall in cm', 195,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Winnipeg', 'Snow Fall in cm', 95,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Regina', 'Snow Fall in cm', 180,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Edmonton', 'Snow Fall in cm', 125,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Calgary', 'Snow Fall in cm', 151,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Vancouver', 'Snow Fall in cm', 26,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Victoria', 'Snow Fall in cm', 147,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Whitehorse', 'Snow Fall in cm',63,2012 )" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR) VALUES( 'Yellowknife', 'Snow Fall in cm',175,2012 )" );

			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'St. Johns', 'Precipitation in mm', 1213,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Charlottetown', 'Precipitation in mm', 1773,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Halifax', 'Precipitation in mm', 1452,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Fredericton', 'Precipitation in mm', 1143,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Qubec', 'Precipitation in mm', 1320,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Montrel', 'Precipitation in mm', 1178,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Ottawa', 'Precipitation in mm', 843,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Toronto', 'Precipitation in mm', 292,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Winnipeg', 'Precipitation in mm', 813,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Regina', 'Precipitation in mm', 488,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Edmonton', 'Precipitation in mm', 282,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Calgary', 'Precipitation in mm',812 ,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Vancouver', 'Precipitation in mm', 1309,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Victoria', 'Precipitation in mm', 1883,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Whitehorse', 'Precipitation in mm', 1267,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Yellowknife', 'Precipitation in mm', 280,2012)" );

			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'St. Johns', 'Average wet day in a year', 225,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Charlottetown', 'Average wet day in a year', 124,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Halifax', 'Average wet day in a year', 136,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Fredericton', 'Average wet day in a year', 161,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Qubec', 'Average wet day in a year', 113,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Montrel', 'Average wet day in a year', 122,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Ottawa', 'Average wet day in a year', 175,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Toronto', 'Average wet day in a year', 173,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Winnipeg', 'Average wet day in a year', 134,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Regina', 'Average wet day in a year', 164,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Edmonton', 'Average wet day in a year', 133,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Calgary', 'Average wet day in a year', 162,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Vancouver', 'Average wet day in a year', 174,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Victoria', 'Average wet day in a year', 123,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Whitehorse', 'Average wet day in a year', 174,2012)" );
			stat.executeUpdate( "INSERT INTO Weather ( CITY, TYPE, AMOUNT, YEAR)VALUES( 'Yellowknife', 'Average wet day in a year', 132,2012)" );

			stat.close(); // close the Statement object
		}
		catch ( SQLException exc )
		{
			System.out.println( " query failed with: " + exc.getMessage() );
			return false;
		}

		System.out.println( "DONE" );

		return true;

	} 

	//#########################################################################
	//RMI Method
	public String[][] getTableData(String selection, int year) throws RemoteException {
		// Choice
		System.out.println("Client Request Begin...");
	

		System.out.print("Requested Data Type: ");
		System.out.println(selection);

		System.out.print("Requested Year Range: ");
		System.out.println(year);
		
		// Return
		String[][] result = new String[16][3];
		try {
			Statement stat = conn.createStatement();
			// SQL statement: database query
			int i = 0;
			ResultSet rs = stat.executeQuery( "SELECT * FROM Weather WHERE TYPE = '"+selection+"' AND YEAR = "+year+";" );
			while ( rs.next() ) {
				result[i][0] = rs.getString(3);
				result[i][1] = rs.getString(2);
				result[i][2] = rs.getString(1);
				i++;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return result;
	}
	public String[] getDataType() throws RemoteException
	{
		return type;
	}
	public String[] getYearRange() throws RemoteException
	{
		return year;
	}

}
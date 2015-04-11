
import java.rmi.*;

//RMI Class
public interface DataResource extends Remote
{
	//----(getTableData)-------------------------------------------------------
	//takes type of the data and range in year, return string array of array
	public String[][] getTableData(String selection, int year) throws RemoteException;
	
	
	//----(getDataType)-------------------------------------------------------
	//Returns available data types
	public String[] getDataType() throws RemoteException;
	
	//----(getYearRange)-------------------------------------------------------
	//returns available data range with given data type	
	public String[] getYearRange() throws RemoteException;
}
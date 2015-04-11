
import java.rmi.*;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import org.jfree.chart.ChartFrame;
import org.jfree.chart.JFreeChart;

public class GraphDataClient
{	
	public static void main(String[] args) {
		try 
		{		
			String names[] = Naming.list( "rmi://localhost:"+args[0] );

			DataResource d = (DataResource) Naming.lookup(names[0]);

			while(true)
			{
				//Variables
				String [][] s = null;
				int year = 0;
				
				//Data type selection
				JFrame frame = new JFrame("Data Resource Selection");
				String userSelection = (String) JOptionPane.showInputDialog(frame,
						"Select graph type", "Graph Type", JOptionPane.QUESTION_MESSAGE, null, d.getDataType(), d.getDataType()[0]);
				
				//Year Range selection
				year = Integer.parseInt( (String) JOptionPane.showInputDialog(frame,
						"Select Year", "Graph Year", JOptionPane.QUESTION_MESSAGE, null, d.getYearRange(), d.getYearRange()[0]));
				
				//Get data with choosen type & range
				s = d.getTableData(userSelection, year);
				
				if(s != null && year != 0)
				{
					PolylineBarChart demo = new PolylineBarChart();
					JFreeChart chart = demo.getChart(s, year);
					ChartFrame frame1=new ChartFrame("Bar Chart",chart);
					frame1.setSize(800,400); 
					frame1.setVisible(true);
				}
				else
				{
					System.out.println("User select cancel. Terminating the program...");
					break;
				}
			}
		}

		catch( Exception e ) {
			System.out.println( "Error " + e );
		}

		System.out.println( "rmi client: THE END!" );
	}
}


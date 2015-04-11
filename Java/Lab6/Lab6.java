import java.util.ArrayList;
import java.util.Random;


public class Lab6 {
	
	//Given Array
	private static String [][] data = {
			{ "java", "I love java", "c++", "python" },
			{ "c programs", "cookies",  "java developers", "oops"},
			{ "john", "doe", "mary", "mark holmes"},
			{ "hello java java", "byebye", "java again?", "java what?"},
			{ "toronto", "montreal", "quebec city", "calgary"}
		};
	
	//Given search keyword
	public static String keyword = "java";

	//Main Function
	public static void main(String[] args) 
	{
		
		System.out.println("Runnable Method\n");
		SearchRunnable [] runnables = new SearchRunnable[data.length];
		Thread [] threads = new Thread[data.length];
		
		//Start threads
		for(int i = 0 ; i < data.length ; i++)
		{
			runnables[i] = new SearchRunnable(i, data[i]);
			threads[i] = new Thread(runnables[i]);
			threads[i].start();
		}
		
		//Start collecting		
		for(int i = 0 ; i < data.length ; i++)
		{
			try {
				threads[i].join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			System.out.print("Row "+ (runnables[i].getRowId()+1) + ": ");
			//Check result size
			if(runnables[i].getResult().size() == 0)
			{
				System.out.println("***");
			}
			else
			{
			
			for(int k = 0 ; k < runnables[i].getResult().size() ;k++)
			{
				System.out.print(runnables[i].getResult().get(k));
				if(k+1 < runnables[i].getResult().size())
					System.out.print(", ");
			}
			System.out.println();
			}
		}
		
		
		//Using Thread
		System.out.println("\nThread extends Method\n");
		ArrayList<SearchThread> threads1 = new ArrayList<SearchThread>();
		
		int i = 0;
		for(String [] row : data)
		{
			threads1.add(new SearchThread(i, row));
			threads1.get(i++).start();
		}
	

			for(SearchThread thread : threads1) 
			{
				try {
					thread.join();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
				System.out.print("Row "+ (thread.getRowId()+1) + ": ");
				//Check result size
				if(thread.getResult().size() == 0)
				{
					System.out.println("***");
				}
				else
				{
				
				for(int k = 0 ; k < thread.getResult().size();k++)
				{
					System.out.print(thread.getResult().get(k));
					if(k+1 < thread.getResult().size())
						System.out.print(", ");
					
					
				}
				System.out.println();
				}
			}
	}
}

//Thread type 1 using 'extends Thread'

class SearchThread extends Thread 
{
	private ArrayList<String> result;
	private int rowId;
	private Random randomTime = new Random();
	private String [] items;

	public SearchThread()
	{
		this(-1, null);
	}

	public SearchThread(int _rowId, String [] _items)
	{
		rowId = _rowId;
		result = new ArrayList<String>();
		items = _items;
	}

	public void run()
	{
		
		for(String item : items)
		{
			//System.out.println("Working..."+item);
			if(item.indexOf(Lab6.keyword)>=0)
			{
				result.add(item);
			}

			//Random sleep!
			try {sleep(((randomTime.nextInt(20)+1)*100)); }
			catch (InterruptedException e) {}
		}
	}

	public int getRowId()
	{
		return rowId;
	}

	public ArrayList<String> getResult()
	{
		return result;
	}
}


//Thread type 2 using Runnable
class SearchRunnable implements Runnable
{
	private ArrayList<String> result;
	private int rowId;
	private Random randomTime = new Random();
	private String [] items;


	public SearchRunnable(int _rowId,String [] _items)
	{
		rowId = _rowId;
		result = new ArrayList<String>();
		items = _items;

	}

	public void run()
	{
		for(String item : items)
		{
			if(item.indexOf(Lab6.keyword)>=0)
			{
				result.add(item);
			}

			//Random sleep!
			try {Thread.sleep(((randomTime.nextInt(20)+1)*100)); }
			catch (InterruptedException e) {}
		}
	}
	
	public int getRowId()
	{
		return rowId;
	}

	public ArrayList<String> getResult()
	{
		return result;
	}
}
import java.util.ArrayList;

public class Bank
{
	//Change into arraylist
	//private Account accounts[];
	private ArrayList<Account> accounts;
	private String name;
	
	//Removed due to use of arraylist
	//private int max;
	
	//Default constructor
	public Bank(String _name){ name = _name; accounts = new ArrayList<Account>();}
	public Bank(){ this("Seneca@york"); }
	
	//Equals
	public boolean equals(Object z)
    {
        boolean result = false;
        Bank z2 = (Bank) z;
		
        if( z instanceof Bank )
        {
            if (z2.accounts.size() == accounts.size() && z2.name.equalsIgnoreCase(name))
			{
				//set result true
				result = true;
				
				//test accounts
				for(int i = 0; i < accounts.size(); i++)
				{	
					if(z2.accounts.get(i) == null || accounts.get(i) == null)
					 result = true;
					else
					if(!z2.accounts.get(i).equals(accounts.get(i)))
						result = false;
				}
			}  
        }    
		
        return result;
    }
	
	public String toString()
	{
		String s;
		
		s =		"******************************\n"+
				"*      Bank Information      *\n"+
				"******************************\n"+
				"-Name: "+name+"\n"+
				"-Opened Account: "+ (accounts.size()) +"\n";
		
		//If there's an account open
		if(accounts.size() != 0)
		{
			s +=	"******************************\n"+
					"*        Accounts Info       *\n"+
					"******************************\n";
					
			for( int i=0 ; i<accounts.size(); i++)
			{
				s += "-"+(i+1)+": Acc#="+accounts.get(i).getAccountNumber()+" Bal=$" + accounts.get(i).getBalance()+"\n";
				
			}
		}
 		s+= "*****************************\n";
		return s;
	}
	
	public boolean addAccount(Account newAccount)
	{
		boolean result = true;
		
		//test null
		if(newAccount != null)
		{
			for( int i=0 ; i<accounts.size() ; i++)
			{	
				//test duplicate
				if(accounts.get(i) != null && accounts.get(i).equals(newAccount))
				{
					//account is duplicate
					result = false;
				}
			}
		}
		else
		{
			//is null
			result = false;
		}
		
		if(result==true)
		{
			accounts.add(newAccount);
		}
		
		return result;
	}
	
	public Account removeAccount(String _accountNumber)
	{
		Account result = null;
		
		for( int i=0 ; i < accounts.size() ; i++ )
		{
			if(accounts.get(i).getAccountNumber() == _accountNumber)
			{
				//remove searched item by replacing from the last one
				result = accounts.get(i);
				accounts.remove(i);
			}
		}
		
		return result;
	}
	
	
    public Account [] getAllAccounts()
	{
		//Check if 0 account
		if(accounts.size() == 0)
		{
			return null;
		}
		else
		{
			Account [] result;
			result = new Account [accounts.size()];
			return accounts.toArray(result);
		}
		
	}

	
	public Account [] search(double _balance)
	{
		Account [] temp = new Account[accounts.size()];
		Account [] result;
		int size=0;
		
		//Check balance, copy to temp array
		for( int i=0 ; i<accounts.size() ; i++)
		{			
			if(accounts.get(i) != null && accounts.get(i).getBalance() == _balance)
			{
				temp[size++] = accounts.get(i);
			}
		}
		
		//Copy to result array
		
		//Creating new array
		if(size>0)
		{
			result = new Account[size];
				for( int i=0; i<size ; i++)
				{
					result[i] = temp[i];
				}
		}
		else
		{
			result = null;
		}		
		return result;
	}
}
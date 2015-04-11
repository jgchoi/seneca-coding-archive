public class Bank
{
	private Account accounts[];
	private String name;
	private int max;
	
	//Default constructor
	public Bank(String _name, int _max){ name = _name; max = _max; accounts = new Account[max];}
	public Bank(){ name = "Seneca@York"; max = 0; accounts=null;}
	
	//Equals
	public boolean equals(Object z)
    {
        boolean result = false;
        Bank z2 = (Bank) z;
		
        if( z instanceof Bank )
        {
            if (z2.max == max && z2.name.equalsIgnoreCase(name))
			{
				//set result true
				result = true;
				
				//test accounts
				for(int i = 0; i <max; i++)
				{	
					if(z2.accounts[i] == null || accounts[i] == null)
					 result = true;
					else
					if(!z2.accounts[i].equals(accounts[i]))
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
				"-Max Account: "+accounts.length+"\n"+
				"-Opened Account: "+ (accounts.length - max) +"\n";
		
		//If there's an account open
		if(accounts[0] != null)
		{
			s +=	"******************************\n"+
					"*        Accounts Info       *\n"+
					"******************************\n";
					
			for( int i=0 ; i<accounts.length - max ; i++)
			{
				s += "-"+(i+1)+": Acc#="+accounts[i].getAccountNumber()+" Bal=$" + accounts[i].getBalance()+"\n";
				
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
			for( int i=0 ; i<accounts.length ; i++)
			{	
				//test duplicate
				if(accounts[i] != null && accounts[i].equals(newAccount))
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
			accounts[ accounts.length - max-- ] = newAccount;
		}
		
		return result;
	}
	
	public Account removeAccount(String _accountNumber)
	{
		Account result = null;
		
		for( int i=0 ; i < accounts.length-max ; i++ )
		{
			if(accounts[i].getAccountNumber() == _accountNumber)
			{
				//remove searched item by replacing from the last one
				result = accounts[i];
				accounts[i] = accounts[accounts.length - max -1];
				accounts[accounts.length - max++ -1] = null;
			}
		}
		
		return result;
	}
	
	public Account [] search(double _balance)
	{
		Account [] temp = new Account[accounts.length];
		Account [] result;
		int size=0;
		
		//Check balance, copy to temp array
		for( int i=0 ; i<accounts.length ; i++)
		{			
			if(accounts[i] != null && accounts[i].getBalance() == _balance)
			{
				temp[size++] = accounts[i];
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
public class Account
{
	//Data Fields
	private String name;
	private String accountNumber;
	private double balance;
	
	//Constructor
	public Account(String _name, String _accountNumber, double _balance)
	{
		name = _name;
		accountNumber = _accountNumber;
		balance = _balance;
	}
	
	public Account()
	{
		this(null, null, 0.0); 
	}
	
	//Methods
	public String toString()
	{
		String s;
		s =		"**************************\n" +
				"*   ACCOUNT INFORMATION  *\n" +
				"**************************\n" +
				"Name : " + name + "\n" +
				"Account Number : "  + accountNumber + "\n" +
				"Balance : " + balance + "\n";
		return s;
	}
	
    
    public boolean equals( Object z)
    {
        boolean result = false;
        Account z2 = (Account) z;
        if( z instanceof Account)
        {
            if( z2.name.equals(name) &&
                z2.accountNumber.equals(accountNumber) &&
                z2.balance==balance )
                
                result = true;
               
        }
        
        return result;
    }
    
	//getter & setter
	public String getFullName(){ return name;}	
	public String getAccountNumber(){ return accountNumber;}
	public double getBalance(){ return balance;}
		
	public void setName(String _name){ name = _name; }
	public void setAccountNumber(String _accountNumber){ accountNumber = _accountNumber; }
	public void setBalance(double _balance){ balance = _balance; }	
	
}


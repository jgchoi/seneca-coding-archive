public class Account
{
	//Data Fields
	private String fullName;
	private String accountNumber;
	private double balance;
	
	//Constructor
	public Account(String _fullName, String _accountNumber, double _balance)
	{
		fullName = _fullName;
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
				"-Name : " + fullName + "\n" +
				"-Account Number : "  + accountNumber + "\n" +
				"-Balance : " + balance + "\n"+
				"**************************\n";
		return s;
	}
	
    
    public boolean equals( Object z)
    {
        boolean result = false;
        Account z2 = (Account) z;
        if( z instanceof Account)
        {
            if( z2.fullName.equals(fullName) &&
                z2.accountNumber.equals(accountNumber) &&
                z2.balance==balance )
                
                result = true;
               
        }
        
        return result;
    }
    
	//get
	public String getFullName(){ return fullName;}	
	public String getAccountNumber(){ return accountNumber;}
	public double getBalance(){ return balance;}
	
	//set
	public void setName(String _fullName){fullName= _fullName; }
	public void setAccountNumber(String _accountNumber){ accountNumber = _accountNumber; }
	public void setBalance(double _balance){ balance = _balance;}	
	
	//Lab 2
	public String getFirstName(){return fullName.split(", ")[1];}
	public String getLastName(){return fullName.split(", ")[0];}
	
}


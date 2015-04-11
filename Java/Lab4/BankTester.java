public class BankTester
{
	public static void main(String[] args)
	{
		//Testing variables
		Bank empty, TD, td, diff,lab3;
		
		//construct
		empty = new Bank();
		TD = new Bank("TD");//same as td
		td = new Bank("td");
		diff = new Bank("Scotia");
		lab3 = new Bank("Lab3");
		System.out.println("===============================");
		System.out.println("TEST0: Lab3 - getAllAccounts() test");
		//Account variable
		Account [] accounts = new Account [5];
		
		accounts[0] = new Account("Choi, Jung", "100001", 500.00); //same balance as [3]
		accounts[1] = new Account("Last2, First2", "100002", 550.00);
		accounts[2] = new Account("Last3, First3", "100003", 560.00);
		accounts[3] = new Account("Last4, First4", "100004", 500.00);
		accounts[4] = new Account("Last5, First5", "100005", 580.00);
		
		Account [] getAllResult = lab3.getAllAccounts();
		System.out.println("Items received from empty lab3 object (Expect Null)");
		System.out.println(getAllResult);
		
		//add accounts
		for(int i=0;i<5;i++)
		{
			boolean result;
			result = lab3.addAccount(accounts[i]);
			System.out.println("-Result of lab3.addAccount(accounts["+i+"]) = "+result);
		}
		getAllResult = lab3.getAllAccounts();
		for (Account account : getAllResult) {
		System.out.println("Items received from geAllAccount()");
		System.out.println(account);
}
		
		
		//Test 1 a) Display information about a bank that does not have any accounts opened yet.
		System.out.println("===============================");
		System.out.println("TEST1: Bank w/o account");
		System.out.println(TD);
		
		System.out.println("===============================");
		System.out.println("TEST2: Compare empty 'TD' and 'td'");
		System.out.println("TD.equals(td)="+TD.equals(td));
		System.out.println("TD.equals(diff)="+TD.equals(diff));

		System.out.println("===============================");
		System.out.println("Test3: first name and last name");
		
	
		

		
		System.out.println(accounts[0]);
		System.out.println("-Last Name is (expect: Choi): "+accounts[0].getLastName()+"");
		System.out.println("-First Name is (expect: Jung): "+accounts[0].getFirstName()+"");
		
		System.out.println("===============================");
		System.out.println("Test4: Add Account to 'TD'");
		System.out.println("Adding accounts to TD...");
		for(int i=0;i<5;i++)
			{
				boolean result;
				result = TD.addAccount(accounts[i]);
				System.out.println("-Result of TD.addAccount(accounts["+i+"]) = "+result);
			}
		
		System.out.println("View TD (Expect: 5 accounts)");
		System.out.println(TD);
		
		System.out.println("===============================");
		System.out.println("Test5: Add Duplicate accounts to 'TD'...");
		for(int i=0;i<5;i++)
			{
				boolean result;
				result = TD.addAccount(accounts[i]);				
				System.out.println("-Result of TD.addAccount(accounts["+i+"]) = "+result);
			}
		
		System.out.println("View TD (Expect: 5 accounts as same as previous");
		System.out.println(TD);
		
		System.out.println("===============================");
		System.out.println("Test6: Compare filled 'TD' and 'td'");
		System.out.println("Adding same accounts to 'td'...");
		for(int i=0;i<5;i++)
			{
				boolean result;
				result = td.addAccount(accounts[i]);
				System.out.println("-Result of td.addAccount(accounts["+i+"]) = "+result);
			}
		System.out.println("View td (Expect: 5 same accounts)");
		System.out.println(td);
		
		System.out.println("Compare TD and td");
		System.out.println("-TD.equals(td)="+TD.equals(td)+"");
		
		System.out.println("===============================");
		System.out.println("Test7: Compare filled 'TD' and 'diff'");
			for(int i=0;i<4;i++)
			{
				boolean result;
				result = diff.addAccount(accounts[i]);
				System.out.println("-Result of diff.addAccount(accounts["+i+"]) = "+result);
			}
			
		System.out.println("View diff (expect: 4 accounts)");
		System.out.println(diff);
		
		System.out.println("Compare TD and diff ");
		System.out.println("-TD.equals(diff)="+TD.equals(diff)+"");
		
		System.out.println("===============================");
		System.out.println("Test7: Remove account");
		Account result;
		result = TD.removeAccount("100006");
		System.out.println("-Removing 100006 (Expect null) result : "+result+"");
		result = TD.removeAccount("100001");
		System.out.println("-Removing 100001 (first)(Expect Account) result : \n"+result+"");
		
		System.out.println("View TD (expect: 4 accounts)");
		System.out.println(TD);
		
		result = TD.removeAccount("100005");
		System.out.println("-Removing 100005 (last)(Expect Account) result : \n"+result+"");
		
		System.out.println("View TD (expect: 3 accounts)");
		System.out.println(TD);
		
		result = TD.removeAccount("100003");
		System.out.println("-Removing 100003 (middle)(Expect Account) result : \n"+result+"");
		
		System.out.println("View TD (expect: 2 accounts)");
		System.out.println(TD);
		
		System.out.println("===============================");
		System.out.println("Test8: Search account");
		
		Account [] searchReasult;
		
		//test 8.1 300 
		searchReasult = td.search(300);
		System.out.println("Search for 300 (Expect null) result : \n Result Found = "+searchReasult+"");

		
		//test 8.2 -300
		searchReasult = td.search(-300);
		System.out.println("Search for -300 (Expect null) result : \n Result Found = "+searchReasult+"");

		
		//test 8.3 500 (2 result expected)
		searchReasult = td.search(500);
		System.out.println("Search for 300 (Expect 2) result : \n Result Found = "+searchReasult.length+"");
		for(int i=0;i<searchReasult.length;i++)
			System.out.println(searchReasult[i]);
		
		//test 8.4 550 (1 result expected)
		searchReasult = td.search(550);
		System.out.println("Search for 300 (Expect 1) result : \n Result Found = "+searchReasult.length+"");
		for(int i=0;i<searchReasult.length;i++)
			System.out.println(searchReasult[i]);
		
		//END OF TEST		
		System.out.println("*** END OF TEST ***");		
	}
}
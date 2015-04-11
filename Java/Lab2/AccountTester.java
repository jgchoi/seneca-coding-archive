
class AccountTester
{
	public static void main(String[] args){
		Account a,b,c,d;
		
		a = new Account();
		b = new Account("Eddy Choi", "455", 56004333);
		c = new Account("Roomi Kim", "233", 2033203);
        d = new Account("Roomi Kim", "233", 2033203);
		
        System.out.println("\nTEST 1 : Empty Object\n");

		System.out.println(a+"\n");
		
		System.out.println("\nTEST 2 : Setting New Name\n");
		a.setName("New Name");
		System.out.println(a+"\n");
        
        System.out.println("\nTEST 3 : Object with some data\n");
		System.out.println(b+"\n");
		
		System.out.println("\nTEST 4 : Equals Test Memory Address\n");
		
		System.out.println("Value of a == b : ");
		System.out.println( a==b );
		System.out.println("\n");
		System.out.println("\nTEST 5 : Equals Test Content\n");
		
		System.out.println("Value of c.equals(d) : ");
		System.out.println( c.equals(d) );
		System.out.println("\n");
		
		System.out.println("\n** Contents of object c and d\n");
		System.out.println(c+"\n");
		System.out.println(d+"\n");
		
	}
}
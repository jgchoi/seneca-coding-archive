/*
 * ##################################################################
 * BTP400 - Assignment 1
 * Due: Feb. 15, 15
 * Group Member : Jung Geon Choi
 * Entire Code for JUnit testing is written solely by Jung Geon Choi
 * ##################################################################
 */

package testing.btp400.w2015;

import ontario.business.Company;
import ontario.people.Employee;
import ontario.people.Manager;
import ontario.people.Programmer;
import junit.framework.TestCase;

public class CompanyTest extends TestCase {
	private Company o1, o2, o3, o4, o5;
	private Employee e1, e2, e3, e4;

	protected void setUp() throws Exception {
		super.setUp();
		//Company objects
		o1 = new Company();
		o2 = new Company("Seneca");
		o3 = new Company("Seneca");
		o4 = new Company("Not_Seneca");
		o5 = new Company("Seneca");

		//Employee objects
		e1 = new Employee("Eddy Choi","U12345",'T');
		e2 = new Programmer("Programmer", "P12345", 1000);
		e3 = new Manager("Manager","M12345",1000, 2000);
		e4 = new Employee("Employee","E12345",'U');

		//set overtime value
		((Programmer)e2).addOvertimePay(500);
	}

	public void testCompany() {
		//test company object created
		assertTrue(o1 != null);

		//test company name as empty string
		assertEquals("",o1.getCompanyName());
	}

	public void testCompanyString() {
		//Test company object created
		assertTrue(o2 != null);
		assertTrue(o3 != null);
		assertTrue(o4 != null);

		//test comapny name
		assertEquals("Seneca",o2.getCompanyName());
		assertEquals("Seneca",o3.getCompanyName());
		assertEquals("Not_Seneca",o4.getCompanyName());	
	}

	public void testGetCompanyName() {
		//test comapny name
		assertEquals("",o1.getCompanyName());
		assertEquals("Seneca",o2.getCompanyName());
		assertEquals("Seneca",o3.getCompanyName());
		assertEquals("Not_Seneca",o4.getCompanyName());	
	}

	public void testHire() {
		//Local Company object
		Company local = new Company("Local");

		//hire new employee - expect true
		assertTrue(local.hire(e1)==true);
		assertTrue(local.hire(e2)==true);
		assertTrue(local.hire(e3)==true);
		assertTrue(local.hire(e4)==true);

		//hire same employee - expect false;
		assertTrue(local.hire(e1)==false);
		assertTrue(local.hire(e2)==false);
		assertTrue(local.hire(e3)==false);
		assertTrue(local.hire(e4)==false);


	}

	public void testLayoff() {
		//Local Company object
		Company local = new Company("Local");

		//hire new employee - expect true
		assertTrue(local.hire(e1)==true);
		assertTrue(local.hire(e2)==true);
		assertTrue(local.hire(e3)==true);
		assertTrue(local.hire(e4)==true);

		//Try fire with invalid Id
		assertTrue(local.layoff("N12345")==null);

		//Fire e1 w/ ID U12345 - expect e1
		assertEquals(e1,local.layoff("U12345"));


	}

	public void testGetAllEmployees() {
		//Local Company object
		Company local = new Company("Local");

		//hire new employee - expect true
		assertTrue(local.hire(e1)==true);
		assertTrue(local.hire(e2)==true);
		assertTrue(local.hire(e3)==true);
		assertTrue(local.hire(e4)==true);

		//make employee array
		Employee [] expected = {e1, e2, e3, e4};

		//get all employee array
		for(int i = 0 ; i < 4; i++)
		{
			assertEquals(expected[i],local.getAllEmployees()[i]);
		}

		//empty company return null
		assertEquals(null,o1.getAllEmployees());
	}

	public void testEqualsObject() {
		//Empty company test
		//Same name
		assertTrue(o2.equals(o3)==true);
		//different name
		assertTrue(o2.equals(o4)==false);
		//compare with empty
		assertTrue(o2.equals(o1)==false);


		//company 1 = no name, employee 1,2,3,4 in sequence
		o1.hire(e1);
		o1.hire(e2);
		o1.hire(e3);
		o1.hire(e4);

		//company 2 = Seneca, employe 1234
		o2.hire(e1);
		o2.hire(e2);
		o2.hire(e3);
		o2.hire(e4);

		//company 3 = Seneca, employee 1234 (same)
		o3.hire(e1);
		o3.hire(e2);
		o3.hire(e3);
		o3.hire(e4);

		//company 4 = Not_seneca, employe 1234 (not same)
		o4.hire(e1);
		o4.hire(e2);
		o4.hire(e3);
		o4.hire(e4);

		//company 5 = Seneca, employee 4321 (different sequence)
		o5.hire(e4);
		o5.hire(e3);
		o5.hire(e2);
		o5.hire(e1);

		//compare with same name / same sequence
		assertTrue(o2.equals(o3)==true);

		//compare with same name / different emplyee
		assertTrue(o2.equals(o5)==false);

		//compare with diff name/ same employee
		assertTrue(o2.equals(o4)==false);

		//compare with no name / sampe employee
		assertTrue(o2.equals(o1)==false);

	}

}


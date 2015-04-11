/*
 * ##################################################################
 * BTP400 - Assignment 1
 * Due: Feb. 15, 15
 * Group Member : Jung Geon Choi
 * Entire Code for JUnit testing is written solely by Jung Geon Choi
 * ##################################################################
 */

package testing.btp400.w2015;

import ontario.people.Employee;
import junit.framework.TestCase;

public class EmployeeTest extends TestCase {
	//Test variables
	private Employee o1, o2, o3, o4;

	protected void setUp() throws Exception {
		super.setUp();

		//Default
		o1 = new Employee();

		//Object with values
		o2 = new Employee("Jung Choi", "A12345",'A');
		o3 = new Employee("Jung Choi", "B12345", 'B');
		o4 = new Employee("John Doe", "A12345", 'C');		
	}

	public void testEmployee() {
		//Test if default construct create a object
		assertTrue(o1!=null);

		//test if empty string is set
		assertEquals("",o1.getName());
		assertEquals("",o1.getEmployeeID());

		//test if default Char is set
		assertEquals('U',o1.getStatus());
	}

	public void testEmployeeStringStringChar() {
		//Test if constructor with parameter create a object
		assertTrue(o2!=null);
		assertTrue(o3!=null);
		assertTrue(o4!=null);

		//test inserted values are set
		assertEquals("Jung Choi", o2.getName());
		assertEquals("A12345", o2.getEmployeeID());
		assertEquals('A',o2.getStatus());
		assertEquals(0.00,o2.getMonthlySalary());

		assertEquals("Jung Choi", o3.getName());
		assertEquals("B12345", o3.getEmployeeID());
		assertEquals('B',o3.getStatus());
		assertEquals(0.00,o3.getMonthlySalary());

		assertEquals("John Doe", o4.getName());
		assertEquals("A12345", o4.getEmployeeID());
		assertEquals('C',o4.getStatus());
		assertEquals(0.00,o4.getMonthlySalary());
	}

	public void testGetName() {
		//Check if get name return the name corerctly
		assertEquals("",o1.getName());
		assertEquals("Jung Choi", o2.getName());
		assertEquals("Jung Choi", o3.getName());
		assertEquals("John Doe", o4.getName());
	}

	public void testGetEmployeeID() {
		//Check if function return employeeid correctly
		assertEquals("",o1.getEmployeeID());
		assertEquals("A12345", o2.getEmployeeID());
		assertEquals("B12345", o3.getEmployeeID());
		assertEquals("A12345", o4.getEmployeeID());
	}

	public void testGetStatus() {
		//Check if function return status correctly
		assertEquals('U', o1.getStatus());
		assertEquals('A', o2.getStatus());
		assertEquals('B', o3.getStatus());
		assertEquals('C', o4.getStatus());
	}

	public void testGetMonthlySalary() {
		//check if monthly salary return value correctly
		assertEquals(0.00,o1.getMonthlySalary());
		assertEquals(0.00,o2.getMonthlySalary());
		assertEquals(0.00,o3.getMonthlySalary());
		assertEquals(0.00,o4.getMonthlySalary());
	}

	public void testGetPay() {
		//check if getpay return 0
		assertEquals(0.00, o1.getPay());
		assertEquals(0.00, o2.getPay());
		assertEquals(0.00, o3.getPay());
		assertEquals(0.00, o4.getPay());
	}

	public void testEqualsObject() {
		//Different ID and same name - expect false
		assertTrue(o2.equals(o3)==false);

		//Different all - expect false
		assertTrue(o2.equals(o1)==false);

		//Different name, same Id - expect true
		assertTrue(o2.equals(o4));
	}

}

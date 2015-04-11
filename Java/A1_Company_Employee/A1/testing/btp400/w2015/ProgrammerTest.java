/*
 * ##################################################################
 * BTP400 - Assignment 1
 * Due: Feb. 15, 15
 * Group Member : Jung Geon Choi
 * Entire Code for JUnit testing is written solely by Jung Geon Choi
 * ##################################################################
 */

package testing.btp400.w2015;

import ontario.people.Programmer;
import junit.framework.TestCase;

public class ProgrammerTest extends TestCase {
	private Programmer o1, o2, o3, o4;

	protected void setUp() throws Exception {
		super.setUp();
		o1 = new Programmer();
		o2 = new Programmer("Eddy Choi", "P12345", 100);
		o3 = new Programmer("Eddy Choi", "P12345", 1000);
		o4 = new Programmer("Eddy Choi", "P12345", 2000);
	}

	public void testProgrammer() {
		//Test if object is created
		assertTrue(o1 != null);

		//check value
		assertEquals("",o1.getName());
		assertEquals("",o1.getEmployeeID());
		assertEquals(0.00,o1.getOvertimePay());
		assertEquals(0.00,o1.getMonthlySalary());
		assertEquals(0.00,o1.getPay());
		assertEquals('P',o1.getStatus());
	}

	public void testProgrammerStringStringBigDecimal() {
		//Test of object with parameter is created
		assertTrue(o2 != null);
		assertTrue(o3 != null);
		assertTrue(o4 != null);

		//check value
		assertEquals("Eddy Choi",o2.getName());
		assertEquals("P12345",o2.getEmployeeID());
		assertEquals(0.00,o2.getOvertimePay());
		assertEquals(100.00,o2.getMonthlySalary());
		assertEquals(100.00,o2.getPay());
		assertEquals('P',o2.getStatus());		
	}

	public void testAddOvertimePay() {
		//Case 1: add overtime for salary 0 - expect false
		assertTrue(o1.addOvertimePay(1)==false);

		//Case 2: add over time (51) to salary 100 - expect false
		assertTrue(o2.addOvertimePay(51) == false);

		//Case 3: add over time (49) to salary 100 - expect true
		assertTrue(o2.addOvertimePay(49) == true);
		//Check the updated value
		assertEquals(49.00, o2.getOvertimePay());

		//Case 4: add over time (110) (multiple times) up to 440 to salary 1000 -expect true
		for(int i = 0; i<4;i++)
			assertTrue(o3.addOvertimePay(110) == true);
		//add over 500 - expect false
		assertTrue(o3.addOvertimePay(110) == false);
		//check value - expect 440
		assertEquals(440.00, o3.getOvertimePay());
		
		//Case 5: add negative value
		assertTrue(o3.addOvertimePay(-1)==false);

	}

	public void testSetOvertimePay() {
		//Case 1: Set 0 - expect true
		assertTrue(o1.setOvertimePay(0)==true);

		//Case 2: Set 1 for monthly salary 0 - expect false
		assertTrue(o1.setOvertimePay(1)==false);

		//Case3: Set 0~50 for monthly salary 100 - expect true
		for(double i=0.00; i<51;i++)
			assertTrue(o2.setOvertimePay(i)==true);
		//Case4: Set 51~99 for monthly salary 100 - expect false
		for(double i=51.00; i<100;i++)
			assertTrue(o2.setOvertimePay(i)==false);
		
		//Case5: set negative value
		assertTrue(o2.setOvertimePay(-1)==false);
	}

	public void testGetOvertimePay() {
		//test get returns overtime
		Programmer local1 = new Programmer("Local Value", "L12345", 1000.00);
		local1.setOvertimePay(500.00);

		//expect-500
		assertEquals(500.00,local1.getOvertimePay());
	}

	public void testGetPay() {
		//test get returns sum of monthly + overtime
		Programmer local1 = new Programmer("Local Value", "L12345", 1000.00);
		local1.setOvertimePay(500.00);

		//expect-1500
		assertEquals(500.00,local1.getOvertimePay());
		assertEquals(1500.00,local1.getPay());
	}

}


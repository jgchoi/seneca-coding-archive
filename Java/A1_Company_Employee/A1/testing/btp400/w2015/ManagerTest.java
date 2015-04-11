/*
 * ##################################################################
 * BTP400 - Assignment 1
 * Due: Feb. 15, 15
 * Group Member : Jung Geon Choi
 * Entire Code for JUnit testing is written solely by Jung Geon Choi
 * ##################################################################
 */

package testing.btp400.w2015;

import ontario.people.Manager;
import junit.framework.TestCase;

public class ManagerTest extends TestCase {
	private Manager o1, o2, o3, o4;

	protected void setUp() throws Exception {
		super.setUp();
		o1 = new Manager();
		o2 = new Manager("Eddy Choi", "M12345", 500.00, 500.00);
		o3 = new Manager("Eddy Choi", "M54321", 100.00, 300.00);
		o4 = new Manager("Eddy Kim", "M12345", 1500.00, 3500.00);

	}

	public void testGetPay() {
		//Check for sum of bonus and monthly salary
		assertEquals(0.00, o1.getPay());
		assertEquals(1000.00, o2.getPay());
		assertEquals(400.00, o3.getPay());
		assertEquals(5000.00, o4.getPay());
	}

	public void testManager() {
		//check if object created correctly with value
		assertTrue(o1 != null);
		assertEquals("",o1.getName());
		assertEquals("",o1.getEmployeeID());
		assertEquals(0.00,o1.getBonusPay());
		assertEquals(0.00,o1.getMonthlySalary());
		assertEquals(0.00,o1.getPay());
		assertEquals('M',o1.getStatus());
	}

	public void testManagerStringStringDoubleBigDecimal() {
		//Check object value as constructed
		assertTrue(o2 != null);
		assertEquals("Eddy Choi",o2.getName());
		assertEquals("M12345",o2.getEmployeeID());
		assertEquals(500.00,o2.getBonusPay());
		assertEquals(500.00,o2.getMonthlySalary());
		assertEquals(1000.00,o2.getPay());
		assertEquals('M',o2.getStatus());

		//Check object value as constructed
		assertTrue(o3 != null);
		assertEquals("Eddy Choi",o3.getName());
		assertEquals("M54321",o3.getEmployeeID());
		assertEquals(100.00,o3.getBonusPay());
		assertEquals(300.00,o3.getMonthlySalary());
		assertEquals(400.00,o3.getPay());
		assertEquals('M',o3.getStatus());

		//Check object value as constructed
		assertTrue(o4 != null);
		assertEquals("Eddy Kim",o4.getName());
		assertEquals("M12345",o4.getEmployeeID());
		assertEquals(1500.00,o4.getBonusPay());
		assertEquals(3500.00,o4.getMonthlySalary());
		assertEquals(5000.00,o4.getPay());
		assertEquals('M',o4.getStatus());
	}

	public void testGetBonusPay() {
		//Check Bnous Pay
		assertEquals(0.00,o1.getBonusPay());
		assertEquals(500.00,o2.getBonusPay());
		assertEquals(100.00,o3.getBonusPay());
		assertEquals(1500.00,o4.getBonusPay());
	}

}

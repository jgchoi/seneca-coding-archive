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
import seneca.finance.Payroll;

public class CustomizedTest {

	public static void runTest() {

		// Variables
		Company o1;
		Employee e1, e2, e3, e4;
		Payroll p1;

		// Company objects
		o1 = new Company("Seneca");

		// Employee objects
		e1 = new Employee("Eddy Choi", "U12345", 'T');
		e2 = new Programmer("Programmer", "P12345", 1000);
		e3 = new Manager("Manager", "M12345", 1000, 2000);
		e4 = new Employee("Employee", "E12345", 'U');

		// set up employees
		((Programmer) e2).setOvertimePay(400);

		// hire for company
		o1.hire(e1);
		o1.hire(e2);
		o1.hire(e3);
		o1.hire(e4);

		// Payroll object
		p1 = new Payroll(o1, "2015-01-01", "2015-01-15");
		System.out.println("################################################");
		System.out.println("Employee Display test\n");
		
		// Display employee, programmer, manager
		System.out.println(e1);
		System.out.println(e2);
		System.out.println(e3);
		System.out.println(e4);
		System.out.println("\n################################################");
		System.out.println("Company Display test\n");
		
		// Display Company!
		System.out.println(o1);

		// Create pay sub
		p1.createPayStubs();
		System.out.println("\n################################################");
		System.out.println("Payroll ToString test\n");
		
		// View all pay stubs
		System.out.println(p1);
		System.out.println("\n################################################");
		System.out.println("Payroll Individual Show test\n");
		
		// Accessing each pay stub element
		for (int i = 0; i < 4; i++)
			System.out.println(p1.showPayStub(i));
	}
}

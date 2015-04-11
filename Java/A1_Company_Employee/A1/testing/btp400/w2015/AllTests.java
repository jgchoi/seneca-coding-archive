package testing.btp400.w2015;

import junit.framework.Test;
import junit.framework.TestSuite;
public class AllTests {

	public static Test suite() {
		TestSuite suite = new TestSuite("Test for Assignment 1");
		//$JUnit-BEGIN$
		suite.addTestSuite(CompanyTest.class);
		suite.addTestSuite(EmployeeTest.class);
		suite.addTestSuite(ManagerTest.class);
		suite.addTestSuite(ProgrammerTest.class);
		//$JUnit-END$
		
		//#Non-Junit, display test
		CustomizedTest.runTest();
		
		return suite;
	}
}

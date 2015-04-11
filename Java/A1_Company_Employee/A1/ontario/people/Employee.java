package ontario.people;

import java.math.BigDecimal;

public class Employee {
	// Properties
	private String fullName;
	private String employeeID;
	private char status;
	protected BigDecimal monthlySalary;

	// Default constructor
	public Employee() {
		this("", "", 'U');
	}

	// constructor w/ parameter
	public Employee(String _fullName, String _employeeID, char _status) {
		if (_fullName == null)
			fullName = "";
		else
			fullName = _fullName;

		if (_employeeID == null)
			employeeID = "";
		else
			employeeID = _employeeID;

		status = _status;
		monthlySalary = new BigDecimal("0.00");
	}

	// methods
	public String getName() {
		return fullName;
	}

	public String getEmployeeID() {
		return employeeID;
	}

	public char getStatus() {
		return status;
	}

	public double getMonthlySalary() {
		return monthlySalary.doubleValue();
	}

	public double getPay() {
		return 0.00;
	}

	public String toString() {
		String s;
		s = "* Employee Information *\n" + "-Name: " + fullName + "\n"
				+ "-ID: " + employeeID + "\n" + "-Status: " + status + "\n";
		return s;
	}

	public boolean equals(Object _employee) {
		boolean result = false;

		if (_employee instanceof Employee) {
			Employee _employee_cp = (Employee) _employee;

			if (_employee_cp.employeeID.equals(employeeID)) {
				result = true;
			}
		}

		return result;
	}

}

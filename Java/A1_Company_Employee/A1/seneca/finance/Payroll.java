package seneca.finance;

import ontario.business.Company;
import ontario.people.Employee;
import ontario.people.Manager;
import ontario.people.Programmer;

public class Payroll {
	private Company company;
	private String startingPayPeriod;
	private String endingPayPeriod;
	private String[] payStubs;

	public Payroll() {
		this(null, "", "");
	}

	public Payroll(Company _company, String _startingPayPeriod,
			String _endingPayPeriod) {
		company = _company;

		if (_startingPayPeriod == null)
			startingPayPeriod = "";
		else
			startingPayPeriod = _startingPayPeriod;

		if (_endingPayPeriod == null)
			endingPayPeriod = "";
		else
			endingPayPeriod = _endingPayPeriod;

		payStubs = null;
	}

	// Create pay stubs
	public void createPayStubs() {
		int i = 0; // index

		// get employees
		Employee[] employees = company.getAllEmployees();

		// set payStubs array
		payStubs = new String[employees.length];

		// create paysub
		for (Employee employee : employees) {
			// Common Message
			payStubs[i] = "Company: " + company.getCompanyName()
					+ "\nPay period: " + startingPayPeriod + " - "
					+ endingPayPeriod + "\nemployee: " + employee.getName()
					+ " (ID: " + employee.getEmployeeID() + ")\tCategory: "
					+ employee.getStatus() + "\n" + "Monthly salary: $"
					+ String.format("%.2f",employee.getMonthlySalary()) + "\t\t";

			// Unique Message
			if (employee.getStatus() == 'P') {

				payStubs[i] += "Overtime pay: $"
						+ String.format("%.2f",((Programmer) employee).getOvertimePay());
			} else if (employee.getStatus() == 'M') {

				payStubs[i] += "Bonus pay: $"
						+ String.format("%.2f",((Manager) employee).getBonusPay());
			}

			// Common last message
			payStubs[i] += "\n*** Total monthly pay: $" + String.format("%.2f", employee.getPay());
			payStubs[i++] += "\n\n";
		}

	}

	// display paystub
	public String showPayStub(int m) {
		String s = "";

		if (m >= 0 && m < payStubs.length) {
			s = payStubs[m];
		}

		return s;
	}

	public String toString() {
		String s = "### Pay Stubs Heading ###\n"
				+ "Number of employees hired by " + company.getCompanyName()
				+ " : " + payStubs.length + "\n\n";

		for (String paystub : payStubs)
			s += paystub;

		return s;
	}
}

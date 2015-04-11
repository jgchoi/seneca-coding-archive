package ontario.people;

import java.math.BigDecimal;

public class Manager extends Employee {
	// Properties
	private BigDecimal bonusPay;

	// Constructor
	public Manager() {
		this("", "", 0.00, 0.00);
	}

	public Manager(String _fullName, String _employeeID, double _bonusPay,
			double _monthlySalary) {
		super(_fullName, _employeeID, 'M');
		monthlySalary = new BigDecimal(_monthlySalary);
		bonusPay = new BigDecimal(_bonusPay);
	}

	public double getBonusPay() {
		// return as double value
		return bonusPay.doubleValue();
	}

	public double getPay() {
		// add monthly salary with bonus and convert to double
		return bonusPay.add(monthlySalary).doubleValue();
	}

	public String toString() {
		String s;
		s = super.toString();
		s += "-Bonus Pay: $" + bonusPay.setScale(2);
		s += "\n";
		return s;
	}
}
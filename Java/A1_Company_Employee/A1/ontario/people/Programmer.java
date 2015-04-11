package ontario.people;

import java.math.BigDecimal;

public class Programmer extends Employee
{
	private BigDecimal overtimePay;
	
	//Constructor
	public Programmer(){ this("","", 0.00);	}
	
	public Programmer(String _fullName, String _employeeID, double _monthlySalary)
	{
		super(_fullName, _employeeID, 'P');
		monthlySalary = new BigDecimal(_monthlySalary);
		overtimePay = new BigDecimal("0.00");
	}
	
	//AddOverTime
	public boolean addOvertimePay(double ot)
	{
		boolean result = true;

		//Check if sum of current overtime & overtime added is bigger than half of monthly salary
		//or if new added value is smaller than 0, reject the input.
		if(overtimePay.add(new BigDecimal(ot)).compareTo(monthlySalary.divide(new BigDecimal("2.00")))==1 || ot < 0)
			result = false;
		else
			overtimePay = overtimePay.add(new BigDecimal(ot));
		return result;
		
	}
	
	public boolean setOvertimePay(double otPay)
	{
		boolean result = true;
		
		//check if new value is greater than half of salary or negative value
		if( new BigDecimal(otPay).compareTo(monthlySalary.divide(new BigDecimal("2.00"))) == 1 || otPay < 0 )
			result = false;
		else
			overtimePay = new BigDecimal(otPay);
		return result;		
	}
	
	public double getOvertimePay()
	{
		return overtimePay.doubleValue();
	}
	
	public double getPay()
	{
		return overtimePay.add(monthlySalary).doubleValue();
	}
	
	public String toString()
	{
		String s;
		s  = super.toString();
		s += "-Overtime Pay: $" + overtimePay.setScale(2).toString();
		s += "\n";
		return s;
	}
}
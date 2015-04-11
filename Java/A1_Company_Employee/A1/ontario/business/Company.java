package ontario.business;
import java.util.ArrayList;
import ontario.people.Employee;

public class Company {
	//private variables
	private String companyName;
	private ArrayList<Employee> employees;

	//Default constructor
	public Company(){ this("");	}

	//Constructor w/ String parameter
	public Company(String _companyName)
	{
		//Empty string for name if null
		if(_companyName != null)
			companyName = _companyName;
		else
			companyName = "";

		//Initialize new array list
		employees = new ArrayList<Employee>();
	}


	public String getCompanyName()
	{
		return companyName;
	}

	//Add new employee to employees
	public boolean hire(Employee _employee)
	{
		boolean result = true;

		//check duplicate
		for (Employee employee : employees)
			if(employee.equals(_employee))
				result = false;

		//add employee
		if(result)
			employees.add(_employee);

		return result;
	}

	//remove employee by search ID
	public Employee layoff(String employeeID)
	{
		//Return value
		Employee fired = null;

		//Start searching
		for(int i = 0 ; i < employees.size() ; i++)
		{
			//check employeeID
			if(employees.get(i).getEmployeeID().equals(employeeID))
			{
				//Remove from the list, assign for return
				fired = employees.remove(i);
			}
		}
		return fired;
	}

	//Get list of employees
	public Employee [] getAllEmployees()
	{
		Employee [] result = null;

		//Check employee size
		if(employees.size() != 0)
		{
			//new array
			result = new Employee [employees.size()];
			//copy arraylist to array
			result = employees.toArray(result);
		}

		return result;
	}

	public boolean equals(Object _company)
	{
		boolean result = false;

		if( _company instanceof Company )
		{
			//copy
			Company _company_cp = (Company) _company;

			//check company name
			if (
					//Check Company name
					_company_cp.companyName.equals(companyName) &&
					//Check number of employee
					_company_cp.employees.size() == employees.size()
				)
			{
				//both company's employees is empty. 
				if(_company_cp.employees.size() == 0  && employees.size() == 0)
				{
					result = true;
				}
				else
				{
					//test employees
					for (int i = 0 ; i < employees.size(); i++)
					{	
						result = true;
						//if any of index have different employee it's not same
						if(!_company_cp.employees.get(i).equals(employees.get(i)))
							result = false;
					}
				}
			}  
		}    

		return result;
	}

	public String toString()
	{
		String s;
		s = 	"* Company Information *\n"+
				"-Name: " + companyName + "\n"+
				"-Employees: " + employees.size() + "\n\n";

		return s;
	}

}
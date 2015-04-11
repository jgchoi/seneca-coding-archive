//Employee.h
//
class Employee {
	int empNum;
	char * empName;
	
	public:
		void display() const;
		bool isGreaterThan(const Employee &) const;
		bool read();
		
		Employee();
		~Employee();
		Employee(int, const char *);
		Employee(Employee &);
		Employee & operator = (const Employee &);
};

#define MAX_EMPLOYEES 5 

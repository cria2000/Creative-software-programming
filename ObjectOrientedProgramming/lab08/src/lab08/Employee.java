package lab08;

public abstract class Employee {
	String name;
	int employeeNum;
	String department;
	int workHrs;
	double salary;
	Employee(String name,int employeeNum){
		this.name=name;
		this.employeeNum=employeeNum;
	}
	public String getDepartment() {
		return department;
	}
	public void setDepartment(String department) {
		this.department=department;
	}
	public int getWorkHrs() {
		return workHrs;
	}
	public void setWorkHrs(int workHrs) {
		this.workHrs=workHrs;
	}
	public boolean equals(Employee otherEmployee) {
		return name.equals(otherEmployee.name)&&otherEmployee.employeeNum==employeeNum;
	}
	public String tostring() {
		return "Name : "+name+"\nEmp# : "+employeeNum;
	}
	public void doWork(int hrs) {
		workHrs+=hrs;
		salary=getPaid();
	}
	public abstract double getPaid();
	public boolean equalPay(Employee emp) {
		return emp.salary==salary;
	}
	
}

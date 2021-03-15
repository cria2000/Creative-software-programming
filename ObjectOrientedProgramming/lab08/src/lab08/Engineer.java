package lab08;

public class Engineer extends Employee{
	double rate;
	Engineer(String name, int employeeNum){
		super(name,employeeNum);
		rate=4.0;
		setDepartment("Engineering");
	}
	public boolean equals(Engineer eng) {
		return name.equals(eng.name)&&employeeNum==eng.employeeNum;
	}
	public String toString() {
		return "Name : "+name+"\nEmp# : "+employeeNum+"\nDept : "+department+"\n";
	}
	public double getPaid() {
		return workHrs*rate;
	}
}

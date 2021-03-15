package lab08;

public class Manager extends Employee {
	double overtimeRate;
	double rate;
	int regularHrs;
	Manager(String name, int employeeNum){
		super(name,employeeNum);
		rate=5.0;
		overtimeRate=8.0;
		regularHrs=40;
		setDepartment("Management");
	}
	public boolean equals(Manager mng) {
		return name.equals(mng.name)&&employeeNum==mng.employeeNum;
	}
	public String toString() {
		return "Name : "+name+"\nEmp# : "+employeeNum+"\nDept : "+department+"\n";
	}
	public double getPaid() {
		int overtimeHrs=workHrs-regularHrs;
		if(workHrs<40)
			return workHrs*rate;
		else
			return (regularHrs*rate)+(overtimeHrs*overtimeRate);
	}

}

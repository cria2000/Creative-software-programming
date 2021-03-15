package lab09;

public class Employee {
	String name;
	int workDay;
	int workHrs;
	Employee(String name){
		this.name=name;
		workDay=1;
		workHrs=0;
	}
	public String getName() {
		return name;
	}
	public int getWorkDay() {
		return workDay;
	}
	public int getWorkHrs() {
		return workHrs;
	}
	public void addWorkDay() {
		++workDay;
	}
	public void addWorkHrs(int Hrs) {
		workHrs+=Hrs;
	}
}

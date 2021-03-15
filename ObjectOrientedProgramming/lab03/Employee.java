package lab03;

public class Employee {
	private String name;
	private int age;
	private String position;
	private int salary;
	private int vacationDays;
	Employee(String name,int age){
		this.name=name;
		this.age=age;
	}
	Employee(String name, int age, int salary){
		this.name=name;
		this.age=age;
		this.salary=salary;
	}
	Employee(String name, int age, String position, int salary){
		this.name=name;
		this.age=age;
		this.position=position;
		this.salary=salary;
		this.vacationDays=20;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name=name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age=age;
	}
	public String getPosition() {
		return position;
	}
	public void setPosition(String position) {
		this.position=position;
	}
	public int getSalary() {
		return salary;
	}
	public void setSalary(int salary) {
		this.salary=salary;
	}
	public int getVacationDays() {
		return vacationDays;
	}
	public void setVacationDays(int vacationDays) {
		this.vacationDays=vacationDays;
	}
	public boolean equals(Employee anotherEmployee) {
		if(this.name.equals(anotherEmployee.name)&&this.age==anotherEmployee.age&&this.position.equals(anotherEmployee.position))
			return true;
		else
			return false;
	}
	public String toString() {
		return "Name: "+this.name+", Age: "+this.age+", Posiiton: "+this.position+", Salary: "+this.salary+", VacationDays: "+vacationDays;
	}
	public boolean vacation(int vacation) {
		if(this.vacationDays<vacation) {
			System.out.println("남은 휴가 일수가 부족합니다.");
			return false;
		}
		else {
			vacationDays=vacationDays-vacation;
			System.out.println("휴가를 사용하였습니다. 남은 휴가 일 수 : "+vacationDays);
			return true;
		}
	}
}

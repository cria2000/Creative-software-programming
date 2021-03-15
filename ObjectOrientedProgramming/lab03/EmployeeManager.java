package lab03;

public class EmployeeManager {

	public static void main(String[] args) {
		Employee em1 = new Employee("James Wright", 42, "Manager", 20000);
		System.out.println(em1.toString());
		
		Employee em2=new Employee("Amy Smith", 27, "Design Coordinator", 8000);
		em2.setVacationDays(15);
		System.out.println(em2.toString());
		
		Employee em3=new Employee("Peter Coolidge", 32, "Assistant Managaer", 12000);
		em3.setVacationDays(7);
		System.out.println(em3.toString());
		
		Employee em4=new Employee("John Doe", 22, "Engineer", 10000);
		em4.setVacationDays(10);
		System.out.println(em4.toString());

		Employee em5=new Employee("Alice Rollen", 20, "Part Time job",50000);
		
		System.out.println(em2.equals(em5));
		
		em1.vacation(10);
		em3.vacation(10);
		
		System.out.println(em1.toString());
		System.out.println(em2.toString());
		System.out.println(em3.toString());
		System.out.println(em4.toString());
	}
}

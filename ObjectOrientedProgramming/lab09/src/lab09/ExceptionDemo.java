package lab09;
import java.util.Scanner;
public class ExceptionDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner key=new Scanner(System.in);
		Employee emp=new Employee("Yu");
		while(true) {
			System.out.print(emp.getWorkDay()+"일차 근무 시간을 입력하세요 : ");
			int hrs=key.nextInt();
			try{
				if(hrs<0) throw new NegativeException();
				else if (hrs==0) throw new Exception("Program Exit");
				else if(hrs>24) throw new TooMuchStuffException(hrs);
				else {
					emp.addWorkHrs(hrs);
					emp.addWorkDay();
					System.out.println("이름 : "+emp.getName());
					System.out.println("누적 근무 시간 : "+emp.getWorkHrs());
					System.out.println("No Exception has been occurred");
				}
			}catch(NegativeException e) {
				System.out.println(e.getMessage());
			}
			catch(TooMuchStuffException e) {
				System.out.println(e.getMessage()+e.getInputNum()+" occurs TooMuchStuffException");
			}
			catch(Exception e) {
				System.out.println(e.getMessage());
				System.exit(0);
			}
			finally {
				System.out.println("End of try-catch statement");
			}
		}
	}

}

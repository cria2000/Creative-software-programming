package lab09;
import java.util.Scanner;
public class ExceptionDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner key=new Scanner(System.in);
		Employee emp=new Employee("Yu");
		while(true) {
			System.out.print(emp.getWorkDay()+"���� �ٹ� �ð��� �Է��ϼ��� : ");
			int hrs=key.nextInt();
			try{
				if(hrs<0) throw new NegativeException();
				else if (hrs==0) throw new Exception("Program Exit");
				else if(hrs>24) throw new TooMuchStuffException(hrs);
				else {
					emp.addWorkHrs(hrs);
					emp.addWorkDay();
					System.out.println("�̸� : "+emp.getName());
					System.out.println("���� �ٹ� �ð� : "+emp.getWorkHrs());
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

import kr.co.Lab05.Collection.*;
import java.util.Calendar;
import java.util.Random;

public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Employee me=new Employee("YU",4500);
		Calendar cal=Calendar.getInstance();
		System.out.println("����� : "+cal.get(Calendar.YEAR)+"/"+(cal.get(Calendar.MONTH)+1)+"/"+cal.get(Calendar.DAY_OF_MONTH));
		System.out.println("Name : "+me.getName());
		System.out.println("���� : "+me.getYearlySalary());
		System.out.println("���� : "+me.getMonthlySalary());
		System.out.println("��� : "+me.getBalance());
		Random rnd=new Random();
		int month=rnd.nextInt(12)+1;
		int mon=1;
		cal.add(Calendar.MONTH,1);
		while(me.getBalance()<20000) {
				me.receiveSalary();
				if(mon%12==1&&mon!=1) {
					int year=rnd.nextInt(11);
					me.increaseYearlySalary(year);
					System.out.println((mon/12+1)+"���� ������ "+year+"% �λ�Ǿ����ϴ�.");
					month=rnd.nextInt(12)+1;
				}	
				if(me.getBalance()<20000) {
					if((cal.get(Calendar.MONTH)+1)==month) {
						me.receiveSalary();
						if(mon%12==0)
							System.out.println(mon/12+"���� "+month+"���� �μ�Ƽ�긦 �޾ҽ��ϴ�.");
						else
							System.out.println((mon/12+1)+"���� "+month+"���� �μ�Ƽ�긦 �޾ҽ��ϴ�.");
						}
					mon++;
					cal.add(Calendar.MONTH,1);
				}
			}
		System.out.println("��¥ : "+cal.get(Calendar.YEAR)+"/"+(cal.get(Calendar.MONTH)+1)+"/"+cal.get(Calendar.DAY_OF_MONTH));
		System.out.println("Name : "+me.getName());
		System.out.println("���� : "+me.getYearlySalary());
		System.out.println("���� : "+me.getMonthlySalary());
		System.out.println("��� : "+me.getBalance());
	}
}
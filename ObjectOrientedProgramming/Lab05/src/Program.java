import kr.co.Lab05.Collection.*;
import java.util.Calendar;
import java.util.Random;

public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Employee me=new Employee("YU",4500);
		Calendar cal=Calendar.getInstance();
		System.out.println("계약일 : "+cal.get(Calendar.YEAR)+"/"+(cal.get(Calendar.MONTH)+1)+"/"+cal.get(Calendar.DAY_OF_MONTH));
		System.out.println("Name : "+me.getName());
		System.out.println("연봉 : "+me.getYearlySalary());
		System.out.println("월급 : "+me.getMonthlySalary());
		System.out.println("재산 : "+me.getBalance());
		Random rnd=new Random();
		int month=rnd.nextInt(12)+1;
		int mon=1;
		cal.add(Calendar.MONTH,1);
		while(me.getBalance()<20000) {
				me.receiveSalary();
				if(mon%12==1&&mon!=1) {
					int year=rnd.nextInt(11);
					me.increaseYearlySalary(year);
					System.out.println((mon/12+1)+"년차 연봉이 "+year+"% 인상되었습니다.");
					month=rnd.nextInt(12)+1;
				}	
				if(me.getBalance()<20000) {
					if((cal.get(Calendar.MONTH)+1)==month) {
						me.receiveSalary();
						if(mon%12==0)
							System.out.println(mon/12+"년차 "+month+"월에 인센티브를 받았습니다.");
						else
							System.out.println((mon/12+1)+"년차 "+month+"월에 인센티브를 받았습니다.");
						}
					mon++;
					cal.add(Calendar.MONTH,1);
				}
			}
		System.out.println("날짜 : "+cal.get(Calendar.YEAR)+"/"+(cal.get(Calendar.MONTH)+1)+"/"+cal.get(Calendar.DAY_OF_MONTH));
		System.out.println("Name : "+me.getName());
		System.out.println("연봉 : "+me.getYearlySalary());
		System.out.println("월급 : "+me.getMonthlySalary());
		System.out.println("재산 : "+me.getBalance());
	}
}
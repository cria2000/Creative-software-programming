import java.util.Scanner;

public class lab1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner keyboard=new Scanner(System.in);
		String name;
		name=keyboard.nextLine();
		String[] name_arr=name.split(" ");
		int len=name_arr.length-1;
		for(int i=1;i<len;i++) {
			name_arr[i]=name_arr[i].substring(0,1);
			name_arr[i]=name_arr[i].toUpperCase();
		}
		String first=name_arr[0].substring(0,1);
		first=first.toUpperCase();
		first+=name_arr[0].substring(1);
		
		String pdf=name_arr[len].replace("ppt", "pdf");
		
		String hw=pdf.substring(0,1);
		hw=hw.toUpperCase();
		hw+=pdf.substring(1);
		
		System.out.println("Name Length(Korean) : "+len);
		
		for(int i=1;i<len;i++) {
			System.out.print(name_arr[i]+".");
		}
		System.out.println(first+" submitted "+hw);
		
	}

}

import java.util.Scanner;
public class PriceListApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner keyboard=new Scanner(System.in);
		PriceList list=new PriceList();
		int ans;
		int col=0;
		while(true) {
			System.out.println("================Main Menu================");
			System.out.println("(1) Add a oil to price list");
			System.out.println("(2) View Region Information");
			System.out.println("(3) Print the entire list");
			System.out.println("(4) Exit the program");
			System.out.println("=========================================");
			System.out.print("choose a menu : ");
			ans=keyboard.nextInt();
			if(ans==1) {
				try {
					if(col>=list.getVertical()) {
						throw new FullArrayException();
					}
				}
				catch(FullArrayException e) {
					System.out.println(e.getMessage());
					ans=keyboard.nextInt();
					list.extendList(ans);
					System.out.println("list is extended.\n");
				}
				String company;
				int price;
				System.out.print("company : ");
				company=keyboard.next();
				System.out.print("supply price : ");
				price=keyboard.nextInt();
				Gasoline ga=new Gasoline(price,company);
				list.setPriceList(col,0,ga);
				System.out.println("gasoline added\n");
				System.out.print("company : ");
				company=keyboard.next();
				System.out.print("supply price : ");
				price=keyboard.nextInt();
				Diesel di=new Diesel(price,company);
				list.setPriceList(col,1,di);
				System.out.println("diesel added");
				++col;
			}
			else if(ans==2) {
				System.out.print("region number to view : ");
				int num=keyboard.nextInt();
				System.out.println(list.getRegionInfo(num));
			}
			else if(ans==3) 
				list.printList();
			else if(ans==4) {
				System.out.println("Exit Application");
				keyboard.close();
				System.exit(0);
			}
			else
				System.out.println("Insert 1~4");
		}
	}
}

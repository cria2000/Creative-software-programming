import java.util.Scanner;
public class TimeTableApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TimeTable tt=new TimeTable();
		Scanner keyboard=new Scanner(System.in);
		while(true) {
			System.out.println("================Main Menu================");
			System.out.println("(1) Add a class to my time table");
			System.out.println("(2) View the class");
			System.out.println("(3) Print the entire time table");
			System.out.println("(4) Exit the program");
			int ans=keyboard.nextInt();
			if(ans==1) {
				System.out.print("Day : ");
				String day=(keyboard.next()).toUpperCase();
				System.out.print("Period : ");
				int period=keyboard.nextInt();
				System.out.print("Name : ");
				String name=keyboard.next();
				System.out.print("Tutor : ");
				String tutor=keyboard.next();
				System.out.print("Room : ");
				String room=keyboard.next();
				if(tt.setSchedule(day, period, name, tutor, room)) {
					tt.setSchedule(day, period, name, tutor, room);
					System.out.println("Class successfully added");
				}
				else
					System.out.println("Class was NOT successfully added");
			}
			else if(ans==2) {
				System.out.println("===============View the Class==============");
				System.out.println("(1) At a specific period");
				System.out.println("(2) By subject title");
				ans=keyboard.nextInt();
				if(ans==1) {
					System.out.print("Day : ");
					String day=(keyboard.next()).toUpperCase();
					System.out.print("Period : ");
					int period=keyboard.nextInt();
					Subject s=tt.getSchedule(day, period);
					System.out.println("At that time you have");
					System.out.println(s.getDetails());	
					}
				else if(ans==2) {
					System.out.println("=============By subject title=============");
					System.out.println("(1) Specific title");
					System.out.println("(2) View all subjects");
					ans=keyboard.nextInt();
					if(ans!=1&&ans!=2)
						System.out.println("Insert 1~2");
					else if(ans==1) {
						System.out.print("Title : ");
						String title=keyboard.next();
						if(tt.getSubjectByTitle(title)!=null)
							System.out.println(tt.getSubjectByTitle(title).getDetails());
						else 
							System.out.println("It doesn't exit");
					}
					else if(ans==2) {
						Subject[] s=new Subject[50];
						s=tt.getAllSubjects();
						for(int i=0;i<s.length;i++) {
							if(s[i]!=null) {
								System.out.println("------------");
								System.out.println(s[i].getDetails());
								System.out.println("------------");
								}
							}
						}
					}
			}
				else if(ans==3) {
					tt.printTimetable();
				}
				else if(ans==4) {
					System.out.println("Exit the apllication");
					System.exit(0);
				}
				else
					System.out.println("Insert 1 ~ 4");
		}
	}
}

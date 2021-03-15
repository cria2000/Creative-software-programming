
public class TimeTable {
	private Subject[][] timeTable;
	public TimeTable(){
		initialize();
	}
	private void initialize() {
		timeTable=new Subject[10][5];
		for(int i=0;i<10;i++) {
			for(int j=0;j<5;j++) {
				if(i!=2&&i!=6) {
					timeTable[i][j]=new Subject("----");
				}
			}
		}
		for(int k=0;k<5;k++) {
			timeTable[2][k]=new Subject("BREAK");
			timeTable[6][k]=new Subject("LUNCH");
		}
	}
	private int getNumByDay(String day) {
		if(day.equals("MON"))
			return 0;
		else if (day.equals("TUE"))
			return 1;
		else if(day.equals("WED"))
			return 2;
		else if(day.equals("THU"))
			return 3;
		else if(day.equals("FRI"))
			return 4;
		else 
			return -1;
	}
	public Subject getSchedule(String day, int period) {
		return timeTable[period-1][getNumByDay(day)];
	}
	public Subject[] getAllSubjects() {
		Subject[] s=new Subject[50];
		int k=0;
		for(int i=0;i<10;i++) {
			for(int j=0;j<5;j++) {
				if(timeTable[i][j].toString()!="----"&&timeTable[i][j].toString()!="BREAK"&&timeTable[i][j].toString()!="LUNCH") {
						if(s[k]==null) 
							s[k]=new Subject(timeTable[i][j]);
					
						else {
							++k;
							s[k]=new Subject(timeTable[i][j]);
						}
				}
			}
		}
		return s;
	}
	public Subject getSubjectByTitle(String title) {
		for(int i=0;i<10;i++) {
			for(int j=0;j<5;j++) {
				if(timeTable[i][j].equals(title))  
					return timeTable[i][j];		
			}
		}
		return null;
	}
	public boolean setSchedule(String day, int period, String name, String tutor, String room){
		if(timeTable[period-1][getNumByDay(day.toUpperCase())].toString()=="BREAK"||timeTable[period-1][getNumByDay(day.toUpperCase())].toString()=="LUNCH")
			return false;
		else { 
			timeTable[period-1][getNumByDay(day.toUpperCase())]=new Subject(name);
			timeTable[period-1][getNumByDay(day.toUpperCase())].setTutor(tutor);
			timeTable[period-1][getNumByDay(day.toUpperCase())].setRoom(room);
			return true;			
		}
	}
	public void printTimetable() {
		System.out.print("\tMON\tTUE\tWED\tTHU\tFRI");
		System.out.println();
		for(int i=0;i<10;i++) {
			System.out.print((i+1)+"\t");
			for(int j=0;j<5;j++) {
				System.out.print(timeTable[i][j]+"\t");
			}
			System.out.println();
		}
	}
}

package lab07;

public class Manager extends Employee {
	int officeNum;
	String team;
	Manager(String name, int employeeNum, int officeNum, String team){
		super(name,employeeNum);
		this.officeNum=officeNum;
		this.team=team;
		this.department="Management";
	}
	public String toString() {
		return "Name : "+name+"\n"+"Emp# : "+employeeNum+"\n"+"location : "+department+", office : "+officeNum;
	}
	public boolean equals(Object obj) {
		if(super.equals(obj)==true) {
			Manager otherMng=(Manager)obj;
			return (officeNum==otherMng.officeNum)&&(team==otherMng.team);
		}
		else 
			return false;
	}

}

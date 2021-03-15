package lab07;

public class Engineer extends Employee{
	String workZone;
	String project;
	Engineer(String name, int employeeNum, String workZone, String project){
		super(name,employeeNum);
		this.workZone=workZone;
		this.project=project;
		department="Engineering";
	}
	public boolean equals(Object obj) {
		if(super.equals(obj)==true) {
			Engineer otherEng=(Engineer)obj;
			return (workZone==otherEng.workZone)&&(project==otherEng.project);
		}
		else 
			return false;
	}
	public String toString() {
		return "Name : "+name+"\nEmp# : "+employeeNum+"\nlocation : "+department+", zone : "+workZone;
	}
}


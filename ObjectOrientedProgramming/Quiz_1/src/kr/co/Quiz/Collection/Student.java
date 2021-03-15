package kr.co.Quiz.Collection;
import java.util.Random;
public class Student {
	private String name;
	private int StudentNumber;
	private int Korean;
	private int Math;
	private int English;
	private double Avg;
	public Student(String name, int Korean, int Math, int English){
		this.name=name;
		this.Korean=Korean;
		this.Math=Math;
		this.English=English;
		Random rnd=new Random();
		int rand=rnd.nextInt(9999);
		this.StudentNumber=2018000000+rand+1;
		Avg=(this.Korean+this.Math+this.English)/3.0;
	}
	public Student(Student AnotherStudent){
		this.name=AnotherStudent.name;
		this.StudentNumber=AnotherStudent.StudentNumber;
		this.Korean=AnotherStudent.Korean;
		this.Math=AnotherStudent.Math;
		this.English=AnotherStudent.English;
		this.Avg=AnotherStudent.Avg;
	}
	public static void makeRank(Student[] StudentList) {
		Student temp;
		for(int i=StudentList.length-1;i>0;i--) {
			for(int j=0;j<i;j++) {
				if(StudentList[j].StudentNumber>StudentList[j+1].StudentNumber) {
					temp=new Student(StudentList[j]);
					StudentList[j]=new Student(StudentList[j+1]);
					StudentList[j+1]=temp;
							}
			}
		}
	}
	
	public String Grade(int score) {
		String grade=null;
		if(score>90||score==90) {
			grade="A";}
		else if(score<90&&score>=80) {
			grade="B";}
		else if(score<80&&score>=70) {
			grade="C";}
		else if(score<70&&score>=60) {
			grade="D";}
		else if(score<60) {
			grade="F";}
		return grade;
	}
	
	public String toString() {
		return "이름 : "+name+" 학번 : "+StudentNumber+"\n국어 : "+Grade(Korean)+" 수학 : "+Grade(Math)+" 영어 : "+Grade(English)+"\n평균 : "+Avg;
	}
}

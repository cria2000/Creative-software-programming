package kr.co.Quiz1;
import kr.co.Quiz.Collection.*;
import java.util.Scanner;
public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner keyboard=new Scanner(System.in);
		Student[] StudentList;
		int num;
		System.out.printf("학생 수를 입력하세요 : ");
		num=keyboard.nextInt();
		StudentList=new Student[num];
		String name;
		int Korea,Math,English;
		for(int i=0;i<num;i++) {
			System.out.printf("학생 이름을 입력하세요 : ");
			name=keyboard.next();
			System.out.printf("국어 성적을 입력하세요: ");
			Korea=keyboard.nextInt();
			System.out.printf("수학 성적을 입력하세요: ");
			Math=keyboard.nextInt();
			System.out.printf("영어 성적을 입력하세요: ");
			English=keyboard.nextInt();
			StudentList[i]=new Student(name,Korea,Math,English);
			}
		Student.makeRank(StudentList);
		for(int i=0;i<num;i++) {
			System.out.printf((i+1)+". ");
			System.out.println(StudentList[i].toString());
		}
		

	}

}

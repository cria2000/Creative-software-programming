package kr.co.Quiz1;
import kr.co.Quiz.Collection.*;
import java.util.Scanner;
public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner keyboard=new Scanner(System.in);
		Student[] StudentList;
		int num;
		System.out.printf("�л� ���� �Է��ϼ��� : ");
		num=keyboard.nextInt();
		StudentList=new Student[num];
		String name;
		int Korea,Math,English;
		for(int i=0;i<num;i++) {
			System.out.printf("�л� �̸��� �Է��ϼ��� : ");
			name=keyboard.next();
			System.out.printf("���� ������ �Է��ϼ���: ");
			Korea=keyboard.nextInt();
			System.out.printf("���� ������ �Է��ϼ���: ");
			Math=keyboard.nextInt();
			System.out.printf("���� ������ �Է��ϼ���: ");
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

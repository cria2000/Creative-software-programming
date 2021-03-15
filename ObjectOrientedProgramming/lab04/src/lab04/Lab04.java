package lab04;

public class Lab04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		City city1=new City("Seoul",23,45);
		System.out.println(city1.toString());
		City city2=new City("Paris",123,41);
		System.out.println(city2.toString());
		City city3=new City("Racoon City");
		System.out.println(city3.toString());
		City city4=new City("Mega City");
		System.out.println(city4.toString());
		System.out.println("Seoul-Paris : "+City.Distance(city1, city2));
		System.out.println("Seoul-Racoon City : "+City.Distance(city1,city3));
		System.out.println("Paris-Mega City : "+City.Distance(city2,city4));
	}
}

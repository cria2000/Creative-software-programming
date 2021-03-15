import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
	
public class Restaurant {
	static TableSet tbset;
	static ArrayList<Dish> dishes_lee;
	static ArrayList<Dish> dishes_kang;
	public static TableSet loadingData() {
		TableSet tableSet=new TableSet();
		int i=-1;
		try {
			Scanner inputStream = new Scanner(new FileInputStream("OrderSheet.txt"));
			String word=inputStream.next();
			int num=0;
			while(inputStream.hasNext()){			
					word=inputStream.next();
					if(word.equals("ramen")||word.equals("stew")||word.equals("friedrice")||word.equals("ovenroast")) {
						tableSet.addtoTable(i, num, word);
					}
					else if(!word.equals("Table")){
						num=Integer.parseInt(word.substring(1));
						++i;
					}
					}
			inputStream.close();
		}
		catch(FileNotFoundException e) {
			System.out.println("Error!");
		}
		
		return tableSet;
	}
	public static void devideDishes() {
		for(int j=0;j<5;j++) {
			if(tbset.getTableSet()[j].getTableNum()%2==1) {
				for(int a=0; a<tbset.getTableSet()[j].getDishSet().size(); a++) {
					dishes_lee.add(tbset.getTableSet()[j].getDishSet().get(a));
				}
			}
			else {
				for(int b=0; b<tbset.getTableSet()[j].getDishSet().size();b++) {
					dishes_kang.add(tbset.getTableSet()[j].getDishSet().get(b));
				}
			}
		}
	}
	public static void main(String[] args) throws InterruptedException{
		// TODO Auto-generated method stub
		tbset=loadingData();
		dishes_lee=new ArrayList<Dish>();
		dishes_kang=new ArrayList<Dish>();
		Kitchen kitchen=new Kitchen();
		
		devideDishes();
		
		Chef lee=new Chef("Lee", kitchen, dishes_lee);
		Chef kang=new Chef("Kang", kitchen, dishes_kang);
		

		lee.start();
		kang.start();
	}
}


import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DictionaryArray ar=new DictionaryArray();
		Scanner keyboard=new Scanner(System.in);
		int ans;
		while(true) {
			System.out.println("(1) Add a word to dictionary");
			System.out.println("(2) Show definition of word");
			System.out.println("(3) Show word list");
			System.out.println("(4) Remove word");
			System.out.println("(5) print all contents");
			System.out.println("(6) Exit Program");
			ans=keyboard.nextInt();
			switch(ans) {
				case 1 : try {
					System.out.println("word : ");
					String word=keyboard.next();
					System.out.println("definition : ");
					String definition=keyboard.next();
					ar.insertEntry(word,definition);
				}
				catch(AlreadyExistsInDicException e) {
					System.out.println(e.getMessage());
				}
				break;
				
			case 2 : try {
				String word=keyboard.next();
				ar.getDefinition(word);
			}
			catch(EmptyException e) {
				System.out.println(e.getMessage());
			}
			catch(NotInDicException e) {
				System.out.println(e.getMessage());
			}
			break;
			
			case 3 : 
				try {
					ar.printWords();
				}
				catch(EmptyException e) {
					System.out.println(e.getMessage());
				}
				break;
			case 4: 
				try {
					System.out.println("word to remove : ");
					String word=keyboard.next();
					ar.removeWord(word);
				}
				catch(EmptyException e) {
					System.out.println(e.getMessage());
				}
				catch(NotInDicException e) {
					System.out.println(e.getMessage());
				}
				break;
			case 5: try {
				
				ar.printAll();
			}
			catch(EmptyException e) {
				System.out.println(e.getMessage());
			}
			break;
			case 6 : 
				try {
					String name=keyboard.next();
					File fileObject=new File(name);
					PrintWriter outputStream=new PrintWriter(new FileOutputStream(name));
				}
				catch(FileNotFoundException e) {
					System.out.println("Error opening thie file");
				}
				System.exit(0);
				}
		}
}}

public class NotInDicException extends Exception {
	NotInDicException(){
		super("this word not exists in dictionay");
	}
	NotInDicException(String m){
		super(m);
	}
	
}

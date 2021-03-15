
public class EmptyException extends Exception{
	EmptyException(){
		super("list is empty");
	}
	EmptyException(String m){
		super(m);
	}
}

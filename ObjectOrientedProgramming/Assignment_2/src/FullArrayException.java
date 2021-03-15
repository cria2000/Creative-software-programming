
public class FullArrayException extends Exception{
	FullArrayException(){
		super("List is full!\nTry to expand...\nHow much will it expand?");
	}
	FullArrayException(String m){
		super(m);
	}
}

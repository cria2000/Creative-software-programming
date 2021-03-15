
public class AlreadyExistsInDicException extends Exception{
	AlreadyExistsInDicException(){
		super("this word exists in dictionary");
	}
	AlreadyExistsInDicException(String m){
		super(m);
	}
}

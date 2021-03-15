package lab09;

public class NegativeException extends Exception{
	NegativeException(){
		super("work time must be positive");
	}
	NegativeException(String m){
		super(m);
	}
}

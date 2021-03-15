package lab09;

public class TooMuchStuffException extends Exception {
	private int inputNum;
	TooMuchStuffException(){
		super("Too much stuff!\n");
	}
	TooMuchStuffException(int num){
		super("Too much stuff!\n");
		inputNum=num;
	}
	public int getInputNum() {
		return inputNum;
	}
}

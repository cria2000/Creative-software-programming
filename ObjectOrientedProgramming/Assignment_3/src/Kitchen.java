
public class Kitchen {
	private int ovenNum;
	private int fryNum;
	private int potNum;
	Kitchen(){
		ovenNum=1;
		fryNum=2;
		potNum=3;
	}
	public synchronized void useOven() throws InterruptedException{
		while(ovenNum==0) {
			System.out.println("The oven is in use.");
			this.wait();
		}
		if(ovenNum!=0)
			--ovenNum;
	}
	public synchronized void releaseOven() throws InterruptedException{
		if(ovenNum<1) {
			++ovenNum;
			notifyAll();
		}
		else
			notifyAll();
	}
	public synchronized void useFriedpan() throws InterruptedException{
		while(fryNum==0) {
			System.out.println("The friedpan is in use.");
			this.wait();
		}
		if(fryNum!=0)
			--fryNum;
	}
	public synchronized void releaseFriedpan() throws InterruptedException{
		if(fryNum<3)
			++fryNum;
		else 
			notifyAll();
	}
	public synchronized void usePot() throws InterruptedException{
		while(potNum==0) {
			System.out.println("The pot is in use.");
			this.wait();
		}
		if(potNum!=0)
			--potNum;
	}
	public synchronized void releasePot() throws InterruptedException{
		 if(potNum<3)
			 ++potNum;
		 else 
			 notifyAll();
	}

}

import java.util.ArrayList;
import java.text.SimpleDateFormat;
public class Chef extends Thread{
	private String name;
	private Kitchen kitchen;
	private ArrayList<Dish> dishes;
	Chef(String name,Kitchen kitchen, ArrayList<Dish> dishes){
		this.name=name;
		this.kitchen=kitchen;
		this.dishes=dishes;
	}
	public void run() {
		synchronized(this) {
		try {
			for(Dish entry : dishes) {
			synchronized(this) {
			if(entry.getName().equals("ramen")||entry.getName().equals("stew")) {
				kitchen.usePot();
			}
			else if(entry.getName().equals("friedrice"))
				kitchen.useFriedpan();
			else if(entry.getName().equals("ovenroast")) {
				kitchen.useOven();
			}
			Thread.sleep(entry.getTime());
			System.out.println("Table #"+entry.getTableNum()+" / "+entry.getName()+" is completed by "+name+". "+new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS").format(System.currentTimeMillis()));
			if(entry.getName().equals("ramen")||entry.getName().equals("stew"))
				kitchen.releasePot();
			else if(entry.getName().equals("friedrice"))
				kitchen.releaseFriedpan();
			else if(entry.getName().equals("ovenroast")) 
				kitchen.releaseOven();
			}
		}
		}catch(InterruptedException e) {
			System.out.println("Error");
		}
		}
	}
}
			
			
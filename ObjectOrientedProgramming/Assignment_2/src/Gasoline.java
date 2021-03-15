import java.util.Random;
public class Gasoline extends Oil {
	private int price;
	private double VAT;
	Gasoline(int price, String company){
		super(company,"gasoline");
		this.price=price;
		Random rnd=new Random();
		int vat=rnd.nextInt(30)+1;
		VAT=(double)vat/100;
	}
	public double getOilPrice() {
		return price+(price*VAT);
	}
	public String toString() {
		return super.toString()+"supply price : "+price+"\n";
	}
}

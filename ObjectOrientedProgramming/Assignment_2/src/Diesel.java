import java.util.Random;
public class Diesel extends Oil{
	private int price;
	private double VAT;
	private double envTax;
	Diesel(int price, String company){
		super(company,"diesel");
		this.price=price;
		Random rnd=new Random();
		int vat=rnd.nextInt(30)+1;
		VAT=(double)vat/100;
		this.envTax=500;
	}
	public double getOilPrice() {
		return price+(price*VAT)+envTax;
	}
	public String toString() {
		return super.toString()+"supply price : "+price;
	}
}

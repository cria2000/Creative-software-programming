
public abstract class Oil {
	private String company;
	private String oilType;
	private double priceInStore;
	Oil(String Company, String oilType){
		this.company=Company;
		this.oilType=oilType;
		this.priceInStore=0;
	}
	public double getPriceInStore() {
		return priceInStore;
	}
	public void setPriceInStore() {
		priceInStore=getOilPrice();
	}
	public String toString() {
		return "company : "+company+"\noil type : "+oilType+"\n";
	}
	public abstract double getOilPrice();
}

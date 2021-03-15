
public class PriceList {
	private Oil[][] priceList;
	private int vertical;
	PriceList(){
		vertical=2;
		priceList=new Oil[2][2];
	}
	public int getVertical() {
		return vertical;
	}
	public void setPriceList(int i, int j, Oil oil) {
			priceList[i][j]=oil;
			priceList[i][j].setPriceInStore();
	}
	public void extendList(int amount) {
		Oil[][] temp=new Oil[vertical+amount][2];
		for(int i=0;i<vertical;i++)
			for(int j=0;j<2;j++)
				temp[i][j]=priceList[i][j];
		vertical=vertical+amount;
		priceList=temp;
	}
	public String getRegionInfo(int i) {
		return priceList[i-1][0].toString()+"\n"+priceList[i-1][1].toString();
	}
	public void printList() {
		System.out.println("                Gasoline        Diesel");
		System.out.println("=================================================");
		for(int i=0;i<vertical;i++) {
			if(priceList[i][0]!=null) {
				System.out.print("Region #"+(i+1)+"        ");
				System.out.println(priceList[i][0].getPriceInStore()+"        "+priceList[i][1].getPriceInStore());
				System.out.println();
			}
		}
	}
}

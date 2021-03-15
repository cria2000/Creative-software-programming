import java.util.ArrayList;
public class Table {
	private int TableNum;
	private ArrayList<Dish> dishSet;
	Table(){
		dishSet=new ArrayList<Dish>(4);
	}
	public int getTableNum() {
		return TableNum;
	}
	public void setTableNum(int TableNum) {
		this.TableNum=TableNum;
	}
	public ArrayList<Dish> getDishSet(){
		return dishSet;
	}
}

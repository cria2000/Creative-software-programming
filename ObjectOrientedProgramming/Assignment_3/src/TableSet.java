
public class TableSet {
	private Table[] tableSet;
	TableSet(){
		tableSet=new Table[5];
		for(int i=0;i<5;i++)
			tableSet[i]=new Table();
	}
	public void addtoTable(int index, int TableNum, String name) {
		tableSet[index].setTableNum(TableNum);
		Dish dish= new Dish(TableNum,name);
		tableSet[index].getDishSet().add(dish);
	}
	public Table[] getTableSet() {
		return tableSet;
	}
}

public class Dish {
	private int tableNum;
	private String name;
	private String tool;
	private int time;
	public int getTableNum() {
		return tableNum;
	}
	public String getName() {
		return name;
	}
	public String getTool() {
		return tool;
	}
	public int getTime() {
		return time;
	}
	Dish(int tableNum, String name){
		this.tableNum=tableNum;
		this.name=name;
		setTool(name);
		setTime(tool);
	}
	public void setTool(String name) {
		if(name.equals("stew")||name.equals("ramen"))
			tool="pot";
		else if(name.equals("friedrice"))
			tool="fryinpan";
		else if(name.equals("ovenroast"))
			tool="oven";
	}
	public void setTime(String tool) {
		if(tool.equals("pot"))
			time=350;
		else if(tool.equals("fryingpan"))
			time=500;
		else if(tool.equals("oven"))
			time=1300;
	}
}

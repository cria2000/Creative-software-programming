
public class Subject {
	private String name;
	private String tutor;
	private String room;
	public Subject(String name, String tutor, String room){
		this.name=name;
		this.tutor=tutor;
		this.room=room;
	}
	public Subject(String name){
		this.name=name;
		this.tutor=null;
		this.room=null;
	}
	public Subject(Subject anotherSubject){
		name=anotherSubject.name;
		tutor=anotherSubject.tutor;
		room=anotherSubject.room;
	}
	public String getName(){
		return name;
	}
	public String getTutor() {
		return tutor;
	}
	public String getRoom() {
		return room;
	}
	public void setTutor(String tutor) {
		this.tutor=tutor;
	}
	public void setRoom(String room) {
		this.room=room;
	}
	public boolean equals(String name) {
		return this.name.equals(name);
	}
	public String toString() {
		return name;
	}
	public String getDetails() {
		return "Name : "+name+"\nTutor : "+tutor+"\nRoom : "+room;
	}
	
}

package kr.co.Lab05.Collection;

public class Employee {
	private String name;
	private double yearly_salary;
	private double monthly_salary;
	private double balance;
	/**
	 * Employee의 생성자(이름과 연봉은 받은 값으로 초기화해주고, 월급은 연봉의 12분의 1, 잔고는 0으로 초기화한다.)
	 * @param name 이름
	 * @param yearly_salary 연봉
	 */
	public Employee(String name, double yearly_salary){
		this.name=name;
		this.yearly_salary=yearly_salary;
		this.monthly_salary=yearly_salary/12;
		this.balance=0;
	}
	/**
	 * Employee class의 name(이름)에 접근할 수 있도록(get할 수 있도록) 해주는 method.
	 * @return name 이름
	 */
	public String getName() {
		return name;
	}
	/**
	 * Employee class의 yearly_salary(연봉)에 접근할 수 있도록(get할 수 있도록) 해주는 method.
	 * @return yearly_salary 연봉
	 */
	public double getYearlySalary() {
		return yearly_salary;
	}
	/**
	 * Employee class의 monthly_salary(월급)에 접근할 수 있도록(get할 수 있도록) 해주는 method.
	 * @return monthly_salary 월급
	 */
	public double getMonthlySalary() {
		return monthly_salary;
	}
	/**
	 * Employee class의 balance(잔고)에 접근할 수 있도록(get할 수 있도록) 해주는 method.
	 * @return balance 잔고
	 */
	public double getBalance() {
		return balance;
	}
	/**
	 * 연봉을 input으로 받은 퍼센트만큼 올려주고, 오른 연봉의 12분의 1로 월급도 다시 초기화해주는 method
	 * @param byPercent 연봉을 몇 퍼센트 올릴 것인지에 대한 값
	 */
	public void increaseYearlySalary(double byPercent) {
		yearly_salary=yearly_salary+(yearly_salary*byPercent*0.01);
		monthly_salary=yearly_salary/12;
	}
	/**
	 * 월급을 받을 수 있도록 하는 method로, 잔고에 월급을 더해준다.
	 */
	public void receiveSalary() {
		balance=balance+monthly_salary;
	}
	
	

}

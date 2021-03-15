package kr.co.Lab05.Collection;

public class Employee {
	private String name;
	private double yearly_salary;
	private double monthly_salary;
	private double balance;
	/**
	 * Employee�� ������(�̸��� ������ ���� ������ �ʱ�ȭ���ְ�, ������ ������ 12���� 1, �ܰ�� 0���� �ʱ�ȭ�Ѵ�.)
	 * @param name �̸�
	 * @param yearly_salary ����
	 */
	public Employee(String name, double yearly_salary){
		this.name=name;
		this.yearly_salary=yearly_salary;
		this.monthly_salary=yearly_salary/12;
		this.balance=0;
	}
	/**
	 * Employee class�� name(�̸�)�� ������ �� �ֵ���(get�� �� �ֵ���) ���ִ� method.
	 * @return name �̸�
	 */
	public String getName() {
		return name;
	}
	/**
	 * Employee class�� yearly_salary(����)�� ������ �� �ֵ���(get�� �� �ֵ���) ���ִ� method.
	 * @return yearly_salary ����
	 */
	public double getYearlySalary() {
		return yearly_salary;
	}
	/**
	 * Employee class�� monthly_salary(����)�� ������ �� �ֵ���(get�� �� �ֵ���) ���ִ� method.
	 * @return monthly_salary ����
	 */
	public double getMonthlySalary() {
		return monthly_salary;
	}
	/**
	 * Employee class�� balance(�ܰ�)�� ������ �� �ֵ���(get�� �� �ֵ���) ���ִ� method.
	 * @return balance �ܰ�
	 */
	public double getBalance() {
		return balance;
	}
	/**
	 * ������ input���� ���� �ۼ�Ʈ��ŭ �÷��ְ�, ���� ������ 12���� 1�� ���޵� �ٽ� �ʱ�ȭ���ִ� method
	 * @param byPercent ������ �� �ۼ�Ʈ �ø� �������� ���� ��
	 */
	public void increaseYearlySalary(double byPercent) {
		yearly_salary=yearly_salary+(yearly_salary*byPercent*0.01);
		monthly_salary=yearly_salary/12;
	}
	/**
	 * ������ ���� �� �ֵ��� �ϴ� method��, �ܰ� ������ �����ش�.
	 */
	public void receiveSalary() {
		balance=balance+monthly_salary;
	}
	
	

}

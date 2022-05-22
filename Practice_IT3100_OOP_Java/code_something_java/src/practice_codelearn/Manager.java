package practice_codelearn;

public class Manager extends Employee {
	private int bonus;

	public Manager() {
		// TODO Auto-generated constructor stub
	}
	public Manager(String name, int salary, int bonus) {
		super(name, salary);
		// TODO Auto-generated constructor stub
		this.bonus = bonus;
	}
	public int getBonus() {
		return bonus;
	}
	public void setBonus(int bonus) {
		this.bonus = bonus;
	}
	@Override
	public void display() {
		super.display();
		System.out.println("Salary: " + (getSalary() + bonus));
	}
	
}

package practice_codelearn;

public class Employee {
	private String name;
	private int salary;

	public Employee() {
		// TODO Auto-generated constructor stub
	}

	public Employee(String name, int salary) {
		super();
		this.name = name;
		this.salary = salary;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getSalary() {
		return salary;
	}

	public void setSalary(int salary) {
		this.salary = salary;
	}
	public void display() {
		System.out.println("Name: " + name);
	}

}

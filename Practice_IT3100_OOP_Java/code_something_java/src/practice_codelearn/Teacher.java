package practice_codelearn;

class Teacher extends Person {
	private int salary;

	public Teacher() {
		// TODO Auto-generated constructor stub
	}

	

	public Teacher(String name, int age, String address, int salary) {
		super(name, age, address);
		// TODO Auto-generated constructor stub
		this.salary = salary;
	}



	public int getSalary() {
		return salary;
	}

	public void setSalary(int salary) {
		this.salary = salary;
	}
	public void display() {
		super.display();
		System.out.println("Salary: " + salary);
	}

}

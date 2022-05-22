package practice_codelearn;

class Student extends Person {
	private double gpa;

	public Student() {
		// TODO Auto-generated constructor stub
	}

	public Student(String name, int age, String address, double gpa) {
		super(name, age, address);
		// TODO Auto-generated constructor stub
		this.gpa = gpa;
	}

	public double getGpa() {
		return gpa;
	}

	public void setGpa(double gpa) {
		this.gpa = gpa;
	}
	public void display() {
		super.display();
		System.out.println("GPA: " + gpa);
	}

}

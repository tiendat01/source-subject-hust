package practice_codelearn;

class Person {
	protected String name, address;
    protected int age;
    
    public Person() {}
    public Person(String name, int age, String address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
    public void display() {
    	System.out.println("Name: " + name);
    	System.out.println("Age: " + age);
    	System.out.println("Address: " + address);
    }
}

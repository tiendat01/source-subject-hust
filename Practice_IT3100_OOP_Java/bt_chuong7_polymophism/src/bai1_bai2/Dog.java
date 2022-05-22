package bai1_bai2;

public class Dog extends Animal {

	@Override
	public void greeting() {
		// TODO Auto-generated method stub
		System.out.println("Woof!");
	}
	
	// overloading
	public void greeting(Dog another) {
		System.out.println("Wooooooooof!");
	}

}

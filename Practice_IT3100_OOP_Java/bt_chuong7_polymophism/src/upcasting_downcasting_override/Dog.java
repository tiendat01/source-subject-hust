package upcasting_downcasting_override;

public class Dog extends Animal {

	@Override
	public String speak() {
		// TODO Auto-generated method stub
		return "The dog says woof!";
	}

	public String eat() {
		return "Eat dog food";
	}
	
	
	// ham check de xem co downcasting ddc ko
	static boolean check1(Object obj) {
		if (obj instanceof Dog) {
			Dog dog = (Dog) obj; // downcasting
			System.out.println("ok downcasting performed");
			return true;
		}
		else {
			System.out.println("obj is not instance of Dog");
			return false;
		}
	}
}

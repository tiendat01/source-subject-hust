package upcasting_downcasting_override;

public class Fox extends Animal {

	@Override
	public String speak() {
		return "What does the fox say?";
	}
	
	public String eat() {
		return "Eat meat";
	}
	
	static void check(Object obj) {
		if (obj instanceof Dog) {
			Fox fox = (Fox) obj; // downcasting
			System.out.println("ok downcasting performed");
		}
		else {
			System.out.println("obj is not instance of Fox");
		}
	}
}

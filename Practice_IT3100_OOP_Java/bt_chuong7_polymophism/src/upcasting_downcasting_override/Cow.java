package upcasting_downcasting_override;

public class Cow extends Animal {

	@Override
	public String speak() {
		return "The cow goes moo!";
	}
	
	public String eat() {
		return "Eat grass";
	}

	static void check(Object obj) {
		if (obj instanceof Dog) {
			Cow cow = (Cow) obj; // downcasting
			System.out.println("ok downcasting performed");
		}
		else {
			System.out.println("obj is not instance of Cow");
		}
	}
}

package upcasting;

public class Cat extends Animal {
	protected String name = "cat";
	public void meow() { System.out.println("meowing..."); }
	// Override pthuc eat() tu lop cha Animal
	public void eat() { System.out.println("eat fish"); }
}

package upcasting_downcasting_override;

public class MainClass {

	public static void main(String[] args) {
		Animal[] animalArray = new Animal[3];
		// upcasting
		animalArray[0] = new Dog();
		animalArray[1] = new Fox();
		animalArray[2] = new Cow();
		
		for (int i = 0; i < animalArray.length; i++) {
			System.out.println(animalArray[i].speak());
		}
		
		// neu muon dung cac phuong thuc khac cua cac lop con
		// downcasting

		if (Dog.check1(animalArray[0])) {
			Dog dog = (Dog) animalArray[0];
			System.out.println(dog.eat());
		}
		
		Object obj = new Rectangle();
		if (Dog.check1(obj)) {
			Dog dog = (Dog) obj;
			System.out.println(dog.eat());
		}
		
//		Fox.check(animalArray[1]);
//		Cow.check(animalArray[2]);
		
		
	}

}

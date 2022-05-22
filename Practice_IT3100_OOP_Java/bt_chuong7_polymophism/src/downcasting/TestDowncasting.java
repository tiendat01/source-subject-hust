package downcasting;

public class TestDowncasting {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Animal animal1 = new Cat();
		Cat cat1 = (Cat) animal1; // downcasting : phai ep kieu tuong minh
		cat1.eat();
		cat1.meow();
	}

}

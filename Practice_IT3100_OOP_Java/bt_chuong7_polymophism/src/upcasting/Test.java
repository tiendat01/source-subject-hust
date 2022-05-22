package upcasting;

public class Test {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat cat = new Cat();
		// ep kieu doi tuong lop con len lop cha
		Animal animal1 = cat; 				// tu dong
		Animal animal2 = (Animal) cat; 		// tuong minh
		cat.eat();	// do tinh ke thua
		cat.meow(); 
		animal1.eat();
		// animal1.meow(); // error
	}
}
package upcasting;

public class TestUpcasting {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Animal animal1 = new Animal();
		
		Animal animal2 = new Cat(); // upcasting: doi tuong lop cha tham chieu den doi tuong lop con
									// upcasting tu dong
		
		Cat cat1 = new Cat();
		Animal animal3 = (Animal) cat1; // upcasting tuong minh
		
		animal1.eat();
		animal2.eat(); // pthuc eat() duoc ghi de o lop con
		animal3.eat(); // pthuc eat() duoc ghi de o lop con
		
		// da hinh tai runtime ko ap dung voi thuoc tinh
		System.out.println(animal1.name);
		System.out.println(animal2.name);
		System.out.println(animal3.name);
	}

}

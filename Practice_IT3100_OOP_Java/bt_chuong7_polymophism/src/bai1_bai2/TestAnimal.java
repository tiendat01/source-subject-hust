package bai1_bai2;

public class TestAnimal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// Using the subclasses
		Cat cat1 = new Cat();
		cat1.greeting();			// Meow!
		Dog dog1 = new Dog();
		dog1.greeting();			// Woof!
		BigDog bigDog1 = new BigDog();
		bigDog1.greeting();			// Woow!
		
		// Using Polymophism
		Animal animal1 = new Cat(); // upcasting
		animal1.greeting(); 		// Meow!
		Animal animal2 = new Dog(); 
		animal2.greeting();   		// Woof!
		Animal animal3 = new BigDog();
		animal3.greeting();			// Woow!
		
		//Animal animal4 = new Animal(); // cannot instantiate abstract class obj
	
		// Downcast
		Dog dog2 = (Dog)animal2; // true
		BigDog bigDog2 = (BigDog)animal3; // true
		Dog dog3 = (Dog)animal3; // true
		//Cat cat2 = (Cat)animal2; // false classCastException
		dog2.greeting(dog3);		// Wooooooof!
		dog3.greeting(dog2);		// Wooooooowww!
		dog2.greeting(bigDog2);		// Wooooooof!
		bigDog2.greeting(dog2);		// Wooooooowww!
		bigDog2.greeting(bigDog1);  // Wooooooowww! 
	}

}

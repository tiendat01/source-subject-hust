package bai2;
import java.awt.Graphics;

public class Cat extends Animal implements CanEat, CanDrink {
	public Cat() {
		// TODO Auto-generated constructor stub
	}
	
	public String getName() {
		System.out.println("Phuong thuc getName()");
		return super.name;	
	}
	
	public void back(Graphics g, int x, int y) {
		System.out.println("Phuong thuc back()");
	}
	
	public void getVelocity(Graphics g) {
		System.out.println("Phuong thuc getVelocity()");
	}
	
	public void eat() {
		System.out.println("Phuong thuc eat()");
	}
	
	public void drink() {
		System.out.println("Phuong thuc drink()");
	}

}

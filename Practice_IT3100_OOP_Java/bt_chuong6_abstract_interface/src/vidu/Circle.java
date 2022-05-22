package vidu;

import java.awt.Graphics;

public class Circle extends Shape implements Actable {
	private int radius;
	

	public Circle(String name, int x, int y, int radius) {
		// TODO Auto-generated constructor stub
		super(name, x, y);
		this.radius = radius;
	}

	@Override
	public void draw(Graphics g) {
		// TODO Auto-generated method stub

	}

	@Override
	public void moveTo(Graphics g, int x1, int y1) {
		// TODO Auto-generated method stub

	}

	@Override
	public void erase(Graphics g) {
		// TODO Auto-generated method stub

	}

	@Override
	public float calculateArea() {
		// TODO Auto-generated method stub
		return 0;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

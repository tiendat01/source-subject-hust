package vidu;

public abstract class Shape {
	protected String name;
	protected int x, y;

	public Shape(String name, int x, int y) {
		// TODO Auto-generated constructor stub
		this.name = name;
		this.x = x;
		this.y = y;
	}
	
	public String getName() { return name; }
	public abstract float calculateArea();
}

package practice_codelearn;

public class Triangle {
	private Point vertice1;
	private Point vertice2;
	private Point vertice3;
	public Triangle(Point vertice1, Point vertice2, Point vertice3) {
		super();
		this.vertice1 = vertice1;
		this.vertice2 = vertice2;
		this.vertice3 = vertice3;
	}
	
	public Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
		this.vertice1 = new Point(x1,y1);
		this.vertice2 = new Point(x2,y2);
		this.vertice3 = new Point(x3,y3);
	}
	
	public double getPerimeter() {
		return vertice1.getDistance(vertice2) + 
				vertice2.getDistance(vertice3) + 
				vertice3.getDistance(vertice1);
	}
}

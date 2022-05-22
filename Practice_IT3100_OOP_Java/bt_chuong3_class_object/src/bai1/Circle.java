package bai1;

public class Circle {
	private double radius;
	public double getRadius() {
		return radius;
	}
	public void setRadius(double radius) {
		if (radius < 0) {
			System.out.println("Do dai canh hinh vuong phai lon hon 0");
		}
		else {
			this.radius = radius;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
}

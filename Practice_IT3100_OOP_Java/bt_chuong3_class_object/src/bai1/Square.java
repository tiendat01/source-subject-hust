package bai1;

public class Square {
	private double size;
	
	public double getSize() {
		return size;
	}
	public void setSize(double size) {
		if (size < 0) {
			System.out.println("Do dai canh hinh vuong phai lon hon 0");
		}
		else {
			this.size = size;
		}
	}
	public static void main(String[] args) {
		Square h1 = new Square();
		h1.size = 40d;
		System.out.print(h1.getSize());
	}
}

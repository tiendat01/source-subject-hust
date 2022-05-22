package bai2;

public class Vector {
	private double x;
	private double y;
	private double z;
	
	// cong vector v1 voi v2, trong do tac dong den doi tuong v1
	public void addVector(Vector v2) {
		x = x + v2.x;
		y = y + v2.y;
		z = z + v2.z;
	}
	
	public void subVector(Vector v2) {
		x = x - v2.x;
		y = y - v2.y;
		z = z - v2.z;
	}
	
	public void multiConst(double c) {
		x = x * c;
		y = y * c;
		z = z * c;
	}
	
	public double multiScalaVector(Vector v2) {
		x = x * v2.x;
		y = y * v2.y;
		z = z * v2.z;
		return x + y + z;
	}
	
	public void setVector(int x, int y, int z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	public void getVectorInfo() {
		System.out.println(x + ", " + y + ", " + z);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector v1 = new Vector();
		Vector v2 = new Vector();
		v1.setVector(1, 2, 3);
		v2.setVector(4, 5, 6);
		
		v1.getVectorInfo();
		v1.addVector(v2);
		v1.getVectorInfo();
		v1.subVector(v2);
		v1.getVectorInfo();
	}
}

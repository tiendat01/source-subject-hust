package test1;

public class Main {
	
	static int x;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		x++;
		
		Shape t = new Shape() {

			@Override
			public String doSomething() {
				// TODO Auto-generated method stub
				return null;
			};
		
		}; // anonymous class/ subclass/ nested class
		t.num = 6;
		Vehicle x = new Vehicle(t);	
		x.getX();
	}

}

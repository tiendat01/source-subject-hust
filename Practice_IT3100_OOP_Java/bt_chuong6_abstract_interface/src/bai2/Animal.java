package bai2;

 abstract class Animal implements CanMove {
	protected String name;
	
	public Animal() {		
	}
	
	public void run() {
		System.out.println("Phuong thuc run()");
	}
	
}

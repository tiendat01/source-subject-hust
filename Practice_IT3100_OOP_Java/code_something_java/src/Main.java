
public class Main {
	
	public static void Try() {
		try {
			int i = Integer.parseInt("abd");
		} catch (NullPointerException e) { // bat ngoai le "truot"
			System.out.println("A");
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Try();
			
		} catch(Exception e) {
			System.out.println("b");
		}
	}

}

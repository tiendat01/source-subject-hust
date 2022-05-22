
public class Test1 {

	public static void delete(StringBuffer s) {
		s.delete(0, 1);
		System.out.print(s);
	}
	
	public static void delete1(StringBuffer s) {
		s = s.delete(0, 1);
		System.out.print(s);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StringBuffer s2 = new StringBuffer("CdE");
		delete(s2); delete(s2);
		System.out.print(s2);
	}

}

package bt_chuong9_ExceptionHandle;

class ExceptionTest {

	public static void main(String[] args) {
		int n = 0;
		int[] arr = new int[100];
		String filepath = "D:\\OneDrive - Hanoi University of Science and Technology\\Cacmon\\OOP\\Practice\\bt_chuong9_ExceptionHandle\\src\\bt_chuong9_ExceptionHandle\\file.txt";
		ReadFile rf = new ReadFile(n, arr);
		
		try {
			rf.readListIntegers(" ");
		} catch (ReadFileException e) {
			System.out.println(e.toString());
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

}

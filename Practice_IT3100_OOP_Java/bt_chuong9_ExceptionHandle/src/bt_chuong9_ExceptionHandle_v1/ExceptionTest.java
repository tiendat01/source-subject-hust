package bt_chuong9_ExceptionHandle_v1;

import java.io.FileNotFoundException;
import java.io.IOException;

import bt_chuong9_ExceptionHandle_v1.ReadFile;
import bt_chuong9_ExceptionHandle_v1.ReadFileException;

class ExceptionTest {

	public static void main(String[] args) {
		int n = 0;
		int[] arr = new int[100];
		String filepath = "D:\\OneDrive - Hanoi University of Science and Technology\\Cacmon\\OOP\\Practice\\bt_chuong9_ExceptionHandle\\src\\bt_chuong9_ExceptionHandle_v1\\file.txt";
		ReadFile rf = new ReadFile(n, arr);
		
		try {
			rf.readListIntegers(filepath);
		} catch (ReadFileException e) {
			System.out.println(e.toString());
		} catch (FileNotFoundException e) {
			System.out.println(e.toString());
		} catch (IOException e) {
			System.out.println(e.toString());
		} catch (NumberFormatException e) {
			System.out.println(e.toString());
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

}

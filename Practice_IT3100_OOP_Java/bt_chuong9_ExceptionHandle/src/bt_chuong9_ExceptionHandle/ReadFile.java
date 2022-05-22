package bt_chuong9_ExceptionHandle;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

class ReadFile {
	
	public int n;
	public int[] listInteger;
	
	public ReadFile(int n, int[] listInteger) {
		this.n = n;
		this.listInteger = listInteger;
	}
	
	public void readListIntegers(String fileName) 
		throws ReadFileException, IOException
	{
		if (fileName.equals("")) {
			throw new ReadFileException("Xau ten file la xau rong");
		}	
		
		File f = new File(fileName);
		
		try {
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			
			String line;
			while ((line = br.readLine()) != null) {
				try {
					listInteger[n] = Integer.parseInt(line);
				} catch (NumberFormatException e) {
					System.out.println("Du lieu trong file ko chuyen sang so nguyen duoc");
					System.out.println(e.toString());
					e.printStackTrace();
				}
				n++;
			}
		} catch(FileNotFoundException e) {
			System.out.println("File ko mo duoc hoac ko ton tai");
			System.out.println(e.toString());
			e.printStackTrace();
		}
		
	}
	
	public void print() {
		System.out.println("Ket qua:");
		for (int i = 0; i < n; i++) {
			System.out.print(listInteger[i] + ' ');
		}
	}

}

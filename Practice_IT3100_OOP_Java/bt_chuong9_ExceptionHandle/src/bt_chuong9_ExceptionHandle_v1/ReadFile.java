/* 
 * phien ban: 
 * cac phuong thuc khai bao exception, uy nhiem cho phuong thuc goi no ma ko bat ngoai le
*/




package bt_chuong9_ExceptionHandle_v1;

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
	
	public boolean isInteger(String s) {
		try { 
	        Integer.parseInt(s); 
	    } catch(NumberFormatException e) { 
	        return false; 
	    } catch(NullPointerException e) {
	        return false;
	    }
	    // only got here if we didn't return false
	    return true;
	}
	
	
	
	public void readListIntegers(String fileName) 
		throws ReadFileException, IOException
	{
		if (fileName.equals("")) {
			throw new ReadFileException("Xau ten file la x rong");
		}	
		
		File f = new File(fileName);
		
		if (!(f.exists())) {
			throw new FileNotFoundException("The file \"" + fileName + "\" does not exist");
		}
		if (!(f.isFile())) {
			throw new FileNotFoundException("The file \"" + fileName + "\" is not a normal file");
		}
		if (!(f.canRead())) {
			throw new FileNotFoundException("The file \"" + fileName + "\" is not readable");
		}
		
		FileReader fr = new FileReader(f);
		BufferedReader br = new BufferedReader(fr);
			
		String line;
		while ((line = br.readLine()) != null) {
			if (!(isInteger(line))) {
				throw new NumberFormatException("Du lieu trong file: \"" + line + "\" khong chuyen sang so nguyen duoc");
			}
			listInteger[n] = Integer.parseInt(line);
			n++;
		}
		
	}
	
	public void print() {
		System.out.println("Ket qua:");
		for (int i = 0; i < n; i++) {
			System.out.print(listInteger[i] + ' ');
		}
	}

}

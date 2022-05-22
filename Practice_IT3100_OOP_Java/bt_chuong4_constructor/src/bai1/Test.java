package bai1; 
import java.util.Scanner;

public class Test {	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);	
		String name;
		String author;
		int numberOfPage;
		String choice;
		int sumPage = 0;
		
		System.out.print("Nhap so phan tu cho mang Book: ");
		int n = sc.nextInt();
		sc.nextLine();
		
		Book book[] = new Book[n];		
		
		int i = 0;
		while (true) {
			System.out.print("Nhan phim '1' de nhap sach. Nhan phim # de ket thuc.");
			choice = sc.nextLine();
			if (choice.equals("1")) {
				System.out.println("Nhap cac thanh phan cua sach: ");
				System.out.print("Ten sach: "); name = sc.nextLine();
				System.out.print("Ten tac gia: "); author = sc.nextLine();
				System.out.print("So trang: "); 
				
//				numberOfPage = sc.nextInt(); // nextInt() khong nhan ky tu Enter \n nen phai co dong sau
//				sc.nextLine();
				// co the thay 2 dong tren bang dong sau:
				 numberOfPage = Integer.parseInt(sc.nextLine());
				book[i] = new Book(name, author, numberOfPage);
				sumPage += numberOfPage;
				i++;
			}
			else break;
		}

		System.out.println("Thong tin sach:");
		System.out.printf("%23s%20s%10s\n", "Ten sach", "Ten tac gia", "So trang");
		for (int j = 0; j < i; j++) {
			System.out.print(j + ". ");
			book[j].outputInfo();
		}
		
		System.out.println("Tong so trang cua cac Book: " + sumPage);
		System.out.println("So Book hien tai: " + i);
		
		sc.close();	
	}

}

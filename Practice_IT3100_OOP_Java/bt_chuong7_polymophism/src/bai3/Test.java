package bai3;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Product p1 = new ElectronicalApp("12345abc", "tu lanh", "datdz",
				20.5f, 36, 1000f, 5000f);
		Product p2 = new Crockery("12345def", "binh su", "datdz", 
				5.5f, "gom su");
		DateTimeFormatter format = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		String dateFrom = "22/06/2021";
		String dateTo = "30/06/2021";
		Product p3 = new Food("12345ghi", "sua tuoi", "datdz", 
				0.5f, LocalDate.parse(dateFrom, format), LocalDate.parse(dateTo, format));
		
		System.out.println(p1.toString());
		System.out.println(p2.toString());
		System.out.println(p3.toString());
	}

}

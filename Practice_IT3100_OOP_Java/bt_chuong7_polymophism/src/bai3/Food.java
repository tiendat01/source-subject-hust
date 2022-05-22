package bai3;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Food extends Product {
	private LocalDate ngaySanXuat;
	private LocalDate ngayHetHan;

	public Food() {
		// TODO Auto-generated constructor stub
	}

	public Food(String maHang, String tenHang, String nhaSanXuat, float gia, 
			LocalDate ngaySanXuat, LocalDate ngayHetHan) {
		super(maHang, tenHang, nhaSanXuat, gia);
		this.ngaySanXuat = ngaySanXuat;
		this.ngayHetHan = ngayHetHan;
	}

	public LocalDate getNgaySanXuat() {
		return ngaySanXuat;
	}

	public void setNgaySanXuat(LocalDate ngaySanXuat) {
		this.ngaySanXuat = ngaySanXuat;
	}

	public LocalDate getNgayHetHan() {
		return ngayHetHan;
	}

	public void setNgayHetHan(LocalDate ngayHetHan) {
		this.ngayHetHan = ngayHetHan;
	}

	@Override
	public String toString() {
		DateTimeFormatter format = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		return "Food [ngaySanXuat=" + format.format(ngaySanXuat) + ", ngayHetHan=" + format.format(ngayHetHan) + ", maHang=" + maHang + ", tenHang="
				+ tenHang + ", nhaSanXuat=" + nhaSanXuat + ", gia=" + gia + "]";
	}
	

}

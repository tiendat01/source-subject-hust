package bai3;

public class Crockery extends Product {
	private String loaiNguyenLieu;

	public Crockery() {
		// TODO Auto-generated constructor stub
	}

	public Crockery(String maHang, String tenHang, String nhaSanXuat, float gia, String loaiNguyenLieu) {
		super(maHang, tenHang, nhaSanXuat, gia);
		this.loaiNguyenLieu = loaiNguyenLieu;
	}

	public String getLoaiNguyenLieu() {
		return loaiNguyenLieu;
	}

	public void setLoaiNguyenLieu(String loaiNguyenLieu) {
		this.loaiNguyenLieu = loaiNguyenLieu;
	}

	@Override
	public String toString() {
		return "Crockery [loaiNguyenLieu=" + loaiNguyenLieu + ", maHang=" + maHang + ", tenHang=" + tenHang
				+ ", nhaSanXuat=" + nhaSanXuat + ", gia=" + gia + "]";
	}

	
}

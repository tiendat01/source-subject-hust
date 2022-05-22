package bai3;

public class Product {
	protected String maHang;
	protected String tenHang;
	protected String nhaSanXuat;
	protected float gia; // VND
	
	public Product() {
		super();
	}
	
	public Product(String maHang, String tenHang, String nhaSanXuat, float gia) {
		super();
		this.maHang = maHang;
		this.tenHang = tenHang;
		this.nhaSanXuat = nhaSanXuat;
		this.gia = gia;
	}
	
	public float getGia() {
		return gia;
	}

	public void setGia(float gia) {
		this.gia = gia;
	}

	public String getMaHang() {
		return maHang;
	}
	public void setMaHang(String maHang) {
		this.maHang = maHang;
	}
	public String getTenHang() {
		return tenHang;
	}
	public void setTenHang(String tenHang) {
		this.tenHang = tenHang;
	}
	public String getNhaSanXuat() {
		return nhaSanXuat;
	}
	public void setNhaSanXuat(String nhaSanXuat) {
		this.nhaSanXuat = nhaSanXuat;
	}
	@Override
	public String toString() {
		return "Produce [maHang=" + maHang + ", tenHang=" + tenHang + ", nhaSanXuat=" + nhaSanXuat + "]";
	}
}

package bai1;

public class NhanVien {
	public NhanVien() {
		super();
	}

	protected String tenNhanVien;
	protected double luongCoBan, heSoLuong;
	protected static final double LUONG_MAX = 1000000;
	
	// Constructor:
	public NhanVien(String tenNhanVien, double luongCoBan, double heSoLuong) {
		this.tenNhanVien = tenNhanVien;
		this.luongCoBan = luongCoBan;
		this.heSoLuong = heSoLuong;
	}

	public boolean tangHeSoLuong(double incValue) {
		if (luongCoBan * (heSoLuong + incValue) > LUONG_MAX) {
			System.out.println("Khong the tang!!!");
			return false;
		}
		System.out.println("Co the tang!!!");
		return true;
	}
	
	public double tinhLuong() {
		return luongCoBan * heSoLuong;
	}
	
	public void inTTin() {
		System.out.println("Ten nhan vien: " + tenNhanVien);
		System.out.println("Luong co ban: " + luongCoBan);
		System.out.println("He so luong: " + heSoLuong);
	}

	public String getTenNhanVien() {
		return tenNhanVien;
	}

	public void setTenNhanVien(String tenNhanVien) {
		this.tenNhanVien = tenNhanVien;
	}

	public double getLuongCoBan() {
		return luongCoBan;
	}

	public void setLuongCoBan(double luongCoBan) {
		this.luongCoBan = luongCoBan;
	}

	public double getHeSoLuong() {
		return heSoLuong;
	}

	public void setHeSoLuong(double heSoLuong) {
		this.heSoLuong = heSoLuong;
	}
	
//	public String getTenNhanVien() { return tenNhanVien; }
//	public void setTenNhanVien(String ten) { tenNhanVien = ten; }
//	
//	public double getLuongCoBan() { return luongCoBan; }
//	public void setLuongCoBan(double luong_co_ban) { luongCoBan = luong_co_ban; }
//	
//	public double getHeSoLuong() { return heSoLuong; }
//	public void setHeSoLuong(double he_so_luong) { heSoLuong = he_so_luong; }
	
}

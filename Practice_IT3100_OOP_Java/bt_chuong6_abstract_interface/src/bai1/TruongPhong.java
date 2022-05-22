package bai1;

public class TruongPhong extends NhanVien {
	private double phuCap;
	private int soNamDuongChuc;
	
	public TruongPhong(){
		super();
	}
	
	public TruongPhong(String tenNhanVien, double luongCoBan, double heSoLuong, double phuCap, int soNamDuongChuc) {
		super(tenNhanVien, luongCoBan, heSoLuong);
		this.phuCap = phuCap;
		this.soNamDuongChuc = soNamDuongChuc;
	}
	
	public double tinhLuong() {
		return luongCoBan * heSoLuong + phuCap;
	}
	
	public void inTTin() {
		super.inTTin();
		System.out.println("Phu cap: " + phuCap);
		System.out.println("So nam duong chuc: " + soNamDuongChuc);
	}
}

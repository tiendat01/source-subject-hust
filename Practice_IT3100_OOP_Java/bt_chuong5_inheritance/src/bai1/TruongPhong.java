package bai1;

class TruongPhong extends NhanVien {
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
	
	
}

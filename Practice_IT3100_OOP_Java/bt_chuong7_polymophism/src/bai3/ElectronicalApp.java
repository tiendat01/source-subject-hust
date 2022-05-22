package bai3;

public class ElectronicalApp extends Product {
	private int thoiGianBaoHanh; // thang
	private float dienAp; // V
	private float congSuat; // W

	public ElectronicalApp() {
		// TODO Auto-generated constructor stub
	}

	public ElectronicalApp(String maHang, String tenHang, String nhaSanXuat, float gia, int thoiGianBaoHanh, float dienAp, float congSuat) {
		super(maHang, tenHang, nhaSanXuat, gia);
		this.thoiGianBaoHanh = thoiGianBaoHanh;
		this.dienAp = dienAp;
		this.congSuat = congSuat;
	}

	public int getThoiGianBaoHanh() {
		return thoiGianBaoHanh;
	}

	public void setThoiGianBaoHanh(int thoiGianBaoHanh) {
		this.thoiGianBaoHanh = thoiGianBaoHanh;
	}

	public float getDienAp() {
		return dienAp;
	}

	public void setDienAp(float dienAp) {
		this.dienAp = dienAp;
	}

	public float getCongSuat() {
		return congSuat;
	}

	public void setCongSuat(float congSuat) {
		this.congSuat = congSuat;
	}

	@Override
	public String toString() {
		return "ElectronicalApp [thoiGianBaoHanh=" + thoiGianBaoHanh + ", dienAp=" + dienAp + ", congSuat=" + congSuat
				+ ", maHang=" + maHang + ", tenHang=" + tenHang + ", nhaSanXuat=" + nhaSanXuat + ", gia=" + gia + "]";
	}

	

}

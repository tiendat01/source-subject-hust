package bai2;

public class TestNV {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		NhanVien nv1 = new NhanVien("Hung", 500000.0, 1.5);
		NhanVien nv2 = new NhanVien("Nam", 500000.0, 1.9);
		
		System.out.println("Thong tin nhan vien: \nNhan vien 1: ");
		nv1.inTTin();
		System.out.println("Hien thi Luong: " + nv1.tinhLuong());
		nv1.tangLuong(0.3);
		
		System.out.println("Nhan vien 2: ");
		nv2.inTTin();
		System.out.println("Hien thi Luong: " + nv2.tinhLuong());
		nv2.tangLuong(0.3);
		
		int n = 2;
		NhanVien[] nv = new NhanVien[2];
		nv[0] = nv1;
		nv[1] = nv2;
		System.out.println("Tong luong cua cac nhan vien trong mang: " + 
		tongLuong(nv));
	}
	
	public static double tongLuong(NhanVien NV[]) {
		double sum = 0;
		for (int i = 0; i < NV.length; i++) {
			sum += NV[i].tinhLuong();
		}
		return sum;
	}

}

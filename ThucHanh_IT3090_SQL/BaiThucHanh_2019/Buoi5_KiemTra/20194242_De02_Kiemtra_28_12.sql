-- Bài kiểm tra 28-12 Đề 02
-- Nguyễn Tiến Đạt - 20194242
-- 1. Tạo cơ sở dữ liệu quản lý bán hàng với các bảng trên (Khóa chính, khóa ngoại, diagram) (1 điểm)

--create database De02_NguyenTienDat;

--use De02_NguyenTienDat;

--create table DAILY_DatNT (
--	MADL_4242 varchar(10) not null primary key,
--	TENDAILY_4242 nvarchar(30) not null,
--	DIACHI_4242 nvarchar(30),
--	DIENTHOAI_4242 nvarchar(10),
--	EMAIL_4242 nvarchar(50)

--);

--create table SANPHAM_DatNT (
--	MASP_4242 varchar(10) not null primary key,
--	TENSP_4242 nvarchar(30) not null,
--	DONGIA_4242 real not null
--);

--create table HOADONXUAT_DatNT (
--	MAHD_4242 varchar(10) not null primary key,
--	MADL_4242 varchar(10) not null,
--	NGAYLAPHD_4242 date not null,
--	SOTIENTT_4242 real not null,
--	constraint hdx_fkey foreign key(MADL_4242) references DAILY_DatNT(MADL_4242)

--);

--create table CHITIETHDXUAT_DatNT (
--	MAHD_4242 varchar(10) not null,
--	MASP_4242 varchar(10) not null,
--	SOLUONG_4242 int not null,
--	constraint chitiet_pkey primary key(MAHD_4242, MASP_4242),
--	foreign key(MAHD_4242) references HOADONXUAT_DatNT(MAHD_4242),
--	foreign key(MASP_4242) references SANPHAM_DatNT(MASP_4242)

--);


----2. Hãy thực hiện các ràng buộc toàn vẹn sau (1 điểm)
----2.1 Đại lý: với email là: *@gmail.com.
--alter table DAILY_DatNT 
--add constraint email_chk check(EMAIL_4242 like N'%@gmail.com');

---- 2.2 Sản phẩm: với đơn giá từ 300 đến 2500
--alter table SANPHAM_DatNT 
--add constraint dongia_chk check(DONGIA_4242 >= 300 and DONGIA_4242 <= 2500);

----2.3 Chi tiết hóa đơn xuất: số lượng từ từ 2 đến 15.
--alter table CHITIETHDXUAT_DatNT
--add constraint soluong_chk check(SOLUONG_4242 between 2 and 15);

----3.Nhập dữ liệu vào các bảng (Theo trang 2). (2.5 điểm)
--insert into DAILY_DatNT (MADL_4242, TENDAILY_4242, EMAIL_4242, DIENTHOAI_4242, DIACHI_4242)
--values
--('DL0001', N'CAFE HOANGNAM', N'namhv@gmail.com', N'0914556677', N'123, Hoàn Kiếm'),
--('DL0002', N'CAFE NAMANH', N'anhtn@gmail.com', N'0912667788', N'146, Ba Đình, Hà Nội'),
--('DL0003', N'TRÀ SỮA BINHAN', N'annb@gmail.com', N'0915334455', N'154, Quang Trung, Nghệ An'),
--('DL0004', N'CAFE MINHLONG', N'longlm@gmail.com', N'0913224455', N'32, Võ Thị sáu, TP HCM'),
--('DL0005', N'TRÀ SỮA ANHVU', N'anhvm@gmail.com', N'0918336677', N'56, Yết Kiêu, Hà Nội'),
--('DL0006', N'Cafe HoaMai', N'hoamai@gmail.com', N'0915227788', N'Hải phòng');

--insert into SANPHAM_DatNT (MASP_4242, TENSP_4242, DONGIA_4242)
--values
--('BMM018', N'Máy pha Cafe Hafele HE', 2445),
--('EMF205', N'Máy đánh sữa Delonghi', 1949),
--('KCFCS2', N'Máy pha Cafe KONKA', 549),
--('SM3016', N'Máy xay Cafe SOKANY', 350),
--('TA02N1', N'Máy pha Cafe Bear 240ml', 1250),
--('TS0530', N'Máy xay Cafe Tiross 150W', 519);

--insert into HOADONXUAT_DatNT (MAHD_4242, MADL_4242, NGAYLAPHD_4242, SOTIENTT_4242)
--values
--('HD0001', 'DL0005', '2021-10-11', 12340),
--('HD0002', 'DL0002', '2021-10-15', 15678),
--('HD0003', 'DL0002', '2021-10-20', 12300),
--('HD0004', 'DL0004', '2021-10-25', 7689),
--('HD0005', 'DL0004', '2021-12-05', 5790),
--('HD0006', 'DL0005', '2021-12-20', 13566),
--('HD0007', 'DL0005', '2021-11-20', 1000),
--('HD0008', 'DL0003', '2021-12-15', 2000);

--insert into CHITIETHDXUAT_DatNT(MAHD_4242, MASP_4242, SOLUONG_4242)
--values
--('HD0001', 'BMM018', 3),
--('HD0001', 'EMF205', 5),
--('HD0001', 'KCFCS2', 3),
--('HD0001', 'TA02N1', 5),
--('HD0001', 'TS0530', 2),
--('HD0002', 'EMF205', 7),
--('HD0002', 'KCFCS2', 6),
--('HD0002', 'SM3016', 7),
--('HD0002', 'TA02N1', 4),
--('HD0003', 'KCFCS2', 5),
--('HD0003', 'SM3016', 4),
--('HD0003', 'TS0530', 6),
--('HD0004', 'BMM018', 5),
--('HD0004', 'TA02N1', 8),
--('HD0004', 'TS0530', 8),
--('HD0005', 'BMM018', 4),
--('HD0005', 'KCFCS2', 10),
--('HD0005', 'SM3016', 12),
--('HD0006', 'SM3016', 3),
--('HD0006', 'TA02N1', 3),
--('HD0006', 'TS0530', 5),
--('HD0007', 'SM3016', 10),
--('HD0007', 'TA02N1', 5),
--('HD0008', 'BMM018', 4),
--('HD0008', 'KCFCS2', 6);

--4.1 Đưa ra mã đại lý, tên đại lý, số hóa đơn, tổng tiền phải thanh toán, của các đại lý có địa
--chỉ là Hà Nội và TP HCM trong tháng 10,11/2021.
select DAILY_DatNT.MADL_4242, TENDAILY_4242, COUNT(MAHD_4242) as SOHOADON, sum(SOTIENTT_4242) as TONGTIENTT
from DAILY_DatNT, HOADONXUAT_DatNT
where DAILY_DatNT.MADL_4242 = HOADONXUAT_DatNT.MADL_4242 
and (DIACHI_4242 like N'%Hà Nội' or DIACHI_4242 like N'%TP HCM')
and (YEAR(NGAYLAPHD_4242) = 2021) and (MONTH(NGAYLAPHD_4242) = 11 or MONTH(NGAYLAPHD_4242) = 10)
group by DAILY_DatNT.MADL_4242, TENDAILY_4242;

--4.2 Đưa ra Sản phẩm bán thu được số tiền cao nhất với các thông tin: mã sản phẩm, tên sản phẩm, số lượng, thành tiền trong năm 2021. 
--trong đó tiền thành tiền bằng số lượng *đơn giá.
select TOP 1 SANPHAM_DatNT.MASP_4242, TENSP_4242, sum(SOLUONG_4242) as SOLUONG, (sum(SOLUONG_4242) * DONGIA_4242) as THANHTIEN   
from SANPHAM_DatNT, CHITIETHDXUAT_DatNT
where SANPHAM_DatNT.MASP_4242 = CHITIETHDXUAT_DatNT.MASP_4242
group by SANPHAM_DatNT.MASP_4242, TENSP_4242, DONGIA_4242
order by THANHTIEN Desc;

--4.3 . Đưa ra danh sách Đại lý có tổng số lượng sản phẩm đã mua >=10, với các thông tin:
--Mã đại lý, tên đại lý, tổng số sản phẩm, tổng tiền phải thanh toán trong năm 2021.
select MADL_4242, TENDAILY_4242, sum(tongsp) as tongsp, sum(SOTIENTT_4242) as thanhtien
from (
select DAILY_DatNT.MADL_4242, TENDAILY_4242, sum(SOLUONG_4242) as tongsp, SOTIENTT_4242
from DAILY_DatNT, CHITIETHDXUAT_DatNT, SANPHAM_DatNT, HOADONXUAT_DatNT
where DAILY_DatNT.MADL_4242 = HOADONXUAT_DatNT.MADL_4242 and HOADONXUAT_DatNT.MAHD_4242 = CHITIETHDXUAT_DatNT.MAHD_4242
and SANPHAM_DatNT.MASP_4242 = CHITIETHDXUAT_DatNT.MASP_4242 and YEAR(NGAYLAPHD_4242) = 2021
group by DAILY_DatNT.MADL_4242, TENDAILY_4242, SOTIENTT_4242 having sum(SOLUONG_4242) >= 10) as tmp

group by MADL_4242, TENDAILY_4242;

--5. Tạo Store procedure với các yêu cầu sau: (2 điểm)
--5.1 Thao tác select các sản phẩm có tên “….pha Cafe…”
drop proc f51;
go
create proc f51 
as begin
select * from SANPHAM_DatNT where TENSP_4242 like N'%pha Cafe%';
end;

exec f51;

--5.2 Thao tác insert bảng Đại lý với các dữ liệu như sau:
--(DL0011, Cafe HoaMai, hoamai@gmail.com, 0915227788, 123 -Đồ sơn -Hải phòng ,)
drop proc f52;
go 
create proc f52 (
@MADL varchar(10), @TENDL nvarchar(30), @EMAIL nvarchar(30), @PHONE nvarchar(10), @DIACHI nvarchar(50)
) as begin
	insert into DAILY_DatNT(MADL_4242, TENDAILY_4242, EMAIL_4242, DIENTHOAI_4242, DIACHI_4242) 
	values (@MADL, @TENDL, @EMAIL, @PHONE, @DIACHI);
end

exec f52 'DL0011', N'Cafe HoaMai', N'hoamai@gmail.com', N'0915227788', N'123 -Đồ sơn -Hải phòng';

-- 5.3 Thao tác select thông tin về Đại lý có địa chỉ ở Hà Nội hoặc TP HCM. Với các thông
--mã đại lý, tên đại lý, tổng số số lượng của sản phẩm, tổng tiền phải thanh toán của tháng
--11 năm 2021.

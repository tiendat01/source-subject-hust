-- Bai Thực hành số 3:
-- Nguyễn Tiến Đạt - 20194242
use QLBongDa_DatNT_4242;

-- a, Xử lý chuỗi, ngày giờ
-- 1. Cho biết NGAYTD, TENCLB1, TENCLB2, KETQUA các trận đấu diễn ra vào tháng 3 trên sân
-- nhà mà không bị thủng lưới.
select NGAYTD_4242, c1.TENCLB_4242, c2.TENCLB_4242, KETQUA_4242
from TRANDAU_DatNT, CAULACBO_DatNT as c1, CAULACBO_DatNT as c2
where c1.MACLB_4242 = TRANDAU_DatNT.MACLB1_4242
and c2.MACLB_4242 = TRANDAU_DatNT.MACLB2_4242
and SUBSTRING(KETQUA_4242, CHARINDEX('-', KETQUA_4242) + 1, LEN(KETQUA_4242) - CHARINDEX('-', KETQUA_4242)) = '0' -- coi số thứ hai là số bàn thắng của đội khách, đội khách là clb2
and MONTH(NGAYTD_4242) = 3;
-- cách 2:
select NGAYTD_4242, c1.TENCLB_4242, c2.TENCLB_4242, KETQUA_4242
from TRANDAU_DatNT, CAULACBO_DatNT as c1, CAULACBO_DatNT as c2
where c1.MACLB_4242 = TRANDAU_DatNT.MACLB1_4242
and c2.MACLB_4242 = TRANDAU_DatNT.MACLB2_4242
and KETQUA_4242 like N'%-0'
and MONTH(NGAYTD_4242) = 3;

-- 2. Cho biết mã số, họ tên, ngày sinh của những cầu thủ có họ lót là “Công”
select MACT_4242, HOTEN_4242, DAY(NGAYSINH_4242) as "DAY"
from CAUTHU_DatNT
where SUBSTRING(
HOTEN_4242, 
LEN(HOTEN_4242) - CHARINDEX(' ', REVERSE(HOTEN_4242), CHARINDEX(' ', REVERSE(HOTEN_4242)) + 1) + 2,
CHARINDEX(' ', REVERSE(HOTEN_4242), CHARINDEX(' ', REVERSE(HOTEN_4242)) + 1) - CHARINDEX(' ', REVERSE(HOTEN_4242))
) = N'Công';
-- cách 2:
select MACT_4242, HOTEN_4242, DAY(NGAYSINH_4242) as "DAY"
from CAUTHU_DatNT
where HOTEN_4242 like N'% Công %';

-- 3. Cho biết mã số, họ tên, ngày sinh của những cầu thủ có họ không phải là họ “Nguyễn “
select MACT_4242, HOTEN_4242, DAY(NGAYSINH_4242) as "DAY"
from CAUTHU_DatNT
where CHARINDEX(' ', HOTEN_4242) = 0
or CHARINDEX(' ', HOTEN_4242) > 0
and SUBSTRING(
HOTEN_4242, 1 ,
CHARINDEX(' ', HOTEN_4242) - 1
) <> N'Nguyễn';
-- cách 2:
select MACT_4242, HOTEN_4242, DAY(NGAYSINH_4242) as "DAY"
from CAUTHU_DatNT
where HOTEN_4242 not like N'Nguyễn%';

-- 4. Cho biết mã huấn luyện viên, họ tên, ngày sinh, đ ịa chỉ của những huấn luyện viên Việt
-- Nam có tuổi nằm trong khoảng 35-60
select MAHLV_4242, TENHLV_4242, DAY(NGAYSINH_4242) as "Ngày sinh", DIACHI_4242
from HUANLUYENVIEN_DatNT, QUOCGIA_DatNT
where HUANLUYENVIEN_DatNT.MAQG_4242 = QUOCGIA_DatNT.MAQG_4242
and YEAR(GETDATE()) - YEAR(NGAYSINH_4242) between 35 and 60;

-- 5. Cho biết tên câu lạc bộ có huấn luyện viên trưởng sinh vào ngày 20 tháng 5
select TENCLB_4242
from CAULACBO_DatNT, HLV_CLB_DatNT, HUANLUYENVIEN_DatNT
where CAULACBO_DatNT.MACLB_4242 = HLV_CLB_DatNT.MACLB_4242
and HUANLUYENVIEN_DatNT.MAHLV_4242 = HLV_CLB_DatNT.MAHLV_4242
and VAITRO_4242 = N'HLV Chính'
and MONTH(NGAYSINH_4242) = 5
and DAY(NGAYSINH_4242) = 20;

-- 6. Cho biết tên câu lạc bộ, tên tỉnh mà CLB đang đóng có số bàn thắng nhiều nhất tính đến
--hết vòng 3 năm 2009
select top 1 TENCLB_4242, TENTINH_4242 ,SUM(CONVERT(INT, SUBSTRING(HIEUSO_4242, 1, CHARINDEX('-', HIEUSO_4242) - 1) ) ) as "SỐ BÀN THẮNG"
from CAULACBO_DatNT, BANGXH_DatNT, TINH_DatNT
where CAULACBO_DatNT.MACLB_4242 = BANGXH_DatNT.MACLB_4242
and CAULACBO_DatNT.MATINH_4242 = TINH_DatNT.MATINH_4242
and VONG_4242 <= 3 and NAM_4242 = 2009
group by TENCLB_4242, TENTINH_4242
order by SUM(CONVERT(INT, SUBSTRING(HIEUSO_4242, 1, CHARINDEX('-', HIEUSO_4242) - 1) ) ) desc;

----- Dung bang tran dau

select top 1 TENCLB_4242, TENTINH_4242 
from CAULACBO_DatNT, TINH_DatNT, 
(
(select MACLB_4242, SUM(convert(INT, SUBSTRING(KETQUA_4242, 1, CHARINDEX('-', KETQUA_4242)-1))) as "SUM"
from TRANDAU_DatNT, CAULACBO_DatNT
where MACLB_4242 = TRANDAU_DatNT.MACLB1_4242
and VONG_4242 <= 3
group by MACLB_4242)
union
(select MACLB_4242, SUM(convert(INT, SUBSTRING(KETQUA_4242, CHARINDEX('-', KETQUA_4242)+1, LEN(KETQUA_4242) - CHARINDEX('-', KETQUA_4242) + 1))) as "SUM"
from TRANDAU_DatNT, CAULACBO_DatNT
where MACLB_4242 = TRANDAU_DatNT.MACLB2_4242
and VONG_4242 <= 3
group by MACLB_4242)
) as "TONG"
where CAULACBO_DatNT.MATINH_4242 = TINH_DatNT.MATINH_4242
and TONG.MACLB_4242 = CAULACBO_DatNT.MACLB_4242
group by TENCLB_4242, TENTINH_4242
order by SUM("TONG"."SUM") desc;


--b. Truy vấn con
--1. Cho biết mã câu lạc bộ, tên câu lạc bộ, tên sân vận động, địa chỉ và số lượng cầu thủ nước
--ngoài (Có quốc tịch khác “Việt Nam”) tương ứng của các câu lạc bộ có nhiều hơn 2 cầu
--thủ nước ngoài.
SELECT CAULACBO_DatNT.MACLB_4242, TENCLB_4242, TENSAN_4242, SANVD_DatNT.DIACHI_4242, COUNT(*) AS SOCAUTHUNGOAI
FROM (((CAULACBO_DatNT
INNER JOIN SANVD_DatNT ON CAULACBO_DatNT.MASAN_4242 = SANVD_DatNT.MASAN_4242)
INNER JOIN CAUTHU_DatNT ON CAULACBO_DatNT.MACLB_4242 = CAUTHU_DatNT.MACLB_4242)
INNER JOIN QUOCGIA_DatNT ON CAUTHU_DatNT.MAQG_4242 = QUOCGIA_DatNT.MAQG_4242)
WHERE TENQG_4242 <> N'Việt Nam'
GROUP BY CAULACBO_DatNT.MACLB_4242, TENCLB_4242, TENSAN_4242, SANVD_DatNT.DIACHI_4242 HAVING COUNT(*) > 2;

-- 2. Cho biết tên câu lạc bộ, tên tỉnh mà CLB đang đóng có hiệu số bàn thắng bại cao nhất
--năm 2009.
select top 1 TENCLB_4242, TENTINH_4242, SUM(
CONVERT(INT, SUBSTRING(HIEUSO_4242, 1, CHARINDEX('-', HIEUSO_4242) - 1) ) 
- CONVERT(INT, 
SUBSTRING(HIEUSO_4242, 
CHARINDEX('-', HIEUSO_4242)+1, 
LEN(HIEUSO_4242)-CHARINDEX('-', HIEUSO_4242)
) ) ) as "HIỆU SỐ"
from CAULACBO_DatNT, BANGXH_DatNT, TINH_DatNT
where CAULACBO_DatNT.MACLB_4242 = BANGXH_DatNT.MACLB_4242
and CAULACBO_DatNT.MATINH_4242 = TINH_DatNT.MATINH_4242
and NAM_4242 = 2009
group by TENCLB_4242, TENTINH_4242
order by SUM(
CONVERT(INT, SUBSTRING(HIEUSO_4242, 1, CHARINDEX('-', HIEUSO_4242) - 1) ) 
- CONVERT(INT, 
SUBSTRING(HIEUSO_4242, 
CHARINDEX('-', HIEUSO_4242)+1, 
LEN(HIEUSO_4242)-CHARINDEX('-', HIEUSO_4242)
) ) ) desc;

--3. Cho biết danh sách các trận đấu ( NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA) của
--câu lạc bộ CLB có thứ hạng thấp nhất trong bảng xếp hạng vòng 3 năm 2009.
select NGAYTD_4242, TENSAN_4242, c1.TENCLB_4242, c2.TENCLB_4242, KETQUA_4242
from TRANDAU_DatNT, CAULACBO_DatNT c1, CAULACBO_DatNT c2, SANVD_DatNT
where TRANDAU_DatNT.MACLB1_4242 = c1.MACLB_4242
and TRANDAU_DatNT.MACLB2_4242 = c2.MACLB_4242
and TRANDAU_DatNT.MASAN_4242 = SANVD_DatNT.MASAN_4242
and ( select top 1 MACLB_4242
from BANGXH_DatNT
where VONG_4242 = 3 and NAM_4242 = 2009
order by HANG_4242 desc) in (TRANDAU_DatNT.MACLB1_4242, TRANDAU_DatNT.MACLB2_4242);

-- 4. Cho biết mã câu lạc bộ, tên câu lạc bộ đã tham gia thi đấu với tất cả các câu lạc bộ còn lại
--(kể cả sân nhà và sân khách) trong mùa giải năm 2009.
select MACLB_4242, TENCLB_4242
from CAULACBO_DatNT where MACLB_4242 in
(select MACLB_4242 from CAULACBO_DatNT clb where 
(select COUNT(MATRAN_4242) from TRANDAU_DatNT where 
clb.MACLB_4242 = TRANDAU_DatNT.MACLB1_4242 or clb.MACLB_4242 = TRANDAU_DatNT.MACLB2_4242
and NAM_4242 = 2009)
>= 
(select COUNT(MACLB_4242) from CAULACBO_DatNT) - 1);

-- 5. Cho biết mã câu lạc bộ, tên câu lạc bộ đã tham gia thi đấu với tất cả các câu lạc bộ còn lại
--( chỉ tính sân nhà) tro ng mùa giải năm 2009.
select MACLB_4242, TENCLB_4242
from CAULACBO_DatNT where MACLB_4242 in
(select MACLB_4242 from CAULACBO_DatNT clb where 
(select COUNT(MATRAN_4242) from TRANDAU_DatNT where clb.MACLB_4242 = TRANDAU_DatNT.MACLB1_4242
and NAM_4242 = 2009)
>= 
(select COUNT(MACLB_4242) from CAULACBO_DatNT) - 1);


-- c. Bài tập về Rule
--1. Khi thêm cầu thủ mới, kiểm tra vị trí trên sân của cầu thủ chỉ thuộc một trong các vị trí
--sau: Thủ môn, tiền đạo, tiền vệ, trung vệ, hậu vệ.
alter table CAUTHU_DatNT drop constraint chk_vitri;
alter table CAUTHU_DatNT add constraint chk_vitri 
check(VITRI_4242 in (N'Thủ môn', N'Tiền đạo', N'Tiền vệ', N'Trung vệ', N'Hậu vệ'));

--2. Khi phân công huấn luyện viên, kiểm tra vai trò của huấn luyện viên chỉ thuộc một trong
--các vai trò sau: HLV chính, HLV phụ, HLV thể lực, HLV thủ môn
alter table HLV_CLB_DatNT drop constraint chk_vaitrohlv;
alter table HLV_CLB_DatNT add constraint chk_vaitrohlv
check(VAITRO_4242 in(N'HLV chính', N'HLV phụ',N'HLV thể lực',N'HLV thủ môn'));

-- 3. Khi thêm cầu thủ mới, kiểm tra cầu thủ đó có tuổi phải đủ 18 trở lên (chỉ tính năm sinh)
alter table CAUTHU_DatNT drop constraint chk_tuoi;
alter table CAUTHU_DatNT add constraint chk_tuoi
check(year(getdate()) - year(NGAYSINH_4242) >= 18);

-- 4. Kiểm tra kết quả trận đấu có dạng số_bàn_thắng-số_bàn_thua
alter table TRANDAU_DatNT drop constraint chk_tiso;
alter table TRANDAU_DatNT add constraint chk_tiso
check(KETQUA_4242 like '%-%');


 --d) Bài tập về View
--1. Cho biết mã số, họ tên, ngày sinh, địa chỉ và vị trí của các cầu thủ thuộc đội bóng “SHB
--Đà Nẵng” có quốc tịch “Bra-xin”
drop view d1;
go
create view d1
as
select MACT_4242, HOTEN_4242, NGAYSINH_4242, DIACHI_4242, VITRI_4242
from CAUTHU_DatNT, CAULACBO_DatNT, QUOCGIA_DatNT
where CAUTHU_DatNT.MACLB_4242 = CAULACBO_DatNT.MACLB_4242
and CAUTHU_DatNT.MAQG_4242 = QUOCGIA_DatNT.MAQG_4242
and TENCLB_4242 = N'SHB Đà Nẵng'
and TENQG_4242 = N'Bra-xin';
go 
select * from d1;

--2. Cho biết kết quả (MATRAN, NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA) các trận
--đấu vòng 3 của mùa bóng năm 2009.
drop view d2
go
create view d2
as
select MATRAN_4242, NGAYTD_4242, TENSAN_4242, c1.TENCLB_4242 as clb1, c2.TENCLB_4242 as clb2, KETQUA_4242
from TRANDAU_DatNT, SANVD_DatNT, CAULACBO_DatNT c1, CAULACBO_DatNT c2
where VONG_4242 = 3 and NAM_4242 = 2009
and TRANDAU_DatNT.MACLB1_4242 = c1.MACLB_4242 and TRANDAU_DatNT.MACLB2_4242 = c2.MACLB_4242
and TRANDAU_DatNT.MASAN_4242 = SANVD_DatNT.MASAN_4242;
go
select * from d2;

-- 3. Cho biết mã huấn luyện viên, họ tên, ngày sinh, địa chỉ, vai trò và tên CLB đang làm việc
--của các huấn luyện viên có quốc tịch “Việt Nam”
drop view d3;
go
create view d3
as
select HUANLUYENVIEN_DatNT.MAHLV_4242, TENHLV_4242, NGAYSINH_4242, DIACHI_4242, VAITRO_4242, TENCLB_4242
from HLV_CLB_DatNT, HUANLUYENVIEN_DatNT, QUOCGIA_DatNT, CAULACBO_DatNT
where HUANLUYENVIEN_DatNT.MAHLV_4242 = HLV_CLB_DatNT.MAHLV_4242
and HLV_CLB_DatNT.MACLB_4242 = CAULACBO_DatNT.MACLB_4242
and HUANLUYENVIEN_DatNT.MAQG_4242 = QUOCGIA_DatNT.MAQG_4242
and TENQG_4242 = N'Việt Nam';
go
select * from d3;

-- 4. Cho biết mã câu lạc bộ, tên câu lạc bộ, tên sân vận động, địa chỉ và số lượng cầu thủ
--nước ngoài (có quốc tịch khác “Việt Nam”) tương ứng của các câu lạc bộ nhiều hơn 2
--cầu thủ nước ngoài
drop view d4;
go
create view d4
as
select CAULACBO_DatNT.MACLB_4242, TENCLB_4242, TENSAN_4242, SANVD_DatNT.DIACHI_4242, COUNT(*) as SOLUONGCAUTHUNGOAI
from CAULACBO_DatNT, SANVD_DatNT, QUOCGIA_DatNT, CAUTHU_DatNT
where CAULACBO_DatNT.MACLB_4242 = CAUTHU_DatNT.MACLB_4242
and CAULACBO_DatNT.MASAN_4242 = SANVD_DatNT.MASAN_4242
and CAUTHU_DatNT.MAQG_4242 = QUOCGIA_DatNT.MAQG_4242
and TENQG_4242 <> N'Việt Nam'
group by CAULACBO_DatNT.MACLB_4242, TENCLB_4242, TENSAN_4242, SANVD_DatNT.DIACHI_4242
having COUNT(*)  >  2;
go
select * from d4;

-- 5. Cho biết tên tỉnh, số lượng câu thủ đang thi đấu ở vị trí tiền đạo trong các câu lạc bộ
--thuộc địa bàn tỉnh đó quản lý.
drop view d5;
go
create view d5
as
select TENTINH_4242, COUNT(*) as "Số cầu thủ thi đấu"
from TINH_DatNT, CAUTHU_DatNT, CAULACBO_DatNT
where TINH_DatNT.MATINH_4242 = CAULACBO_DatNT.MATINH_4242
and CAUTHU_DatNT.MACLB_4242 = CAULACBO_DatNT.MACLB_4242
and VITRI_4242 = N'Tiền đạo'
group by TENTINH_4242;
go
select * from d5;

-- 6. Cho biết tên câu lạc bộ,tên tỉnh mà CLB đang đóng nằm ở vị trí cao nhất của bảng xếp
--hạng của vòng 3 năm 2009
drop view d6;
go
create view d6
as
select top 1 TENCLB_4242, TENTINH_4242
from CAULACBO_DatNT, TINH_DatNT, BANGXH_DatNT
where CAULACBO_DatNT.MACLB_4242 = BANGXH_DatNT.MACLB_4242
and CAULACBO_DatNT.MATINH_4242 = TINH_DatNT.MATINH_4242
and VONG_4242 = 3 and NAM_4242 = 2009
order by HANG_4242;
go
select * from d6;

-- 7. Cho biết tên huấn luyện viên đang nắm giữ một vị trí trong 1 c âu lạc bộ mà chưa có số
--điện thoại
drop view d7;
go
create view d7
as
select TENHLV_4242
from HUANLUYENVIEN_DatNT
where MAHLV_4242 in (select MAHLV_4242 from HLV_CLB_DatNT)
and DIENTHOAI_4242 is null;
go
select * from d7;

-- 8. Liệt kê các huấn luyện viên thuộc quốc gia Việt Nam chưa làm công tác huấn luyện tại bất
--kỳ một câu lạc b ộ nào
drop view d8;
go
create view d8
as
select MAHLV_4242, TENHLV_4242
from HUANLUYENVIEN_DatNT, QUOCGIA_DatNT
where MAHLV_4242 not in (select MAHLV_4242 from HLV_CLB_DatNT)
and HUANLUYENVIEN_DatNT.MAQG_4242 = QUOCGIA_DatNT.MAQG_4242
and TENQG_4242 = N'Việt Nam';
go
select * from d8;

-- 9. Cho biết kết quả các trận đấu đã diễn ra (MACLB1, MACLB2, NAM, VONG,
--SOBANTHANG,SOBANTHUA)
drop view d9;
go
create view d9
as
select c1.MACLB_4242 clb1, c2.MACLB_4242 clb2, NAM_4242, VONG_4242,
SUBSTRING(KETQUA_4242, 1, CHARINDEX('-', KETQUA_4242)-1) as SOBANTHANG1,
SUBSTRING(KETQUA_4242, CHARINDEX('-', KETQUA_4242)+1, LEN(KETQUA_4242)-CHARINDEX('-', KETQUA_4242)+1) as SOBANTHANG2
from CAULACBO_DatNT c1, CAULACBO_DatNT c2, TRANDAU_DatNT
where c1.MACLB_4242 = TRANDAU_DatNT.MACLB1_4242 and c2.MACLB_4242 = TRANDAU_DatNT.MACLB2_4242;
go
select * from d9;

-- 10. Cho biết kết quả các trận đấu trên sân nhà (MACLB, NAM, VONG,
--SOBANTHANG, SOBANTHUA)
drop view d10;
go
create view d10
as
select TRANDAU_DatNT.MACLB1_4242 as MACLB, NAM_4242, VONG_4242, KETQUA_4242
from TRANDAU_DatNT;
go
select * from d10;

-- 11.Cho biết kết quả các trận đấu trên sân khách (MACLB, NAM, VONG,
--SOBANTHANG,SOBANTHUA)
drop view d11;
go
create view d11
as
select TRANDAU_DatNT.MACLB2_4242 as MACLB, NAM_4242, VONG_4242, KETQUA_4242
from TRANDAU_DatNT;
go
select * from d11;

-- 12. Cho biết danh sách các trận đấu (NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA)
--của câu lạc bộ CLB đang xếp hạng cao nhất tính đến hết vòng 3 năm 2009
drop view d12;
go
create view d12
as
select NGAYTD_4242, TENSAN_4242, c1.TENCLB_4242 as TENCLB1, c2.TENCLB_4242 as TENCLB2, KETQUA_4242
from CAULACBO_DatNT c1, CAULACBO_DatNT c2, SANVD_DatNT, TRANDAU_DatNT
where c1.MACLB_4242 = TRANDAU_DatNT.MACLB1_4242 and c2.MACLB_4242 = TRANDAU_DatNT.MACLB2_4242
and SANVD_DatNT.MASAN_4242 = TRANDAU_DatNT.MASAN_4242
and (select top 1 MACLB_4242 from BANGXH_DatNT where VONG_4242 = 3 and NAM_4242 = 2009 order by HANG_4242) in (c1.MACLB_4242, c2.MACLB_4242);
go
select * from d12;

-- 13. Cho biết danh sách các trận đấu (NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA)
--của câu lạc bộ CLB có thứ hạng thấp nhất trong bảng xếp hạng vòng 3 năm 2009
drop view d13;
go
create view d13
as
select NGAYTD_4242, TENSAN_4242, c1.TENCLB_4242 as TENCLB1, c2.TENCLB_4242 as TENCLB2, KETQUA_4242
from CAULACBO_DatNT c1, CAULACBO_DatNT c2, SANVD_DatNT, TRANDAU_DatNT
where c1.MACLB_4242 = TRANDAU_DatNT.MACLB1_4242 and c2.MACLB_4242 = TRANDAU_DatNT.MACLB2_4242
and SANVD_DatNT.MASAN_4242 = TRANDAU_DatNT.MASAN_4242
and (select top 1 MACLB_4242 from BANGXH_DatNT where VONG_4242 = 3 and NAM_4242 = 2009 order by HANG_4242 desc) in (c1.MACLB_4242, c2.MACLB_4242);
go
select * from d13;
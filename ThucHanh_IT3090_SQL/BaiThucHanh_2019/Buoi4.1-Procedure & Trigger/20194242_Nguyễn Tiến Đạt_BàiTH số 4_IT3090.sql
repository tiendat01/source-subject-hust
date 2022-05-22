--Bài thực hành số 4
--Nguyễn Tiến Đạt - 20194242
USE QLBongDa_DatNT_4242;
-- a. Bài tập về Store Procedure
-- 1. In ra dòng chữ “Xin Chao”
print N'Xin Chao';

--2. In ra dòng chữ “ Xin chào” + @ten với @ten là tham số đầu vào là tên của
--bạn. Cho thực thi và in giá trị cảu các tham số này để kiểm tra
drop procedure a2;
go
create procedure a2(
@ten NVARCHAR(50), @xau nvarchar(100) out
)
as
begin
set @xau = N'Xin chào ' + @ten;
end;

declare @out nvarchar(100)
execute a2  N'Nguyễn Tiến Đạt - 20194242', @out out;
print @out;

-- 3. Nhập vào 2 số @s1,@s2. In ra câu “Tổng là : @tg’ với @tg = @s1+@s2
drop procedure a3;
go
create procedure a3 (
@s1 INT,
@s2 INT,
@tg INT output
) as
begin
set @tg = @s1 + @s2;
end;

declare @tg1 INT;
execute a3 @s1=3, @s2=5, @tg=@tg1 output;
print N'Tổng là: ' + CAST(@tg1 as nvarchar(10));

-- 4. Nhập vào 2 số @s1,@s2. Xuất min và max của chúng rat ham số
--@max Cho thực thi và in giá trị của các tham số này để kiểm tra.
drop proc a4;
go 
create proc a4 (
@s1 int, @s2 int, @min int out, @max int out
) as begin
	if @s1 < @s2 begin
		set @min = @s1; set @max = @s2;
	end;
	else begin 
	set @min = @s2; set @max = @s1;
	end;
end;

declare @min int, @max int;
exec a4 3, 5, @min output, @max output;
print N'MIN = ' + CAST(@min as NVARCHAR(10));
print N'MAX = ' + CAST(@max as NVARCHAR(10));

--5. Nhập vào số nguyên @n. In ra các số từ 1 đến @n.
drop proc a5;
go 
create proc a5(
@n int
) as
set nocount on;
declare @index int = 1;
begin
	while @index <= @n
	begin
		print @index;
		set @index = @index + 1;
	end;
end;

declare @n int = 5;
exec a5 @n;

-- 6. Nhập vào số nguyên @n. In ra tổng các số chẵn từ 1 đến @n
drop proc a6;
go 
create proc a6(
@n int, @res int output
) as begin
	declare @index int = 1;
	set @res = 0;
	while @index <= @n
	begin
		if @index % 2 = 0
		begin
			set @res = @res + @index; 
		end;
		set @index = @index + 1;
	end;
end;
go
declare @m int = 20, @evensum int;
exec a6 @m, @evensum output;
print N'Tổng các số chẵn từ 1 đến @n: ' + CAST(@evensum as NVARCHAR(10));

-- 7.Viết store procedure tương ứng với các câu ở phần View. Sau đó cho thể hiện kết quả (chọn 5 câu 1,2,3,4,5 trong phần View)
--VIEW 1. Cho biết mã số, họ tên, ngày sinh, địa chỉ và vị trí của các cầu thủ thuộc đội bóng “SHB
--Đà Nẵng” có quốc tịch “Bra-xin”
drop procedure a7cau1;
go
create procedure a7cau1 (@tenclb nvarchar(50), @tenqg nvarchar(50))
as begin
	select MACT_4242, HOTEN_4242, NGAYSINH_4242, DIACHI_4242, VITRI_4242
	from CAUTHU_DatNT, CAULACBO_DatNT, QUOCGIA_DatNT
	where CAUTHU_DatNT.MACLB_4242 = CAULACBO_DatNT.MACLB_4242
	and CAUTHU_DatNT.MAQG_4242 = QUOCGIA_DatNT.MAQG_4242
	and TENCLB_4242 = @tenclb
	and TENQG_4242 = @tenqg;
end;

go
execute a7cau1 N'SHB Đà Nẵng', N'Bra-xin';

--VIEW 2. Cho biết kết quả (MATRAN, NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA) các trận
--đấu vòng 3 của mùa bóng năm 2009.
drop procedure a7cau2;
go
create procedure a7cau2 (@vong int, @nam int)
as begin
	select MATRAN_4242, NGAYTD_4242, TENSAN_4242, c1.TENCLB_4242 as clb1, c2.TENCLB_4242 as clb2, KETQUA_4242
	from TRANDAU_DatNT, SANVD_DatNT, CAULACBO_DatNT c1, CAULACBO_DatNT c2
	where VONG_4242 = @vong and NAM_4242 = NAM_4242
	and TRANDAU_DatNT.MACLB1_4242 = c1.MACLB_4242 and TRANDAU_DatNT.MACLB2_4242 = c2.MACLB_4242
	and TRANDAU_DatNT.MASAN_4242 = SANVD_DatNT.MASAN_4242;
end;

go
execute a7cau2 3, 2009;

-- VIEW 3. Cho biết mã huấn luyện viên, họ tên, ngày sinh, địa chỉ, vai trò và tên CLB đang làm việc
--của các huấn luyện viên có quốc tịch “Việt Nam”
drop procedure a7cau3;
go
create procedure a7cau3 (@tenqg nvarchar(50))
as begin
	select HUANLUYENVIEN_DatNT.MAHLV_4242, TENHLV_4242, NGAYSINH_4242, DIACHI_4242, VAITRO_4242, TENCLB_4242
	from HLV_CLB_DatNT, HUANLUYENVIEN_DatNT, QUOCGIA_DatNT, CAULACBO_DatNT
	where HUANLUYENVIEN_DatNT.MAHLV_4242 = HLV_CLB_DatNT.MAHLV_4242
	and HLV_CLB_DatNT.MACLB_4242 = CAULACBO_DatNT.MACLB_4242
	and HUANLUYENVIEN_DatNT.MAQG_4242 = QUOCGIA_DatNT.MAQG_4242
	and TENQG_4242 = @tenqg;
end;

go
execute a7cau3 N'Việt Nam';

-- VIEW 4. Cho biết mã câu lạc bộ, tên câu lạc bộ, tên sân vận động, địa chỉ và số lượng cầu thủ
--nước ngoài (có quốc tịch khác “Việt Nam”) tương ứng của các câu lạc bộ nhiều hơn 2 cầu thủ nước ngoài
drop procedure a7cau4;
go
create procedure a7cau4 (@tenqg nvarchar(50))
as begin
	select CAULACBO_DatNT.MACLB_4242, TENCLB_4242, TENSAN_4242, SANVD_DatNT.DIACHI_4242, COUNT(*) as SOLUONGCAUTHUNGOAI
	from CAULACBO_DatNT, SANVD_DatNT, QUOCGIA_DatNT, CAUTHU_DatNT
	where CAULACBO_DatNT.MACLB_4242 = CAUTHU_DatNT.MACLB_4242
	and CAULACBO_DatNT.MASAN_4242 = SANVD_DatNT.MASAN_4242
	and CAUTHU_DatNT.MAQG_4242 = QUOCGIA_DatNT.MAQG_4242
	and TENQG_4242 <> @tenqg
	group by CAULACBO_DatNT.MACLB_4242, TENCLB_4242, TENSAN_4242, SANVD_DatNT.DIACHI_4242
	having COUNT(*)  >  2;
end;

go
execute a7cau4 N'Việt Nam';

-- VIEW 5. Cho biết tên tỉnh, số lượng câu thủ đang thi đấu ở vị trí tiền đạo trong các câu lạc bộ
--thuộc địa bàn tỉnh đó quản lý.
drop procedure a7cau5;
go
create procedure a7cau5 (@vitri nvarchar(20))
as begin
	select TENTINH_4242, COUNT(*) as "Số cầu thủ thi đấu"
	from TINH_DatNT, CAUTHU_DatNT, CAULACBO_DatNT
	where TINH_DatNT.MATINH_4242 = CAULACBO_DatNT.MATINH_4242
	and CAUTHU_DatNT.MACLB_4242 = CAULACBO_DatNT.MACLB_4242
	and VITRI_4242 = @vitri
	group by TENTINH_4242;
end;

go
execute a7cau5 N'Tiền đạo';

-- 8. Ứng với 5 bảng trong CSDL QLBongDa (QuocGia, Cau Thu, HLV, HLV_CLB, CauLacBo), bạn hãy viết 4 stored Procedure ứng với 4 công việc
--Insert/Update/Delete/Select. Trong đó Stored procedure update và delete lấy khóa chính làm tham số
-- 8.1. Bảng QUOCGIA
-- 8.1.1. Stored Procedure ứng với Select:
drop proc select_quocgia;
go
create procedure select_quocgia
as begin
select * from QUOCGIA_DatNT;
end;
go
exec select_quocgia;

-- 8.1.2. Stored Procedure ứng với Insert:
drop proc insert_quocgia;
go
create procedure insert_quocgia (
@maqg varchar(5), @tenqg nvarchar(60)
) as begin
insert into QUOCGIA_DatNT(MAQG_4242, TENQG_4242) values (@maqg, @tenqg);
end;
go
execute insert_quocgia 'KW', 'Kuwait';
execute select_quocgia;

-- 8.1.3. Stored Procedure ứng với Update:
drop proc update_quocgia;
go
create procedure update_quocgia (
@maqg varchar(5), @tenqg nvarchar(60)
) as begin
update QUOCGIA_DatNT set TENQG_4242 = @tenqg where MAQG_4242 = @maqg;
end;
go
execute update_quocgia 'KW', 'Kawaki';
execute select_quocgia;


-- 8.1.4. Stored Procedure ứng với Delete:
drop proc delete_quocgia;
go
create procedure delete_quocgia (@maqg varchar(5)) 
as begin
delete QUOCGIA_DatNT where MAQG_4242 = @maqg;
end;
go
execute delete_quocgia 'KW';
execute select_quocgia;

-- 8.2. Bảng CAUTHU
-- 8.2.1. Stored Procedure ứng với Select:
drop proc select_cauthu;
go
create procedure select_cauthu as begin
	select * from CAUTHU_DatNT;
end;
go 
exec select_cauthu;

-- 8.2.2. Stored Procedure ứng với Insert:
drop proc insert_cauthu;
go
create procedure insert_cauthu (
@hoten nvarchar(100), @vitri nvarchar(20), @ngaysinh datetime, @diachi nvarchar(200), @maclb varchar(5), @maqg varchar(5), @so int
) as begin
	insert into CAUTHU_DatNT (HOTEN_4242, VITRI_4242, NGAYSINH_4242, DIACHI_4242, MACLB_4242, MAQG_4242, SO_4242)
	values (@hoten, @vitri, @ngaysinh, @diachi, @maclb, @maqg, @so)
end;
go
exec insert_cauthu N'abc', N'abc', null, null, 'BBD', 'VN', 1000;
exec select_cauthu;

-- 8.2.3. Stored Procedure ứng với Update:
drop proc update_cauthu;
go
create procedure update_cauthu (
@mact numeric(18,0), @hoten nvarchar(100), @vitri nvarchar(20), @ngaysinh datetime, @diachi nvarchar(200), @maclb varchar(5),
	 @maqg varchar(5), @so int
) as begin
	update CAUTHU_DatNT set HOTEN_4242=@hoten, VITRI_4242=@vitri, NGAYSINH_4242=@ngaysinh, DIACHI_4242=@diachi,
	MACLB_4242=@maclb, MAQG_4242=@maqg, SO_4242=@so where MACT_4242 = @mact;
end;

go
exec update_cauthu 10113, N'tên mới', N'abc', null, null, 'BBD', 'VN', 1000;
exec select_cauthu;

-- 8.2.4. Stored Procedure ứng với Delete:
drop proc delete_cauthu;
go
create procedure delete_cauthu (
@mact numeric(18,0)
) as begin
	delete CAUTHU_DatNT where MACT_4242 = @mact;
end;
go
exec delete_cauthu 10113;
exec select_cauthu;

--8.3. Bảng HUANLUYENVIEN
--8.3.1. Stored Procedure ứng với Select:
drop proc select_hlv;
go 
create proc select_hlv 
as begin
	select * from HUANLUYENVIEN_DatNT;
end;

go 
exec select_hlv;

-- 8.3.2. Stored Procedure ứng với Insert:
drop proc insert_hlv;
go
create proc insert_hlv (
@mahlv varchar(5), @tenhlv nvarchar(100), @ngaysinh datetime, @diachi nvarchar(200), @dienthoai nvarchar(20), @maqg varchar(5)
) as begin
	insert into HUANLUYENVIEN_DatNT (MAHLV_4242, TENHLV_4242, NGAYSINH_4242, DIACHI_4242, DIENTHOAI_4242, MAQG_4242)
	values (@mahlv, @tenhlv, @ngaysinh, @diachi, @dienthoai, @maqg);
end;
go
exec insert_hlv 'HLV50', N'Nguyễn Tiến Đạt - 4242', null, null, null, 'VN';
exec select_hlv;

--8.3.3. Stored Procedure ứng với Update:
drop proc update_hlv;
go 
create proc update_hlv (
@mahlv varchar(5), @tenhlv nvarchar(100), @ngaysinh datetime, @diachi nvarchar(200), @dienthoai nvarchar(20), @maqg varchar(5)
) as begin
	update HUANLUYENVIEN_DatNT set TENHLV_4242=@tenhlv, NGAYSINH_4242=@ngaysinh, DIACHI_4242=@diachi,
	DIENTHOAI_4242=@dienthoai, MAQG_4242=@maqg
	where MAHLV_4242=@mahlv;
end;
go 
exec update_hlv 'HLV50', N'Nguyễn Tiến Đạt - 4242', null, null, null, 'ANH';
exec select_hlv;

-- 8.3.4. Stored Procedure ứng với Delete:
drop proc delete_hlv;
go 
create proc delete_hlv (@mahlv varchar(5)) 
as begin
	delete HUANLUYENVIEN_DatNT where MAHLV_4242 = @mahlv;
end;
go 
exec delete_hlv 'HLV50';
exec select_hlv;

--8.4. Bảng HLV_CLB
-- 8.4.1. Stored Procedure ứng với Select:
drop proc select_hlvclb;
go 
create proc select_hlvclb 
as begin
	select * from HLV_CLB_DatNT;
end;
go 
exec select_hlvclb;

-- 8.4.2. Stored Procedure ứng với Insert:
drop proc insert_hlvclb;
go 
create proc insert_hlvclb(
	@mahlv varchar(5), @maclb varchar(5), @vaitro nvarchar(100)
) as begin
	insert into HLV_CLB_DatNT (MAHLV_4242, MACLB_4242, VAITRO_4242)
	values (@mahlv, @maclb, @vaitro);
end;
go 
exec insert_hlvclb 'HLV08', 'HAGL', N'HLV thể lực';
exec select_hlvclb;

-- 8.4.3. Stored Procedure ứng với Update:
drop proc update_hlvclb;
go 
create proc update_hlvclb(
	@mahlv varchar(5), @maclb varchar(5), @vaitro nvarchar(100)
) as begin
	update HLV_CLB_DatNT set MACLB_4242=@maclb, VAITRO_4242=@vaitro 
	where MAHLV_4242 = @mahlv;
end;
go 
exec update_hlvclb 'HLV08', 'BBD', N'HLV thủ môn';
exec select_hlvclb;

--8.4.4. Stored Procedure ứng với Delete:
drop proc delete_hlvclb;
go 
create proc delete_hlvclb(
	@mahlv varchar(5)
) as begin
	delete from HLV_CLB_DatNT where MAHLV_4242 = @mahlv;
end;
go 
exec delete_hlvclb 'HLV08';
exec select_hlvclb;

--8.5. Bảng CAULACBO
-- 8.5.1. Stored Procedure ứng với Select:
drop proc select_clb;
go 
create proc select_clb
as begin
	select * from CAULACBO_DatNT;
end;
go 
exec select_clb;

-- 8.5.2. Stored Procedure ứng với Insert:
drop proc insert_clb;
go 
create proc insert_clb (
	@maclb varchar(5), @tenclb nvarchar(100), @masan varchar(5), @matinh varchar(5)
) as begin
	insert into CAULACBO_DatNT (MACLB_4242, TENCLB_4242, MASAN_4242, MATINH_4242)
	values (@maclb, @tenclb, @masan, @matinh);
end;
go 
exec insert_clb 'DTQG', N'Đội tuyển quốc gia', 'CL', 'DN';
exec select_clb;

-- 8.5.3. Stored Procedure ứng với Update:
drop proc update_clb;
go 
create proc update_clb (
	@maclb varchar(5), @tenclb nvarchar(100), @masan varchar(5), @matinh varchar(5)
) as begin
	update CAULACBO_DatNT set TENCLB_4242 = @tenclb, MASAN_4242 = @masan, MATINH_4242 = @matinh
	where MACLB_4242 = @maclb;
end;
go 
exec update_clb 'DTQG', N'Đội tuyển Việt Nam', 'CL', 'DN';
exec select_clb;

-- 8.5.4. Stored Procedure ứng với Delete:
drop proc delete_clb;
go 
create proc delete_clb (@maclb varchar(5))
as begin
	delete CAULACBO_DatNT where MACLB_4242 = @maclb;
end;
go 
exec delete_clb 'DTQG';
exec select_clb;

--b. Bài tập về Trigger
--1. Khi thêm cầu thủ mới, kiểm tra vị trí trên sân của cầu thủ chỉ thuộc một trong các vị trí sau:
--Thủ môn, Tiền đạo, Tiền vệ, Trung vệ, Hậu vệ.
drop trigger trg_b1;
go
create trigger trg_b1 on CAUTHU_DatNT
after insert
as begin
	declare @VITRI_4242 nvarchar(20);
	select @VITRI_4242 = VITRI_4242 from inserted;
	if @VITRI_4242 not in (N'Thủ môn', N'Tiền đạo', N'Tiền vệ', N'Trung vệ', N'Hậu vệ') 
	begin
		rollback transaction;
	end;
end;

insert into CAUTHU_DatNT(HOTEN_4242, VITRI_4242, NGAYSINH_4242, DIACHI_4242, MAQG_4242, MACLB_4242, SO_4242)
values (N'Tiến Đạt', N'Trung vệ', null, null, 'VN', 'GDT', 17);

-- 2. Khi thêm cầu thủ mới, kiểm tra số áo của cầu thủ thuộc cùng một câu lạc bộ phải khác nhau
drop trigger trg_b2;
go
create trigger trg_b2 on CAUTHU_DatNT
for insert
as begin
	declare @SO_4242 int;
	declare @MACLB_4242 varchar(5);
	select @SO_4242 = SO_4242, @MACLB_4242 = MACLB_4242 from inserted;
	if (select count(*)from CAUTHU_DatNT ct where ct.MACLB_4242 = @MACLB_4242 and ct.SO_4242 = @SO_4242) > 1
	begin
		rollback transaction
	end;
end;
--insert into CAUTHU_DatNT(HOTEN_4242, VITRI_4242, NGAYSINH_4242, DIACHI_4242, MAQG_4242, MACLB_4242, SO_4242)
--values (N'Tiến Đạt', N'Trung vệ', null, null, 'VN', 'GDT', 17);
insert into CAUTHU_DatNT(HOTEN_4242, VITRI_4242, NGAYSINH_4242, DIACHI_4242, MAQG_4242, MACLB_4242, SO_4242)
values (N'Đạt Nguyễn', N'Tiền vệ', null, null, 'VN', 'GDT', 1000);
select * from CAUTHU_DatNT;


-- 3. Khi thêm thông tin cầu thủ thì in ra câu thông báo bằng Tiếng Việt ‘Đã thêm cầu thủ mới’
drop trigger trg_b3;
go 
create trigger trg_b3 on dbo.CAUTHU_DatNT
for insert
as begin
	print N'Đã thêm cầu thủ mới';
end;

insert into CAUTHU_DatNT(HOTEN_4242, VITRI_4242, NGAYSINH_4242, DIACHI_4242, MAQG_4242, MACLB_4242, SO_4242)
values (N'Đạt Nguyễn', N'Tiền vệ', null, null, 'VN', 'HAGL', 1000);


--4. Khi thêm cầu thủ mới, kiểm tra số lượng cầu thủ nước ngoài ở mỗi câu lạc bộ chỉ được
--phép đăng ký tối đa 8 cầu thủ
drop trigger trg_b4;
go 
create trigger trg_b4 on dbo.CAUTHU_DatNT
for insert
as begin
	declare @MACLB_4242 varchar(5);
	select @MACLB_4242 = MACLB_4242 from inserted;
	if (select count(*) from CAUTHU_DatNT where MACLB_4242 = @MACLB_4242 and MAQG_4242 <> 'VN') > 8
	begin
		rollback transaction;
	end;
end;

-- 5. Khi thêm tên quốc gia, kiểm tra tên quốc gia không được trùng với tên quốc gia đã có
go
create trigger trg_b5 on dbo.QUOCGIA_DatNT
for insert
as begin
	declare @tenqg nvarchar(60);
	select @tenqg = TENQG_4242 from inserted;
	if (select count(*) from QUOCGIA_DatNT where TENQG_4242 = @tenqg) > 1
	begin
		rollback transaction;
	end;
end;
select * from QUOCGIA_DatNT;
insert into QUOCGIA_DatNT (MAQG_4242, TENQG_4242) values ('KW', N'Kuwait');
select * from QUOCGIA_DatNT;

-- 6. Khi thêm tên tỉnh thành, kiểm tra tên tỉnh thành không được trùng với tên tỉnh thành đã có
drop trigger trg_b6;
go 
create trigger trg_b6 on dbo.TINH_DatNT
for insert
as begin
	declare @tentinh nvarchar(60);
	select @tentinh = TENTINH_4242 from inserted;
	if (select count(*) from TINH_DatNT where TENTINH_4242 = @tentinh) > 1
	begin
		rollback transaction;
	end;
end;


-- 7. Không cho sửa kết quả của các trận đấu đã diễn ra
drop trigger trg_b7;
go 
create trigger trg_b7 on dbo.TRANDAU_DatNT
for update
as begin
	declare @ngaytd datetime;
	--select @ngaytd = NGAYTD_4242 from deleted;
	if DATEDIFF(day, @ngaytd, CURRENT_TIMESTAMP) > 0
	begin 
		rollback transaction;
	end;
end;


--8. Khi phân công huấn luyện viên cho câu lạc bộ:
--8a. Kiểm tra vai trò của huấn luyện viên chỉ thuộc một trong các vai trò sau: HLV chính,
--HLV phụ, HLV thể lực, HLV thủ môn
drop trigger trg_b8a
go
create trigger trg_b8a on dbo.HLV_CLB_DatNT
for insert 
as begin
	declare @vaitro nvarchar(100);
	select @vaitro = VAITRO_4242 from inserted;
	if @vaitro not in (N'HLV chính', N'HLV phụ', N'HLV thể lực', N'HLV thủ môn')
	begin
		rollback transaction;
	end;
end;
--8b. Kiểm tra mỗi câu lạc bổ chỉ có tối đa 2 HLV chính
drop trigger trg_b8b
go
create trigger trg_b9b on dbo.HLV_CLB_DatNT
for insert 
as begin
	declare @maclb varchar(5);
	select @maclb = MACLB_4242 from inserted;
	if (select count(*) from HLV_CLB_DatNT where MACLB_4242 = @maclb and VAITRO_4242 = N'HLV chính') > 2
	begin
		rollback transaction
	end;
end;

-- 9. Khi thêm mới một câu lạc bộ thì kiểm tra xem đã có câu lạc bộ trùng tên với câu lạc bộ
--vừa được thêm hay không?
--a. Chỉ thông báo vẫn cho insert
drop trigger trg_b9a
go
create trigger trg_b9a on dbo.CAULACBO_DatNT
for insert 
as begin
	declare @tenclb nvarchar(100);
	select @tenclb = TENCLB_4242 from CAULACBO_DatNT;
	if (select count(*) from CAULACBO_DatNT where TENCLB_4242 = @tenclb) > 2
	begin
		print N'Câu lạc bộ ' + @tenclb + ' trùng tên với câu lạc bộ vừa thêm';
	end;
end;
--b. Thông báo và không cho insert
drop trigger trg_b9b
go
create trigger trg_b9b on dbo.CAULACBO_DatNT
for insert 
as begin
	declare @tenclb nvarchar(100);
	select @tenclb = TENCLB_4242 from CAULACBO_DatNT;
	if (select count(*) from CAULACBO_DatNT where TENCLB_4242 = @tenclb) > 2
	begin
		print N'Câu lạc bộ ' + @tenclb + ' trùng tên với câu lạc bộ vừa thêm';
		rollback transaction;
	end;
end;
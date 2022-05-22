-- Bài thực hành số 5
-- Nguyễn Tiến Đạt - 20194242
use AdventureWorks2014;

-- 1. Hiển thị chi tiết của tất cả mọi người từ bảng Person.Person
select * from Person.Person;

-- 2. Hiển thị Title, FirstName, MiddleName, LastName và EmailAddress từ bảng
--Person.Contact 
select Title, FirstName, MiddleName, LastName, EmailAddress from Person.Person person 
inner join Person.EmailAddress email on person.BusinessEntityID = email.BusinessEntityID;

--3. Hiển thị Title, FirstName, LastName như là một chuỗi nối nhằm dễ đọc và cung
--cấp tiêu đề cho cột tên (PersonName).
select concat(Title, FirstName, ' ', LastName) [Full Name] from Person.Person; 

--4. Hiển thị chi tiết địa chỉ của tất cả các nhân viên trong bảng Person.Address
select concat(p.FirstName, ' ', p.MiddleName, ' ', p.LastName) [Full Name], a.AddressLine1
from Person.Address a
inner join Person.BusinessEntityAddress bea on a.AddressID = bea.AddressID
inner join Person.Person p on bea.BusinessEntityID = p.BusinessEntityID;

-- 5. Liệt kê tên của các thành phố từ bảng Person.Address và bỏ đi phần lặp lại
select a.City from Person.Address a group by a.City order by a.City;

-- 6. Hiển thị chi tiết của 10 bảng ghi đầu tiên của bảng Person.Address.
select TOP 10 * from Person.Address;

-- 7. Hiển thị trung bình của tỷ giá (Rate) từ bảng HumanResources.EmployeePayHistory.
select AVG(eph.Rate) as [Trung bình tỷ giá] from HumanResources.EmployeePayHistory eph;

-- 8. Hiển thị tổng số nhân viên từ bảng HumanResources.Employee
select COUNT(Employee.BusinessEntityID) from HumanResources.Employee;

-- 9. Đưa ra danh sách các khách hàng có trên 10 đơn hàng
select c.CustomerID from Sales.Customer c 
inner join Sales.SalesOrderHeader soh on c.CustomerID = soh.CustomerID
group by c.CustomerID having count(soh.SalesOrderID) > 10;

-- 10. Đưa ra danh sách các mặt hàng chưa từng được đặt hàng
select prod.Name from Production.Product prod
where prod.Name not in
(select prod.Name from Production.Product prod
inner join Sales.SalesOrderDetail sod on prod.ProductID = sod.ProductID
inner join Sales.SalesOrderHeader soh on sod.SalesOrderID = soh.SalesOrderID
group by prod.Name)
order by prod.Name;
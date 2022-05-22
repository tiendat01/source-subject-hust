#include <iostream>

typedef double datatype;

struct phanso {
    datatype tu;
    datatype mau;
};

// chi dung neu datatype la int
datatype UCLN(datatype a, datatype b) {
    if (a == b) return a;
    if (a > b) return UCLN(a-b, b);
    else return UCLN(a, b-a);
}

// chi dung neu datatype la int
phanso & toiGianPhanSo(phanso &p1) {
    datatype ucln = UCLN(p1.tu, p1.mau);
    p1.tu /= ucln;
    p1.mau /= ucln;
    return p1;
}

phanso operator + (phanso p1, phanso p2) {
    phanso tmp;
    tmp.tu = p1.tu * p2.mau + p1.mau * p2.tu;
    tmp.mau = p1.mau * p2.mau;
    return tmp;
}

phanso operator - (phanso p1, phanso p2) {
    phanso tmp;
    tmp.tu = p1.tu * p2.mau - p1.mau * p2.tu;
    tmp.mau = p1.mau * p2.mau;
    return tmp;
}

phanso operator * (phanso p1, phanso p2) {
    phanso tmp;
    tmp.tu = p1.tu * p2.tu;
    tmp.mau = p1.mau * p2.mau;
    return tmp;
}

phanso operator / (phanso p1, phanso p2) {
    phanso tmp;
    tmp.tu = p1.tu * p2.mau;
    tmp.mau = p1.mau * p2.tu;
    return tmp;
}

phanso operator ++ (phanso &a){
	a.tu = a.tu + a.mau;
	return a;
}
phanso operator -- (phanso &a){
	a.tu = a.tu - a.mau;
	return a;
}
phanso &operator ++ (phanso &a,int){
	phanso b = a;
	a.tu = a.tu + a.mau;
	return b;
}
phanso &operator -- (phanso &a,int){
	phanso b = a;
	a.tu = a.tu - a.mau;
	return b;
}
phanso &operator += (phanso &a, phanso b){
	a = a + b;
	return a;
}
phanso &operator -= (phanso &a, phanso b){
	a = a - b;
	return a;
}
phanso &operator *= (phanso &a, phanso b){
	a = a * b;
	return a;
}
phanso &operator /= (phanso &a, phanso b){
	a = a / b;
	return a;
}

phanso setPhanSo(datatype tu, datatype mau) {
    phanso tmp;
    tmp.mau = mau;
    tmp.tu = tu;
    return tmp;
}

void display(phanso p1) {
    std::cout << p1.tu << "/" << p1.mau;
}

int main() {
    phanso q1, q2, res;
    q1 = setPhanSo(1,2);
    q2 = setPhanSo(1,4);
    res = q1 + q2;
    toiGianPhanSo(res);
    display(res);
}
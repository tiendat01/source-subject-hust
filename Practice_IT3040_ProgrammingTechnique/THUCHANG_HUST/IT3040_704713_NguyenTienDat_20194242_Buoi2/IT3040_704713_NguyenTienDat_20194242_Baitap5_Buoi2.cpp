#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    Complex c;
    c.imag = a.imag + b.imag;
    c.real = a.real + b.real;
    return c;
}

Complex operator - (Complex a, Complex b) {
    Complex c;
    c.imag = a.imag - b.imag;
    c.real = a.real - b.real;
    return c;
}

Complex operator * (Complex a, Complex b) {
    Complex c;
    c.imag = a.imag * b.real + b.imag * a.real;
    c.real = a.real * b.real - b.imag * a.imag;
    return c;
}

Complex operator / (Complex a, Complex b) {
    Complex c;
    double A = b.real;
    double B = b.imag;
    double C = a.real;
    double D = a.imag;
    c.real = (A*C + B*D) / (A*A + B*B);
    c.imag = (A*D - B*C) / (A*A + B*B);
    return c;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    Complex a = {real_a, img_a};
    Complex b = {real_b, img_b};
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}

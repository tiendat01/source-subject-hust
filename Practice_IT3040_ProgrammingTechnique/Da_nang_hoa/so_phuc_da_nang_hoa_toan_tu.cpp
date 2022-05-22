#include <iostream>

using namespace std;

typedef struct {
    double real;
    double img;
} sophuc;

sophuc setSP(double real, double img) {
    sophuc sp;
    sp.real = real;
    sp.img = img;
    return sp;
}

template<typename T>
sophuc &operator+= (sophuc &c, T a) {
    c.real += a;
    return c;
}

template<typename T>
sophuc &operator+= (T a, sophuc &c) {
    c.real += a;
    return c;
}

// sophuc& operator += (sophuc &c, double a) {
//     c.real += a;
//     return c;
// }

sophuc& operator += (sophuc &c, sophuc a) {
    c.real += a.real;
    c.img += a.img;
    return c;
}

// tien to ++a = a + 1: tra ve gia tri da tang len 1 cua a
sophuc& operator ++ (sophuc &c) {
    c.real++;
    return c;
}

// hau to a++: tra ve a sau do moi tang a len 1
// muc dich cua tham so hinh thuc 'int' la de phan biet voi toan tu tien to
sophuc operator ++ (sophuc &c, int) {
    sophuc tmp = c;
    c.real++;
    return tmp;
}

sophuc operator + (sophuc c1, sophuc c2) {
    sophuc tmp;
    tmp.real = c1.real + c2.real;
    tmp.img = c1.img + c2.img;
    return tmp;
}

sophuc operator - (sophuc c1, sophuc c2) {
    sophuc tmp;
    tmp.real = c1.real - c2.real;
    tmp.img = c1.img - c2.img;
    return tmp;
}

void Display(sophuc c) {
    cout << c.real << "+" << c.img << "i";
}

int main() {
    sophuc so1 = setSP(1.0, 2.0);
    sophuc so2 = setSP(2.0, 3.0);
    // so1 += so2;
    // so1+=2;
    sophuc x = so1++;
    sophuc y = ++so2;
    Display(x);
    cout << endl;
    Display(y);

}
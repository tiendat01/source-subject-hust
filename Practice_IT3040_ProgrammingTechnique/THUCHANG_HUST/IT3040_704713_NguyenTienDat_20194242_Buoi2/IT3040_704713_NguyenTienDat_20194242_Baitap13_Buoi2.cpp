#include <iostream>

using namespace std;

struct bigNum{
    char sign;
    char num[101];
};

void input(bigNum &number) {
    string data;
    cin >> data;
    // 0 la am, 1 la duong
    number.sign = data.at(0);
    int length = data.length();
    for (int i = 1; i < length; i++) number.num[100-length+i+1] = data.at(i);
    for (int i = 0; i <= 100 - length+1; i++) number.num[i] = '0';
}

inline int charToInt(char c) { return (int)(c-48);}
inline char intToChar(int n) {return (char)(n+'0');}

void printBigNumber(bigNum number){
    cout << number.sign;
    int start;
    for(start=0; start<101; start++)
        if(number.num[start] != '0') break;

    for(int i = start; i<101; i++)
        cout << number.num[i];
}

void add_positive(char res[101], char *a, char *b) {
    int carry = 0;
    for (int i = 100; i >= 0; i--) {
        int tmp = charToInt(a[i]) + charToInt(b[i]) + carry;
        res[i] = intToChar(tmp % 10);
        carry = tmp / 10;
    }
}

void sub_positive(char res[101], char *big, char *small) {
    int borrow = 0;
    for (int i = 100; i >= 0; i--) {
        int tmp = charToInt(big[i]) - charToInt(small[i]) - borrow;
        if (tmp < 0) {
            tmp += 10;
            borrow = 1;
        }
        else borrow = 0;
        res[i] = intToChar(tmp);
    }
}

// bigInt * n
void multi_positive_const(char res[101], char *a, unsigned int n) {
    int carry = 0;
    for (int i = 100; i >= 0; i--) {
        int tmp = charToInt(a[i]) * n + carry;
        res[i] = intToChar(tmp % 10);
        carry = tmp / 10;
    }
}

// so sanh abs(a) < abs(b) neu dung tra ve true
bool operator < (bigNum a, bigNum b) {
    int i = 0;
    for (; i <= 100; i++) {
        if (a.num[i] != '0' && b.num[i] == '0') break;
        if (a.num[i] == '0' && b.num[i] != '0') break;
        if (a.num[i] != '0' && b.num[i] != '0' && b.num[i] != a.num[i]) break;  
    }
    if (a.num[i] < b.num[i]) return true;
    else return false;
}

bigNum operator + (bigNum a, bigNum b) {
    bigNum result;
    if (a.sign == b.sign) {
        if (a.sign == '0') result.sign = '0';
        else result.sign = '1';
        add_positive(result.num, a.num, b.num);
        return result;
    }
    else {
        // so duong nho a + so am lon b
        if (a.sign == '1' && a < b) {
            sub_positive(result.num, b.num, a.num);
            result.sign = '0';
            return result;
        }
        // so duong lon a + so am nho b
        else if (a.sign == '1' && !(a < b)) {
            sub_positive(result.num, a.num, b.num);
            result.sign = '1';
            return result;
        }
        // so am nho a + so duong lon b
        else if (a.sign == '0' && a < b) {
            sub_positive(result.num, b.num, a.num);
            result.sign = '1';
            return result;
        }
        // so am lon a + so duong nho b
        else {
            sub_positive(result.num, a.num, b.num);
            result.sign = '0';
            return result;
        }
    }
}

bigNum operator - (bigNum a, bigNum b) {
    bigNum result;
    if (a.sign != b.sign) {
        if (a.sign == '0') result.sign = '0';
        else result.sign = '1';
        add_positive(result.num, a.num, b.num);
        return result;
    }
    else {
        // so am nho a - so am lon b
        if (a.sign == '0' && a < b) {
            sub_positive(result.num, b.num, a.num);
            result.sign = '1';
            return result; 
        }
        // so am lon a - so am nho b
        else if (a.sign == '0' && !(a < b)) {
            sub_positive(result.num, a.num, b.num);
            result.sign = '0';
            return result;
        }
        // so duong nho a - so duong lon b
        else if (a.sign == '1' && a < b) {
            sub_positive(result.num, b.num, a.num);
            result.sign = '0';
            return result;
        }
        // so duong lon a - so duong nho b
        else {
            sub_positive(result.num, a.num, b.num);
            result.sign = '1';
            return result;
        }
    }
}

bigNum operator * (bigNum a, unsigned int n) {
    bigNum result;
    result.sign = a.sign;
    multi_positive_const(result.num, a.num, n);
    return result;
}

bigNum operator * (bigNum a, bigNum b) {
    bigNum result;
    for (int i = 0; i <= 100; i++) result.num[i] = '0';
    if (a.sign == b.sign) result.sign = '1';
    else result.sign = '0';
    
    for (int i = 100; i >= 0; i--) {
        char tmp[101];
        // khoi tao tmp
        for (int k = 0; k < 101; k++) tmp[k] = '0';

        int carry = 0;
        int k = i;
        for (int j = 100; j >= 0; j--) {
            int tmp_num = charToInt(a.num[j]) * charToInt(b.num[i]) + carry;
            tmp[k] = intToChar(tmp_num % 10);
            carry = tmp_num / 10;
            k--; if (k < 0) break;
        }
        add_positive(result.num, result.num, tmp);

    }
    return result;

}



int main() {
    bigNum num1, num2, result;
    input(num1);
    input(num2);
    printBigNumber(num1);
    printBigNumber(num2);
    result = num1*num2 - num1*3 + num2*4;
    printBigNumber(result);
    
    return 0;
}
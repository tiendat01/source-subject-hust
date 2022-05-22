#include <iostream>

using namespace std;

struct Time {
    int hour; // 0->23
    int minute; // 0->59
    int second; // 0->59

    Time& operator= (const Time& new_time) {
        hour = new_time.hour;
        minute = new_time.minute;
        second = new_time.second;
        return *this;
    }
};

bool operator== (const Time& t1, const Time& t2) {
    if (t1.hour == t2.hour && t1.minute == t2.minute && t1.second == t2.second) return true;
    return false;
}

bool operator< (const Time& t1, const Time& t2) {
    if (t1.hour < t2.hour) return true;
    else if (t1.hour == t2.hour) {
        if (t1.minute < t2.minute) return true;
        else if (t1.minute == t2.minute) {
            if (t1.second < t2.second) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

Time operator+ (const Time& t1, const Time& t2) {
    Time res;
    res.second = (t1.second + t2.second) % 60;
    res.minute = (t1.minute + t2.minute) % 60;
    res.hour = (t1.hour + t2.hour) % 24;
    
    if ((t1.second + t2.second) >= 60) {
        if (res.minute == 59) {
            res.minute = 0;
            res.hour++;
            if (res.hour == 24) res.hour = 0;
        }
        else res.minute++;
    }
    if ((t1.minute + t2.minute ) >= 60) {
        if (res.hour == 23) res.hour = 0;
        else res.hour++;
    }
    
    if (t1.hour + t1.hour >= 24) res.hour -= 24;

    return res;
}

// t1 - t2
Time operator- (const Time& t1, const Time& t2) {
    Time res;
    res.hour = t1.hour - t2.hour;
    res.minute = t1.minute - t2.minute;
    res.second = t1.second - t2.second;
    if (res.second < 0) {
        res.second += 60;
        res.minute--;
        if (res.minute < 0) {
            res.minute += 60;
            res.hour--;
            if (res.hour < 0) res.hour += 24;
        }
    }
    else {
        if (res.minute < 0) {
            res.minute += 60;
            res.hour--;
            if (res.hour < 0) res.hour += 24;
        }
        else {
            if (res.hour < 0) res.hour += 24;
        }
    }
    return res;
}

Time& operator++ (Time &t1, int) { // tang 1s, hau to
    if (t1.hour == 23 && t1.minute == 59 && t1.second == 59) {
        t1.hour = 0;
        t1.minute = 0;
        t1.second = 0;
    }
    else if (t1.minute == 59 && t1.second == 59) {
        t1.hour++;
        t1.minute = 0;
        t1.second = 0;
    }
    else if (t1.second == 59) {
        t1.minute++;
        t1.second = 0;
    }
    else t1.second++;
    return t1;
}

Time& operator-- (Time &t2, int) { // giam 1s, hau to
    if (t2.hour == 0 && t2.minute == 0 && t2.second == 0) {
        t2.hour = 23;
        t2.minute = 59;
        t2.second = 59;
    }
    else if (t2.minute == 0 && t2.second == 0) {
        t2.hour--;
        t2.minute = 59;
        t2.second = 59;
    }
    else if (t2.second == 0) {
        t2.minute--;
        t2.second = 59;
    }
    else t2.second--;
    return t2;
}

istream& operator>> (istream& is, Time& time) {
    cout << "Nhap gio, phut, giay (cach nhau boi dau space): " << endl << "Luu y: 0 <= gio, phut, giay\tgio <= 23\tphut, giay <= 59\n";
    do {
        is >> time.hour >> time.minute >> time.second;
        if (time.hour < 0 || time.hour > 23 ||
          time.minute < 0 || time.minute > 59 ||
          time.second < 0 || time.second > 59
        ) cout << "Du lieu nhap sai quy dinh. Moi nhap lai.";
    } while (time.hour < 0 || time.hour > 23 ||
           time.minute < 0 || time.minute > 59 ||
           time.second < 0 || time.second > 59);
    return is;
}

ostream& operator<< (ostream& os, const Time& time) {
    os << (time.hour < 10 ? "0" : "") << time.hour << 
    ':' << (time.minute < 10 ? "0" : "") << time.minute <<
    ':' << (time.second < 10 ? "0" : "") << time.second;
    return os;
}

int main() {
    Time t1,t2;
    cin >> t1 >> t2;
    cout << t1 << endl << t2 << endl;
    cout << (t1-t2) << endl;
    cout << t1++;
}

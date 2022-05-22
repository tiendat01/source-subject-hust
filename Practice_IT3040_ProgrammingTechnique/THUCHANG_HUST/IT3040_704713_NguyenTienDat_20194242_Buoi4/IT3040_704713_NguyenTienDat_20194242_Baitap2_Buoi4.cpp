 #include <iostream>
 #include <cmath>
 #include <iomanip>
 #include <utility>
 using namespace std;
 using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    /*****************
    # YOUR CODE HERE #
    *****************/
	return 0.5 * fabs((c.first - a.first) * (b.second - a.second) - (b.first - a.first) * (c.second - a.second));
}

 int main() {
 	cout << "Ho ten: Nguyen Tien Dat\n" << "MSSV: 20194242\n";
     cout << setprecision(2) << fixed;
     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
     return 0;
 }

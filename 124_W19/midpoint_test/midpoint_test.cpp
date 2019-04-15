#include <iostream>
#include "Rational.h"

class Point {
public:
	double x;
	double y;
};

void bad_midpoint(double x1, double y1, double x2, double y2,
              double& x_mid, double& y_mid) {
	x_mid = (x1 + x2) / 2;
	y_mid = (y1 + y2) / 2;
}

Point midpoint(Point p1, Point p2) {
	Point result;
	result.x = (p1.x + p2.x) / 2;
	result.y = (p1.y + p2.y) / 2;
	return result;
}

std::ostream& operator<<(std::ostream& os, Point p) {
	os << '(';
	os << p.x;
	os << ',';
	os << p.y;
	os << ')';
	return os;
}

//int main() {
//	std::cout << "Please enter two points: ";
//	double x1, y1, x2, y2;
//	std::cin >> x1 >> y1 >> x2 >> y2;
//
//	double mid_x, mid_y;
//	bad_midpoint(x1, y1, x2, y2, mid_x, mid_y);
//
//	std::cout << "The midpoint is (" << mid_x << ", " << mid_y << ")\n";
//
//	std::cout << "---------------------------------\n";
//
//	Point point1, point2;
//	point1.x = x1;
//	point1.y = y1;
//	point2.x = x2;
//	point2.y = y2;
//
//	std::cout << "The midpoint between " << point1 << " and "
//		      << point2 << " is " << midpoint(point1, point2) << ".\n";
//}

int main() {
	Rational fract1(20, 26);

	std::cout << fract1 << '\n';
	std::cout << fract1.reduce() << '\n';

	Rational f1(1, 20), f2(3, 4);

	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n';
	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << '\n';

	Rational f3(1, 0);
	std::cout << f3 << '\n';

}
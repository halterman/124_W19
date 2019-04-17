#include <iostream>


class Rational {
	int numerator;
	int denominator;
public:
	//Rational();
	//~Rational();
	Rational(int n, int d);
	Rational reduce();
	int get_numerator();
	int get_denominator();
};

std::ostream& operator<<(std::ostream& os, Rational r);

Rational operator*(Rational r1, Rational r2);

Rational operator+(Rational r1, Rational r2);

#include <iostream>


class Rational {
	int numerator;
	int denominator;
public:
	//Rational();
	//~Rational();
	Rational(int n, int d);
	Rational reduce() const;
	int get_numerator() const;
	int get_denominator() const;
	void set_numerator(int n);
	void set_denominator(int d);
};

std::ostream& operator<<(std::ostream& os, Rational r);

Rational operator*(Rational r1, Rational r2);

Rational operator+(Rational r1, Rational r2);

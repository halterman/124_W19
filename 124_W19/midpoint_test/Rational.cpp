#include "Rational.h"


//Rational::Rational()
//{
//}
//
//
//Rational::~Rational()
//{
//}

int gcd(int m, int n) {
	if (n == 0)
		return m;
	else
		return gcd(n, m % n);
}

std::ostream& operator<<(std::ostream& os, Rational r) {
	os << r.get_numerator() << '/' << r.get_denominator();
	return os;
}

Rational operator*(Rational r1, Rational r2) {
	int num = r1.get_numerator() * r2.get_numerator(),
		den = r1.get_denominator() * r2.get_denominator();
	Rational result(num, den);
	return result.reduce();
}

Rational operator+(Rational r1, Rational r2) {
	Rational new_r1(r1.get_numerator() * r2.get_denominator(),
		            r1.get_denominator() * r2.get_denominator()),
		     new_r2(r2.get_numerator() * r1.get_denominator(),
			        r2.get_denominator() * r1.get_denominator());
	Rational result(new_r1.get_numerator() + new_r2.get_numerator(),
		            new_r1.get_denominator());
	return result.reduce();
}

Rational::Rational(int n, int d):
        numerator(n), denominator(d) {
	if (d == 0) {
		std::cout << "Attempt to create an illegal Rational object\n";
		exit(600);
	}
}

Rational Rational::reduce() {
	int factor = gcd(numerator, denominator);
	return Rational(numerator / factor, denominator / factor);
}

int Rational::get_numerator() {
	return numerator;
}
int Rational::get_denominator() {
	return denominator;
}

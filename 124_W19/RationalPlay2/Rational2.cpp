#include "Rational2.h"


//Rational::Rational()
//{
//}
//
//

int sn_source = 0;

Rational2::~Rational2() {
	std::cout << "Destroying rational #"
		      << serial_number << '\n';
}

int gcd(int m, int n) {
	if (n == 0)
		return m;
	else
		return gcd(n, m % n);
}

std::ostream& operator<<(std::ostream & os, Rational2 r) {
	os << r.get_numerator() << '/' << r.get_denominator();
	return os;
}

Rational2 operator*(Rational2 r1, Rational2 r2) {
	int num = r1.get_numerator() * r2.get_numerator(),
		den = r1.get_denominator() * r2.get_denominator();
	Rational2 result(num, den);
	return result.reduce();
}

Rational2 operator+(Rational2 r1, Rational2 r2) {
	Rational2 new_r1(r1.get_numerator() * r2.get_denominator(),
		r1.get_denominator() * r2.get_denominator()),
		new_r2(r2.get_numerator() * r1.get_denominator(),
			r2.get_denominator() * r1.get_denominator());
	Rational2 result(new_r1.get_numerator() + new_r2.get_numerator(),
		new_r1.get_denominator());
	return result.reduce();
}

Rational2::Rational2(int n, int d) :
	numerator(n), denominator(d),
    serial_number(sn_source++) {
	if (d == 0) {
		std::cout << "Attempt to create an illegal Rational object\n";
		exit(600);
	}
	std::cout << "Creating rational #" 
		      << serial_number << '\n';
}

Rational2::Rational2(const Rational2& other) :
	Rational2(other.numerator, other.denominator) {}

Rational2 Rational2::reduce() const {
	int factor = gcd(numerator, denominator);
	return Rational2(numerator / factor, denominator / factor);
}

int Rational2::get_numerator() const {
	return numerator;
}
int Rational2::get_denominator() const {
	return denominator;
}

void Rational2::set_numerator(int n) {
	numerator = n;
}
void Rational2::set_denominator(int d) {
	if (d == 0) {
		std::cout << "Attempt to set denominator to zero\n";
		exit(600);
	}
	else
		denominator = d;
}
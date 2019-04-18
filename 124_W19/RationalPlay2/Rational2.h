#include <iostream>


class Rational2 {
	int numerator;
	int denominator;
	int serial_number;
public:
	//Rational();
	~Rational2();
	Rational2(int n, int d);
	Rational2(const Rational2& other);
	Rational2 reduce() const;
	int get_numerator() const;
	int get_denominator() const;
	void set_numerator(int n);
	void set_denominator(int d);
};

std::ostream& operator<<(std::ostream& os, const Rational2& r);

Rational2 operator*(const Rational2& r1, const Rational2& r2);

Rational2 operator+(const Rational2& r1, const Rational2& r2);

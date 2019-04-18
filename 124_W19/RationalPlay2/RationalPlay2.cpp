// RationalPlay2.cpp
// Created 4/17/2019 2:50:02 PM

#include <iostream>
#include "Rational2.h"


Rational2 twice(const Rational2& fract) {
	return Rational2(fract.get_numerator() * 2,
		             fract.get_denominator());
}

int main() {
	Rational2 fract1(20, 26);
	std::cout << fract1 << '\n';
	std::cout << fract1.reduce() << '\n';
	Rational2 fract2(twice(fract1));
	std::cout << fract2 << '\n';
	std::cout << fract2.reduce() << '\n';
	twice(fract1);

	Rational2 f1(1, 2), f2(1, 4);
	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << '\n';
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n';
}


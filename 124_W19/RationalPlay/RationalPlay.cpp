// RationalPlay.cpp
// Created 4/15/2019 2:12:15 PM

#include <iostream>
#include "Rational.h"

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

// _01_16_floatingdivision.cpp
// Created 1/16/2019 2:16:02 PM

#include <iostream>

int main() {
	std::cout << "Please enter two floating-point numbers: ";
	double x, y;
	std::cin >> x >> y;
	std::cout << x << " + " << y << " = " << x + y << '\n';
	std::cout << x << " * " << y << " = " << x * y << '\n';
	std::cout << x << " / " << y << " = " << x / y << '\n';
}

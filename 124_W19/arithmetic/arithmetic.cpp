// arithmetic.cpp
// Created 1/14/2019 2:31:54 PM

#include <iostream>

int main() {
	std::cout << "Please enter two integers: ";
	int x, y;
	std::cin >> x >> y;
	std::cout << x << " + " << y << " = " << x + y << '\n';
	std::cout << x << " * " << y << " = " << x * y << '\n';
	std::cout << x << " / " << y << " = " << x / y << '\n';
	std::cout << x << " % " << y << " = " << x % y << '\n';
}

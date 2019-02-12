// my_square_root_1.cpp
// Created 2/11/2019 2:09:16 PM

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	while (true) {
		std::cout << "Please enter a nonnegative number: ";
		double input, root = 1;
		std::cin >> input;

		if (input >= 0.0) {
			while (root*root - input > 0.000000001 || root * root - input < -0.000000001) {
				root = (root + input / root) / 2;
			}
			std::cout << "The square root of " << input << " is "
				<< std::setprecision(15) << std::fixed << root << '\n';
			std::cout << "Library function: " << sqrt(input) << '\n';
		}
		else
			std::cout << "Cannot compute the square root of a negative number\n";
	}
}

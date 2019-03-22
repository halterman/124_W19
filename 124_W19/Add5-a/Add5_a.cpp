// Add5_a.cpp
// Created 3/20/2019 1:28:44 PM

#include <iostream>

int main() {
	double n1, n2, n3, n4, n5;
	std::cout << "Please enter five numbers: ";
	// Allow the user to enter in the five values.
	std::cin >> n1 >> n2 >> n3 >> n4 >> n5;
	std::cout << "The sum of " << n1 << ", " << n2 << ", "
		      << n3 << ", " << n4 << ", " << n5 << " is "
		      << n1 + n2 + n3 + n4 + n5 << '\n';
}
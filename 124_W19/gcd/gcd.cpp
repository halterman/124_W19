// gcd.cpp
// Created 2/20/2019 2:27:28 PM

#include <iostream>

// Computes and returns the greatest common divisor of
// nonnegative integers m and n.
int gcd(int m, int n) {
	int smaller = (m < n) ? m : n;
	int factor = 1;
	for (int i = 2; i <= smaller; i++) {
		if (m % i == 0 && n % i == 0)
			factor = i;
	}
	return factor;
}

void reduce(int& num, int& den) {
	int gcf = gcd(num, den);
	num /= gcf;
	den /= gcf;
}

int main() {
	//int num1, num2;
	//std::cout << "Please enter two integers: ";
	//std::cin >> num1 >> num2;
	//int answer = gcd(num1, num2);
	//std::cout << "GCD(" << num1 << "," << num2 << ") = "
	//	      << answer << '\n';
	while (true) {
		std::cout << "Please enter a fraction: ";
		int numerator, denominator;
		char slash;
		std::cin >> numerator >> slash >> denominator;
		std::cout << numerator << '/' << denominator << " reduces to ";
		reduce(numerator, denominator);
		std::cout << numerator << '/' << denominator << ".\n";
	}


}

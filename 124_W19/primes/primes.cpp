// primes.cpp
// Created 1/30/2019 2:33:32 PM

#include <iostream>

int main() {
	int upper_limit;
	std::cout << "Please enter upper limit: ";
	std::cin >> upper_limit;
	int n = 2;
	// Consider all the possible prime numbers from 2 to upper_limit
	while (n <= upper_limit) {
		// Count the number of factors of n
		int factor_count = 0, potential_factor = 1;
		while (potential_factor <= n) {
			if (n % potential_factor == 0) {
				factor_count++;
			}
			potential_factor++;
		}
		if (factor_count == 2)
			std::cout << n << ' ';
		n++;
	}
	std::cout << '\n';
}

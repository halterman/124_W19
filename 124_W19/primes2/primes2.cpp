// primes2.cpp
// Created 1/30/2019 3:02:14 PM

#include <iostream>

int main() {
	int upper_limit;
	std::cout << "Please enter upper limit: ";
	std::cin >> upper_limit;
	if (upper_limit >= 2) {
		std::cout << 2 << ' ';
		int n = 3;
		// Consider all the possible prime numbers from 2 to upper_limit
		while (n <= upper_limit) {
			// Count the number of factors of n
			int factor_count = 0, potential_factor = 2;
			while (potential_factor*potential_factor <= n) {
				if (n % potential_factor == 0) {
					factor_count++;
				}
				potential_factor++;
				if (factor_count > 0)
					break;
			}
			if (factor_count == 0)
				std::cout << n << ' ';
			n += 2;
		}
		std::cout << '\n';
	}
}
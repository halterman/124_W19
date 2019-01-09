#include <iostream>

int main() {
	int x;

	x = 5;
	std::cout << "x is " << x << '\n';

	std::cout << "Please enter an integer value: ";
	std::cin >> x;

	std::cout << "x is " << x << "\n";
}
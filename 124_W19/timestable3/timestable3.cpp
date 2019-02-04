// timestable3.cpp
// Created 2/4/2019 3:06:37 PM

#include <iostream>
#include <iomanip>

int main() {
	std::cout << "Please enter the size of the table: ";
	int size;
	std::cin >> size;

	for (int row = 1; row <= size; row++) {
		for (int column = 1; column <= size; column++)
			std::cout << std::setw(4) << row * column;
		std::cout << '\n';
	}

}

// timestable5.cpp
// Created 2/6/2019 2:43:47 PM

#include <iostream>
#include <iomanip>

int main() {
	std::cout << "Please enter the size of the table: ";
	int size;
	std::cin >> size;

	// Print the numbers that label the columns
	std::cout << "    ";
	for (int column = 1; column <= size; column++) {
		std::cout << std::setw(4) << column;
	}
	std::cout << '\n';
	// Print the line that separates the column labels from the table itself
	std::cout << "   +";
	for (int column = 1; column <= size; column++) {
		std::cout << "----";
	}
	std::cout << '\n';

	for (int row = 1; row <= size; row++) {
		std::cout << std::setw(2) << row << " |";
		for (int column = 1; column <= size; column++)
			std::cout << std::setw(4) << row * column;
		std::cout << '\n';
	}
}

